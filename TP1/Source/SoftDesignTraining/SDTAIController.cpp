// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "PhysicsHelpers.h"
#include "SoftDesignTraining.h"
#include <SoftDesignTraining/SDTUtils.h>

void ASDTAIController::Tick(float deltaTime)
{
    //ASDTAIController::MoveForward(1.0f);
    APawn* const pawn = GetPawn();
    UWorld* world = GetWorld();
    PhysicsHelpers physicsHelper(world);

    if (pawn)
    {
        FVector pawnLocation = pawn->GetActorLocation();
        FRotator orientation = pawn->GetActorRotation();
        ASDTAIController::FindDirection(orientation, pawnLocation, world);
        if (ASDTAIController::WallDetected(orientation, pawnLocation, world))
        {
            orientation = orientation.Add(0.0f, preferedDirection * 10.0f, 0.0f);
            pawn->SetActorRotation(orientation);
        }
        else
        {
            // Check spherical area around the pawn for the player character
            TArray<FOverlapResult> results = SphereDetection(pawn, physicsHelper);
            for (int i = 0; i < results.Num(); i++)
            {
                AActor* foundActor = results[i].GetActor();
                if (foundActor->GetName() == "BP_SDTMainCharacter_C_0")
                {
                    // Player found
                    FVector fleeVector = pawnLocation - foundActor->GetActorLocation();

                    // Flee if won't flee into a wall
                    if (!ASDTAIController::WallDetected(fleeVector.Rotation(), pawnLocation, world))
                    {
                        pawn->SetActorRotation(fleeVector.Rotation());
                    }
                }
            }
        }

        if (ASDTAIController::PickupDetected(orientation, pawnLocation, world, physicsHelper)) {
        }

        ASDTAIController::PawnMovement(orientation, pawn, deltaTime);
    }
}

// Return all actors within its radius
TArray<FOverlapResult> ASDTAIController::SphereDetection(APawn const* pawn, PhysicsHelpers& physicHelper) const
{
    TArray<FOverlapResult> outResults;
    physicHelper.SphereOverlap(pawn->GetActorLocation(), visionDistance, outResults, true);

    return outResults;
}

// Find prefered (no obstacle) direction (left or right) to turn toward
void ASDTAIController::FindDirection(FRotator orientation, FVector pawnLocation, UWorld* world)
{
    FVector leftTargetLocation = pawnLocation + orientation.Add(0.0f, -45.0f, 0.0f).Vector().GetSafeNormal() * 300.0f;
    bool leftHit = SDTUtils::Raycast(world, pawnLocation, leftTargetLocation);

    FVector rightTargetLocation = pawnLocation + orientation.Add(0.0f, 45.0f, 0.0f).Vector().GetSafeNormal() * 300.0f;
    bool rightHit = SDTUtils::Raycast(world, pawnLocation, rightTargetLocation);

    if (leftHit)
    {
        if (!rightHit)
        {
            preferedDirection = 1.0f;
        }
        else
        {
            RefineDirection(orientation, pawnLocation, world);
        }
    }
    else if (rightHit)
    {
        if (!leftHit)
        {
            preferedDirection = -1.0f;
        }
        else
        {
            RefineDirection(orientation, pawnLocation, world);
        }
    }
}

void ASDTAIController::RefineDirection(FRotator orientation, FVector pawnLocation, UWorld* world)
{
    FVector leftTargetLocation = pawnLocation + orientation.Add(0.0f, -90.0f, 0.0f).Vector().GetSafeNormal() * 300.0f;
    bool leftHit = SDTUtils::Raycast(world, pawnLocation, leftTargetLocation);

    FVector rightTargetLocation = pawnLocation + orientation.Add(0.0f, 90.0f, 0.0f).Vector().GetSafeNormal() * 300.0f;
    bool rightHit = SDTUtils::Raycast(world, pawnLocation, rightTargetLocation);

    if (leftHit && !rightHit)
    {
        preferedDirection = 1.0f;
    }
    else if (rightHit && !leftHit)
    {
        preferedDirection = -1.0f;
    }
}

bool ASDTAIController::WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world)
{
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * hitDistance;
    return SDTUtils::Raycast(world, pawnLocation, targetLocation);
}


bool ASDTAIController::PickupDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper)
{
    TArray<struct FHitResult> hitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * visionDistance;
    physicsHelper.SphereCast(pawnLocation, targetLocation, radiusDetection, hitResult, drawDebug);

    return true;

}


void ASDTAIController::PawnMovement(FRotator orientation, APawn* pawn, float deltaTime)
{
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    pawn->AddMovementInput(speed * orientation.Vector().GetSafeNormal());
}