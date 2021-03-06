// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "PhysicsHelpers.h"
#include "SoftDesignTraining.h"
#include "DrawDebugHelpers.h"
#include <SoftDesignTraining/SDTUtils.h>
#include <SoftDesignTraining/SDTCollectible.h>
#include <SoftDesignTraining/SoftDesignTrainingMainCharacter.h>


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

        if (ASDTAIController::PlayerChasing(world, pawnLocation, physicsHelper, pawn))
        {
            acc = FVector(accX, accY, 0.0f);
        }
        else if (ASDTAIController::DeathTrapDetected(orientation, pawnLocation, world, physicsHelper, pawn))
        {
            acc = FVector(accX, accY, 0.0f);
        } 
        else if (ASDTAIController::PickupDetected(orientation, pawnLocation, world, physicsHelper, pawn))
        {
            acc = FVector(accX, accY, 0.0f);
        }
        else if (ASDTAIController::WallDetected(orientation, pawnLocation, world, physicsHelper))
        {
            orientation = orientation.Add(0.0f, preferedDirection * 10.0f, 0.0f);
            pawn->SetActorRotation(orientation);
            // Slowing down the AI to 2 m/s when a wall is detected
            acc = speed > 200.0f ? FVector(0.0f, -2.5f, 0.0f) : FVector(0.0f, 0.0f, 0.0f);
        }

        ASDTAIController::PawnMovement(orientation, pawn, deltaTime);
    }
}

// Return all actors within its radius
TArray<FOverlapResult> ASDTAIController::SphereDetection(APawn const* pawn, PhysicsHelpers& physicHelper) const
{
    TArray<FOverlapResult> outResults;
    physicHelper.SphereOverlap(pawn->GetActorLocation(), visionDistance, outResults, drawDebug);

    return outResults;
}

// Find prefered (no obstacle) direction (left or right) to turn toward
void ASDTAIController::FindDirection(FRotator orientation, FVector pawnLocation, UWorld* world)
{
    FVector leftTargetLocation = pawnLocation + orientation.Add(0.0f, -90.0f, 0.0f).Vector().GetSafeNormal() * 400.0f;
    bool leftHit = SDTUtils::Raycast(world, pawnLocation, leftTargetLocation);

    FVector rightTargetLocation = pawnLocation + orientation.Add(0.0f, 90.0f, 0.0f).Vector().GetSafeNormal() * 400.0f;
    bool rightHit = SDTUtils::Raycast(world, pawnLocation, rightTargetLocation);

    if (leftHit)
    {
        if (!rightHit)
        {
            preferedDirection = 1.0f;
        }
    }
    else if (rightHit)
    {
        if (!leftHit)
        {
            preferedDirection = -1.0f;
        }
    }
}

// Detects if there is a wall in front of the pawn
bool ASDTAIController::WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper)
{
    TArray<struct FHitResult> rayCastHitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * hitDistance;
    physicsHelper.CastRay(pawnLocation, targetLocation, rayCastHitResult, drawDebug);

    for (int i = 0; i < rayCastHitResult.Num(); ++i) {
        if (!rayCastHitResult[i].GetActor()->GetName().Contains("BP_SDTCollectible")) {
            return true;
        }
    }
    return false;
}

// Detects if there is a pickup in front of the pawn
bool ASDTAIController::PickupDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn)
{
    TArray<struct FHitResult> sphereHitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * visionDistance;
    FVector startLocation = pawnLocation + orientation.Vector().GetSafeNormal() * radiusDetection;
    physicsHelper.SphereCast(startLocation, targetLocation, radiusDetection, sphereHitResult, drawDebug);
    
    TArray<FVector> pickupLocations;
    for (int i = 0; i < sphereHitResult.Num(); ++i) 
    {
        if (sphereHitResult[i].GetActor()->GetName().Contains("BP_SDTCollectible"))
        {
            if (static_cast<ASDTCollectible*>(sphereHitResult[i].GetActor())->GetStaticMeshComponent()->GetVisibleFlag())
            {
                pickupLocations.Add(sphereHitResult[i].ImpactPoint);
            }
        }
    }

    for (int i = 0; i < pickupLocations.Num(); ++i) 
    {
        FVector pawnToPickup = pickupLocations[i] - pawnLocation;
        TArray<struct FHitResult> rayCastHitResult;
        physicsHelper.CastRay(pawnLocation, pickupLocations[i], rayCastHitResult, drawDebug);
        bool wallBlocking = false;
        for (int j = 0; j < rayCastHitResult.Num(); ++j) {
            if (!rayCastHitResult[j].GetActor()->GetName().Contains("BP_SDTCollectible")) {
                wallBlocking = true;
            }
        }
        if (!wallBlocking) 
        {
            FRotator newDirection = FRotator(0.0f, pawnToPickup.ToOrientationRotator().Yaw, 0.0f);
            pawn->SetActorRotation(newDirection);
            return true;
        }
    }
    return false;
}

// Detects if there is a death trap in front of the pawn
bool ASDTAIController::DeathTrapDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn)
{
    TArray<struct FHitResult> sphereHitResult;
    FVector targetLocation = FVector(pawnLocation.X, pawnLocation.Y, 0.0f) + orientation.Vector().GetSafeNormal() * 1000.0f;
    FVector startLocation = FVector(pawnLocation.X, pawnLocation.Y, 0.0f);
    physicsHelper.SphereCast(startLocation, targetLocation, 1000.0f, sphereHitResult, false);

    for (int i = 0; i < sphereHitResult.Num(); ++i) {
        if (sphereHitResult[i].GetActor()->GetName().Contains("BP_DeathFloor")){
            FVector pawnToTrap = sphereHitResult[i].ImpactPoint - pawnLocation;
            FRotator newDirection = FRotator(0.0f, pawnToTrap.ToOrientationRotator().Yaw, 0.0f).Add(0.0f, 180.0f, 0.0f);
            pawn->SetActorRotation(newDirection);
            return true;
        }
    }
    return false;
}

// Sets the speed of the pawn based on it's acceleration
void ASDTAIController::PawnMovement(FRotator orientation, APawn* pawn, float deltaTime)
{
    speed = speed + std::sqrt(std::pow(acc.X, 2) + std::pow(acc.Y, 2)) * deltaTime;
    // Ensures the AI doesn't go faster than max speed
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    pawn->AddMovementInput(speed * orientation.Vector().GetSafeNormal());
}

// Detects if pawn is chased or is chasing
bool ASDTAIController::PlayerChasing(UWorld* world, FVector pawnLocation, PhysicsHelpers physicsHelper, APawn* pawn)
{
    // Check spherical area around the pawn for the player character
    TArray<FOverlapResult> results = ASDTAIController::SphereDetection(pawn, physicsHelper);
    for (int i = 0; i < results.Num(); i++)
    {
        AActor* foundActor = results[i].GetActor();
        if (foundActor->GetName() == "BP_SDTMainCharacter_C_0")
        {
            // Player found
            FVector fleeVector = pawnLocation - foundActor->GetActorLocation();

            // Chase instead of fleeing if player is vulnerable
            if (!static_cast<ASoftDesignTrainingMainCharacter*>(foundActor)->IsPoweredUp())
            {
                fleeVector *= -1;
            }

            // Check if has line of sight on player
            TArray<struct FHitResult> rayCastHitResult;
            physicsHelper.CastRay(pawnLocation, foundActor->GetActorLocation(), rayCastHitResult, drawDebug);
            bool wallBlocking = false;
            for (int j = 0; j < rayCastHitResult.Num(); ++j) {
                if (!rayCastHitResult[j].GetActor()->GetName().Contains("BP_SDTCollectible")) {
                    wallBlocking = true;
                }
            }

            // Change direction if has LoS on player and won't move into a wall
            if (!wallBlocking && !ASDTAIController::WallDetected(fleeVector.Rotation(), pawnLocation, world, physicsHelper))
            {
                pawn->SetActorRotation(fleeVector.Rotation());
                return true;
            }
        }
    }
    return false;
}