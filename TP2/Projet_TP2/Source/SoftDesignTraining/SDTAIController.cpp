// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include "SDTCollectible.h"
#include "SDTFleeLocation.h"
#include "SDTPathFollowingComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
//#include "UnrealMathUtility.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include "cmath"
#include "PhysicsHelpers.h"
#include <Runtime/NavigationSystem/Public/NavigationSystem.h>
#include <SoftDesignTraining/SoftDesignTrainingMainCharacter.h>

#define PATH_FOLLOW_DEBUG
#define SHORTCUT_SAMPLE_NUM 8

ASDTAIController::ASDTAIController(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<USDTPathFollowingComponent>(TEXT("PathFollowingComponent")))
{
}

void ASDTAIController::GoToBestTarget(float deltaTime, UWorld* world, FVector pawnLocation)
{
    //Move to target depending on current behavior
    TArray<FOverlapResult> sphereHitResult;
    pawnLocation = GetPawn()->GetActorLocation();
    PhysicsHelpers physicsHelper(GetWorld());
    physicsHelper.SphereOverlap(pawnLocation, 1000000, sphereHitResult, false);

    FVector destination = FVector::ZeroVector;
    if (sphereHitResult.Num() > 0) 
    {
        AActor* closestCollectible = sphereHitResult[0].GetActor();
        bool hasDetectedCollectible = false;
        float minDistanceToCollectible = 99999999;
        float fleeVectorImperfection = 99999999;
        FVector playerLocation = FVector::ZeroVector;

        for (int i = 0; i < sphereHitResult.Num(); i++)
        {
            AActor* foundActor = sphereHitResult[i].GetActor();
            if (foundActor->GetName().Contains("BP_SDTCollectible") && behavior == 0)
            {
                if (static_cast<ASDTCollectible*>(sphereHitResult[i].GetActor())->GetStaticMeshComponent()->GetVisibleFlag())
                {
                    hasDetectedCollectible = false;
                    FVector position = foundActor->GetActorLocation();
                    FVector pawnToCollectible = position - pawnLocation;
                    float x = pawnLocation.X;
                    float xs = pawnLocation.X;
                    double distance = sqrt(pow(pawnToCollectible.X, 2) + pow(pawnToCollectible.Y, 2));
                    if (distance < minDistanceToCollectible) {
                        minDistanceToCollectible = distance;
                        closestCollectible = foundActor;
                    }
                }
            }
            else if (foundActor->GetName() == "BP_SDTMainCharacter_C_0")
            {
                playerLocation = foundActor->GetActorLocation();

                // Check has line of sight
                TArray<struct FHitResult> rayCastHitResult;
                physicsHelper.CastRay(pawnLocation, playerLocation, rayCastHitResult, false);
                bool wallBlocking = false;
                for (int j = 0; j < rayCastHitResult.Num(); ++j) {
                    if (rayCastHitResult[j].GetActor()->GetName().Contains("Wall")) {
                        wallBlocking = true;
                    }
                }
                if (!wallBlocking)
                {
                    // Chase or flee depending on player's state (which can change mid chase/flee) if has line of sight
                    if (static_cast<ASoftDesignTrainingMainCharacter*>(foundActor)->IsPoweredUp())
                    {
                        behavior = 2;

                        // Choose the fleeLocation in the direction most opposite from player.
                        FVector perfectFleeVector = (pawnLocation - playerLocation).GetSafeNormal();

                        // Getting all actors here since the fleeLocations don't show up in the sphereCast for some reasons. ¯\_(ツ)_/¯
                        TArray<AActor*> fleeLocations;
                        for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
                        {
                            if ((*ActorItr)->GetName().Contains("FleeLocation"))
                            {
                                // Compare direction of the fleeLocation with ideal fleeing direction and pick it if it's better than previous best.
                                FVector fleeVector = ((*ActorItr)->GetActorLocation() - pawnLocation).GetSafeNormal();
                                float imperfection = FVector::DotProduct(perfectFleeVector, fleeVector);

                                if (imperfection < fleeVectorImperfection)
                                {
                                    fleeVectorImperfection = imperfection;
                                    closestCollectible = (*ActorItr);
                                }
                            }
                        }
                    }
                    else {
                        behavior = 1;
                        closestCollectible = foundActor;
                    }
                }
                else
                {
                    behavior = 0;
                }
            }
        }
        destination = closestCollectible->GetActorLocation();
    }
    UNavigationPath* path = UNavigationSystemV1::FindPathToLocationSynchronously(this, GetPawn()->GetActorLocation(), destination);
    if(!path || !path->GetPath().IsValid() || path->GetPath()->IsPartial() || path->GetPath()->GetPathPoints().Num() == 0)
    {
        GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, TEXT("INVALID DESTINATION USED"));
        return;
    }

    PathToFollow.Empty();

    for(FNavPathPoint& point : path->GetPath()->GetPathPoints())
        PathToFollow.Push(point.Location);

    USDTPathFollowingComponent* pathFollowingComponent = static_cast<USDTPathFollowingComponent*>(GetPathFollowingComponent());
    pathFollowingComponent->SetPath(path->GetPath());

    ASDTAIController::OnMoveToTarget();
}

void ASDTAIController::OnMoveToTarget()
{
    m_ReachedTarget = false;
}

void ASDTAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);
    behavior = 0;
    m_ReachedTarget = true;
}

void ASDTAIController::ShowNavigationPath(FVector pawnLocation)
{
    USDTPathFollowingComponent* pathFollowingComponent = static_cast<USDTPathFollowingComponent*>(GetPathFollowingComponent());
    if (pathFollowingComponent->IsCollectibleReached())
    {
        m_ReachedTarget = true;
    }
    //Show current navigation path DrawDebugLine and DrawDebugSphere
    pawnLocation.Z += 50;

    for(int i = 0; i < PathToFollow.Num() - 1; i++)
        DrawDebugLine(
            GetWorld(),
            PathToFollow[i],
            PathToFollow[i + 1],
            FColor(0, 0, 255),
            false, -1, 0,
            5.f
        );
}

void ASDTAIController::ChooseBehavior(float deltaTime)
{
    UpdatePlayerInteraction(deltaTime);
}

void ASDTAIController::UpdatePlayerInteraction(float deltaTime)
{
    PhysicsHelpers physicsHelper(GetWorld());

    //finish jump before updating AI state
    if (AtJumpSegment)
        return;

    APawn* selfPawn = GetPawn();
    if (!selfPawn)
        return;

    ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (!playerCharacter)
        return;

    FVector detectionStartLocation = selfPawn->GetActorLocation() + selfPawn->GetActorForwardVector() * m_DetectionCapsuleForwardStartingOffset;
    FVector detectionEndLocation = detectionStartLocation + selfPawn->GetActorForwardVector() * m_DetectionCapsuleHalfLength * 2;

    TArray<TEnumAsByte<EObjectTypeQuery>> detectionTraceObjectTypes;
    detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_COLLECTIBLE));
    detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_PLAYER));

    TArray<FHitResult> allDetectionHits;
    GetWorld()->SweepMultiByObjectType(allDetectionHits, detectionStartLocation, detectionEndLocation, FQuat::Identity, detectionTraceObjectTypes, FCollisionShape::MakeSphere(m_DetectionCapsuleRadius));

    FHitResult detectionHit;
    GetHightestPriorityDetectionHit(allDetectionHits, detectionHit);

    //Set behavior based on hit


    // Check if has line of sight on player
    TArray<struct FHitResult> rayCastHitResult;
    physicsHelper.CastRay(selfPawn->GetActorLocation(), playerCharacter->GetActorLocation(), rayCastHitResult, false);
    bool wallBlocking = false;
    for (int j = 0; j < rayCastHitResult.Num(); ++j) {
        if (rayCastHitResult[j].GetActor()->GetName().Contains("Wall")) {
            wallBlocking = true;
        }
    }

    if (!wallBlocking) 
    {
        // Don't wait to finish path when a player is sighted since the path needs to be updated live with player's actions.
        AIStateInterrupted();
    }

    DrawDebugCapsule(GetWorld(), detectionStartLocation + m_DetectionCapsuleHalfLength * selfPawn->GetActorForwardVector(), m_DetectionCapsuleHalfLength, m_DetectionCapsuleRadius, selfPawn->GetActorQuat() * selfPawn->GetActorUpVector().ToOrientationQuat(), FColor::Blue);
}

void ASDTAIController::GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit)
{
    for (const FHitResult& hit : hits)
    {
        if (UPrimitiveComponent* component = hit.GetComponent())
        {
            if (component->GetCollisionObjectType() == COLLISION_PLAYER)
            {
                //we can't get more important than the player
                outDetectionHit = hit;
                return;
            }
            else if (component->GetCollisionObjectType() == COLLISION_COLLECTIBLE)
            {
                outDetectionHit = hit;
            }
        }
    }
}

void ASDTAIController::AIStateInterrupted()
{
    StopMovement();
    m_ReachedTarget = true;
}

