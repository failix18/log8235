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

    if (sphereHitResult.Num() > 0) {
        AActor* closestCollectible = sphereHitResult[0].GetActor();
        bool hasDetectedCollectible = false;
        float minDistanceToCollectible = 99999999;
        for (int i = 0; i < sphereHitResult.Num(); i++)
        {
            AActor* foundActor = sphereHitResult[i].GetActor();
            if (foundActor->GetName().Contains("BP_SDTCollectible"))
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
    // UNavigationPath* path = UNavigationSystemV1::FindPathToLocationSynchronously(this, GetActorLocation(), destination);
    // if(!path || !path->GetPath().IsValid() || path->GetPath()->IsPartial() || path->GetPath()->GetPathPoints().Num() == 0)
    // {
    //     GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, TEXT("INVALID DESTINATION USED"));
    //     return;
    // }

    // PathToFollow.Empty();

    // for(FNavPathPoint& point : path->GetPath()->GetPathPoints())
    //     PathToFollow.Push(point.Location);

    // CurrentDestinationIndex = 0;
    //TArray<AActor*> actors = world->GetCurrentLevel()->Actors;
    /*if (actors.Num() > 0) {
        AActor* closestCollectible = actors[0];
        bool hasDetectedCollectible = false;
        float minDistanceToCollectible = 99999999;
        for (int i = 0; i < actors.Num(); ++i) {
            if (actors[i]->GetName().Contains("BP_SDTCollectible")) {
                hasDetectedCollectible = false;
                FVector position = actors[i]->GetActorLocation();
                FVector pawnToCollectible = position - pawnLocation;
                float x = pawnLocation.X;
                float xs = pawnLocation.X;
                double distance = sqrt(pow(pawnToCollectible.X, 2) + pow(pawnToCollectible.Y, 2));
                if (distance < minDistanceToCollectible) {
                    minDistanceToCollectible = distance;
                    closestCollectible = actors[i];
                }
            }
        }
    }*/
    
//     if(PathToFollow.Num() > 0)
//     {
//         FVector velocity = FVector::ZeroVector;

//         if(CurrentDestinationIndex > -1 && CurrentDestinationIndex < PathToFollow.Num())
//         {
//             FVector destination = ComputeDestination(pawnLocation);

// #ifdef PATH_FOLLOW_DEBUG
//             {
//                 DrawDebugSphere(
//                     GetWorld(),
//                     destination,
//                     20.f, 20,
//                     FColor(255, 0, 0),
//                     false, -1, 0
//                 );
//             }
// #endif //PATH_FOLLOW_DEBUG

//             UpdateDirection(deltaTime, destination - pawnLocation);
//             velocity = ComputeVelocity(deltaTime, destination);
//         }
//         else
//         {
//             velocity = ComputeVelocity(-deltaTime, pawnLocation + Direction);

//             if(velocity.SizeSquared() < 0.1f)
//             {
//                 CurrentSpeed = 0.f;
//                 CurrentDestinationIndex = -1.f;
//             }
//         }

//         ApplyVelocity(deltaTime, velocity);
//     }
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
    //Show current navigation path DrawDebugLine and DrawDebugSphere
    pawnLocation.Z += 50;

    DrawDebugLine(
        GetWorld(),
        pawnLocation,
        pawnLocation + Direction * 100.f,
        FColor(255, 0, 0),
        false, -1, 0,
        12.333
    );

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


void ASDTAIController::UseShortcuts_Behavior(FVector2D& destination2D, FVector& destination, FVector pawnLocation)
{
    if (CurrentDestinationIndex != PathToFollow.Num() - 1)
    {
        TArray<FVector> sampleShortcutPoints;

        sampleShortcutPoints.Empty();
        sampleShortcutPoints.Reserve(SHORTCUT_SAMPLE_NUM);
        FVector startNextPath = PathToFollow[CurrentDestinationIndex];
        FVector endNextPath = PathToFollow[CurrentDestinationIndex + 1];

        FVector displacementSamples = (endNextPath - startNextPath) / SHORTCUT_SAMPLE_NUM;

        for (int i = 0; i < SHORTCUT_SAMPLE_NUM; i++)
        {
            FVector sample = startNextPath + ((i + 1) * displacementSamples);
            sampleShortcutPoints.Push(sample);
#ifdef PATH_FOLLOW_DEBUG
            {
                DrawDebugSphere(
                    GetWorld(),
                    sample,
                    10.f, 20,
                    FColor::Emerald,
                    false, -1, 0
                );
            }
#endif //PATH_FOLLOW_DEBUG
        }

        FVector originBB = FVector::ZeroVector;
        FVector extentsBB;
        GetPawn()->GetActorBounds(true, originBB, extentsBB);
        extentsBB.Z = 0.f;

        for (int i = SHORTCUT_SAMPLE_NUM - 1; i >= 0; i--)
        {
            FVector start = pawnLocation;
            start.Z = originBB.Z;
            FVector end = sampleShortcutPoints[i];
            end.Z = originBB.Z;

            FVector sideVectorLeft = FVector::CrossProduct((end - start), GetPawn()->GetActorUpVector());
            sideVectorLeft.Normalize();
            sideVectorLeft *= extentsBB.Size();
            FVector sideVectorRight = -sideVectorLeft;

            FHitResult HitOut;
            // EXERCICE 3 : TESTS RAYCASTS
            if (!SDTUtils::Raycast(GetWorld(),
                start + sideVectorLeft,	//start
                end + sideVectorLeft //end
            )
                &&
                !SDTUtils::Raycast(GetWorld(),
                    start + sideVectorRight,	//start
                    end + sideVectorRight //end
                )
                )
            {
                destination = sampleShortcutPoints[i];
                destination2D = FVector2D(sampleShortcutPoints[i]);
                if (destination.Equals(PathToFollow[CurrentDestinationIndex + 1]))
                    CurrentDestinationIndex++;
                break;
            }
        }
    }
}

void ASDTAIController::UseIntermediaryDestination_Behavior(FVector2D position2D, FVector2D destination2D, FVector& destination)
{
    FVector lineStart = PathToFollow[CurrentDestinationIndex - 1];
    FVector lineEnd = PathToFollow[CurrentDestinationIndex];
    FVector lineDirection = lineEnd - lineStart;
    lineDirection.Normalize();

    FVector projectedPosition = FMath::ClosestPointOnLine(lineStart, lineEnd, GetPawn()->GetActorLocation());

    if ((GetPawn()->GetActorLocation() - lineEnd).Size() > 1.f)
        destination = projectedPosition + ((lineEnd - projectedPosition) / 2);
}

float ASDTAIController::ComputeTargetSpeedForTurn()
{
    if (CurrentDestinationIndex == PathToFollow.Num() - 1)
        return -1.f;

    FVector nextDirection = PathToFollow[CurrentDestinationIndex + 1] - PathToFollow[CurrentDestinationIndex];
    nextDirection.Normalize();

    float speedFactor = 1.f;

    float cosAngleDir = FVector::DotProduct(Direction, nextDirection);
    speedFactor = (cosAngleDir + 1) / 2;

    return MaxSpeed * speedFactor;
}

float ASDTAIController::UseSlowDownForTurns_Behavior(FVector destination, float deltaTime)
{
    // On calcule une fois la vitesse auquelle on veut descendre arriv� au prochain noeud
    if (!IsTurning && SlowDownTargetSpeed == -1.f)
    {
        SlowDownTargetSpeed = ComputeTargetSpeedForTurn();
        FVector destToPos = GetPawn()->GetActorLocation() - destination;
        destToPos.Normalize();
        SlowDownStartPos = destination + destToPos * 200.f;
        IndexAfterSlowDown = CurrentDestinationIndex + 1;
    }

    if (!IsTurning)
        return FMath::Lerp(MaxSpeed, SlowDownTargetSpeed, 1 - ((destination - GetPawn()->GetActorLocation()).Size() / (destination - SlowDownStartPos).Size()));
    else
        return SlowDownTargetSpeed;
}

FVector ASDTAIController::ComputeDestination(FVector pawnLocation)
{
    FVector2D position2D(pawnLocation);
    FVector destination(PathToFollow[CurrentDestinationIndex]);
    FVector2D destination2D(destination);

    UseShortcuts_Behavior(destination2D, destination, pawnLocation);

    if(position2D.Equals(destination2D, 10.f))
    {
        CurrentDestinationIndex++;

        if(CurrentDestinationIndex == PathToFollow.Num())
        {
            CurrentDestinationIndex = -1;
            destination = FVector(position2D, 0.f) + Direction;
        }
        else
        {
            destination = PathToFollow[CurrentDestinationIndex];
        }
    }

    if(!position2D.Equals(destination2D, 20.f) && CurrentDestinationIndex > 0)
        UseIntermediaryDestination_Behavior(position2D, destination2D, destination);

    return destination;
}


void ASDTAIController::UpdateDirection(float DeltaTime, FVector directionGoal)
{
    directionGoal.Z = 0.f;

    if(!FMath::IsNearlyEqual(directionGoal.SizeSquared(), 1))
        directionGoal.Normalize();

    if(Direction.Equals(directionGoal, 0.01f))
    {
        Direction = directionGoal;
        IsTurning = false;
        if(CurrentDestinationIndex == IndexAfterSlowDown)
            SlowDownTargetSpeed = -1.f;
        return;
    }

    IsTurning = true;

    FRotator currentRotation = Direction.ToOrientationRotator();
    FRotator goalRotation = directionGoal.ToOrientationRotator();

    FRotator deltaRotation = goalRotation - currentRotation;

    if(deltaRotation.Yaw > 180.f)
        deltaRotation.Yaw -= 360.f;

    if(deltaRotation.Yaw < -180.f)
        deltaRotation.Yaw += 360.f;

    float RotationThisFrame = RotationRate * DeltaTime;

    deltaRotation.Yaw = FMath::Clamp(deltaRotation.Yaw, -RotationThisFrame, RotationThisFrame);

    Direction = deltaRotation.RotateVector(Direction);
}

FVector ASDTAIController::ComputeVelocity(float DeltaTime, FVector destination)
{
    FVector velocity = FVector::ZeroVector;
    float speed = MaxSpeed;

    if ((IsTurning || (destination - GetPawn()->GetActorLocation()).Size() < 200.f) && CurrentDestinationIndex != -1 && CurrentDestinationIndex != PathToFollow.Num() - 1)
        speed = UseSlowDownForTurns_Behavior(destination, DeltaTime);

    CurrentSpeed = FMath::Clamp(CurrentSpeed + (Acceleration * DeltaTime), 0.f, speed);
    velocity = Direction * CurrentSpeed;

    return velocity;
}

void ASDTAIController::ApplyVelocity(float DeltaTime, FVector velocity)
{
    if(!velocity.IsNearlyZero())
    {
        FVector position = GetPawn()->GetActorLocation();

        FVector destination = position + velocity * DeltaTime;

        GetPawn()->SetActorLocation(destination);
    }
}