// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"
#include <SoftDesignTraining/SDTUtils.h>

void ASDTAIController::Tick(float deltaTime)
{
    //ASDTAIController::MoveForward(1.0f);
    APawn* const pawn = GetPawn();
    UWorld* world = GetWorld();
    //PhysicsHelper newPhysicsHelper(world);

    if (pawn)
    {
        FVector pawnLocation = pawn->GetActorLocation();
        FRotator orientation = pawn->GetActorRotation();
        ASDTAIController::FindDirection(orientation, pawnLocation, world);
        //PhysicsHelper.CastRay(selfPosition, targetActor->GetActorLocation(), hitResult, true);
        if (ASDTAIController::WallDetected(orientation, pawnLocation, world))
        {
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


bool ASDTAIController::CollectibleDetection(APawn* pawn, UWorld* world)
{
    FVector pawnDirection = pawn->GetLastMovementInputVector();
    FVector pawnLocation = pawn->GetActorLocation();
    FVector targetLocation = pawnLocation + pawnDirection.GetSafeNormal() * hitDistance;
    return SDTUtils::Raycast(world, pawnLocation, targetLocation);
}


void ASDTAIController::PawnMovement(FRotator orientation, APawn* pawn, float deltaTime)
{
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    pawn->AddMovementInput(speed * orientation.Vector().GetSafeNormal());
}