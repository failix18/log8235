// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "PhysicsHelpers.h"
#include "SoftDesignTraining.h"
#include "DrawDebugHelpers.h"
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
        if (ASDTAIController::PickupDetected(orientation, pawnLocation, world, physicsHelper, pawn)) {
             orientation = orientation.Add(0.0f, preferedDirection * 10.0f, 0.0f);
             pawn->SetActorRotation(orientation);
        } else if (ASDTAIController::WallDetected(orientation, pawnLocation, world)){
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

bool ASDTAIController::WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world)
{
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * hitDistance;
    return SDTUtils::Raycast(world, pawnLocation, targetLocation);
}


bool ASDTAIController::PickupDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn)
{
    TArray<struct FHitResult> hitResult;
    FVector targetLocation = pawnLocation + orientation.Vector().GetSafeNormal() * visionDistance;
    physicsHelper.SphereCast(pawnLocation, targetLocation, radiusDetection, hitResult, drawDebug);
    
    int hitResSize = hitResult.Num();
    FVector pickupLocation;
    for (int i = 0; i < hitResSize; ++i) {
        if (hitResult[i].GetActor()->GetName().Contains("SDTCollectible")) {
            TArray<struct FHitResult> rayCastHitResult;
            pickupLocation = hitResult[i].ImpactPoint;
            FVector pawnToPickup = pickupLocation - pawnLocation; 


            physicsHelper.CastRay(pawnLocation, pickupLocation, rayCastHitResult,drawDebug);
            if (rayCastHitResult.Num() != 0) {
                if (rayCastHitResult[0].GetActor()->GetName().Contains("SDTCollectible")) {
                    DrawDebugDirectionalArrow(world, pawnLocation, pickupLocation, 100, FColor::Red, false, -1.0f, 000, 5.0f);
                    preferedDirection = orientation.Vector().CosineAngle2D(pawnToPickup) > 0 ? 1.0f : -1.0;
                   /* FRotator orientation = pawn->GetActorRotation();
                    pawn->SetActorRotation(orientation.Add(0.0f, orientation.Vector().CosineAngle2D(pawnToPickup), 0.0f));
                    */
                    return true;
                }
            }
        }
    }

    return false;
}
/*  float dot = pawnToPickup.X * targetLocation.X + pawnToPickup.Y * targetLocation.Y;
           float det = pawnToPickup.X * targetLocation.Y - targetLocation.X * pawnToPickup.Y;
           float angle = std::atan2(det, dot);*/

void ASDTAIController::PawnMovement(FRotator orientation, APawn* pawn, float deltaTime)
{
    speed = speed + std::sqrt(std::pow(acc.X, 2) + std::pow(acc.Y, 2)) * deltaTime;
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    pawn->AddMovementInput(speed * orientation.Vector().GetSafeNormal());
}