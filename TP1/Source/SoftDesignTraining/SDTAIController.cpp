// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "PhysicsHelpers.h"
#include "SoftDesignTraining.h"
#include "DrawDebugHelpers.h"
#include <SoftDesignTraining/SDTUtils.h>
#include <SoftDesignTraining/SDTCollectible.h>

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
        if (ASDTAIController::PickupDetected(orientation, pawnLocation, world, physicsHelper, pawn))
        {
             /*orientation = orientation.Add(0.0f, preferedDirection * 1.0f, 0.0f);
             pawn->SetActorRotation(orientation);*/
        }
        else if (ASDTAIController::WallDetected(orientation, pawnLocation, world, physicsHelper))
        {
            //preferedDirection = std::rand() % 2 == 0 ? -1.0f : 1.0f;
            orientation = orientation.Add(0.0f, preferedDirection * 10.0f, 0.0f);
            pawn->SetActorRotation(orientation);
        }

        ASDTAIController::PawnMovement(orientation, pawn, deltaTime);
    }
}

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

bool ASDTAIController::WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper)
{
    TArray<struct FHitResult> rayCastHitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * hitDistance;
    return physicsHelper.CastRay(pawnLocation, targetLocation, rayCastHitResult, drawDebug);

   /* for (int i = 0; i < rayCastHitResult.Num(); ++i) {
        if (rayCastHitResult[i].GetActor()->GetName().Contains("Wall")) {
            return true;
        }
    }
    return false;*/
}


bool ASDTAIController::PickupDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn)
{
    TArray<struct FHitResult> sphereHitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * visionDistance;
    FVector startLocation = pawnLocation + orientation.Vector().GetSafeNormal() * radiusDetection;
    physicsHelper.SphereCast(startLocation, targetLocation, radiusDetection, sphereHitResult, drawDebug);
    
    TArray<FVector> pickupLocations;
    for (int i = 0; i < sphereHitResult.Num(); ++i) {
        if (sphereHitResult[i].GetActor()->GetName().Contains("BP_SDTCollectible"))
        {
            if (static_cast<ASDTCollectible*>(sphereHitResult[i].GetActor())->GetStaticMeshComponent()->GetVisibleFlag())
            {
                pickupLocations.Add(sphereHitResult[i].ImpactPoint);
            }
        }
    }

    for (int i = 0; i < pickupLocations.Num(); ++i) {
        FVector pawnToPickup = pickupLocations[i] - pawnLocation;
        TArray<struct FHitResult> rayCastHitResult;
        physicsHelper.CastRay(pawnLocation, pickupLocations[i], rayCastHitResult, drawDebug);
        bool wallBlocking = false;
        for (int j = 0; j < rayCastHitResult.Num(); ++j) {
            if (rayCastHitResult[j].GetActor()->GetName().Contains("Wall")) {
                wallBlocking = true;
            }
        }

        if (!wallBlocking) {
            DrawDebugDirectionalArrow(world, pawnLocation, pickupLocations[i], 100, FColor::Red, false, -1.0f, 000, 5.0f);
            FRotator newDirection = FRotator(0.0f, pawnToPickup.ToOrientationRotator().Yaw, 0.0f);
            pawn->SetActorRotation(newDirection);
            return true;
        }
    }
    return false;
}

bool ASDTAIController::DeathTrapDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn)
{
    TArray<struct FHitResult> sphereHitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * visionDistance;
    FVector startLocation = pawnLocation + orientation.Vector().GetSafeNormal() * radiusDetection;
    physicsHelper.SphereCast(startLocation, targetLocation, radiusDetection, sphereHitResult, drawDebug);

    TArray<FVector> pickupLocations;
    for (int i = 0; i < sphereHitResult.Num(); ++i) {
        if (sphereHitResult[i].GetActor()->GetName().Contains("BP_SDTCollectible"))
        {
            if (static_cast<ASDTCollectible*>(sphereHitResult[i].GetActor())->GetStaticMeshComponent()->GetVisibleFlag())
            {
                pickupLocations.Add(sphereHitResult[i].ImpactPoint);
            }
        }
    }

    for (int i = 0; i < pickupLocations.Num(); ++i) {
        FVector pawnToPickup = pickupLocations[i] - pawnLocation;
        TArray<struct FHitResult> rayCastHitResult;
        physicsHelper.CastRay(pawnLocation, pickupLocations[i], rayCastHitResult, drawDebug);
        bool wallBlocking = false;
        for (int j = 0; j < rayCastHitResult.Num(); ++j) {
            if (rayCastHitResult[j].GetActor()->GetName().Contains("Wall")) {
                wallBlocking = true;
            }
        }

        if (!wallBlocking) {
            DrawDebugDirectionalArrow(world, pawnLocation, pickupLocations[i], 100, FColor::Red, false, -1.0f, 000, 5.0f);
            FRotator newDirection = FRotator(0.0f, pawnToPickup.ToOrientationRotator().Yaw, 0.0f);
            pawn->SetActorRotation(newDirection);
            return true;
        }
    }
    return false;
}

void ASDTAIController::PawnMovement(FRotator orientation, APawn* pawn, float deltaTime)
{
    speed = speed + std::sqrt(std::pow(acc.X, 2) + std::pow(acc.Y, 2)) * deltaTime;
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    pawn->AddMovementInput(speed * orientation.Vector().GetSafeNormal());
}