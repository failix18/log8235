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
#include <Runtime/NavigationSystem/Public/NavLinkComponent.h>

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
    physicsHelper.SphereOverlap(pawnLocation, 10000000, sphereHitResult, false);

    FVector destination = FVector::ZeroVector;
    if (sphereHitResult.Num() > 0) {
        AActor* closestCollectible = sphereHitResult[0].GetActor();
        bool hasDetectedCollectible = false;
        float minDistanceToCollectible = 99999999;
        for (int i = 0; i < sphereHitResult.Num(); i++)
        {
            AActor* foundActor = sphereHitResult[i].GetActor();
            if (foundActor->GetName().Contains("BP_SDTCollectible"))
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
    //TArray<AActor*> navLinks;
    //for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    //{
    //    AActor* act = Cast<AActor>(*ActorItr);
    //    /*navLinks.Add(Cast<AActor>(*ActorItr));*/
    //    if ((act)->GetName().Contains("NavLink")) {
    //        /*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, act->GetName());*/
    //        //UNavLinkComponent* NavLink = Cast<UNavLinkComponent>(act);
    //        int test = 0;
    //        /*FNavigationLink Link = NavLink->Links[0];
    //        DrawDebugLine(
    //            GetWorld(),
    //            Link.Left,
    //            Link.Right,
    //            FColor(0, 0, 0),
    //            false, -1, 0,
    //            5.f
    //        );*/
    //        //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Link.Left.ToString());
    //    }
    //}
    
    for(FNavPathPoint& point : path->GetPath()->GetPathPoints())
        PathToFollow.Push(point.Location);

    USDTPathFollowingComponent* pathFollowingComponent = static_cast<USDTPathFollowingComponent*>(GetPathFollowingComponent());
    pathFollowingComponent->SetPath(path->GetPath(), GetPawn());

    ASDTAIController::OnMoveToTarget();
}

void ASDTAIController::OnMoveToTarget()
{
    m_ReachedTarget = false;
}

void ASDTAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);

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
            FColor(0, 0, 0),
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