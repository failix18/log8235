// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTAIController.h"
#include "SoftDesignTraining.h"

void ASDTAIController::Tick(float deltaTime)
{
    //ASDTAIController::MoveForward(1.0f);
    APawn* const pawn = GetPawn();
    UWorld* world = GetWorld();
    //PhysicsHelper newPhysicsHelper(world);

    if (pawn)
    {

        
        FVector acc = FVector(100.0f, 0.0f, 0.0f);
        //PhysicsHelper.CastRay(selfPosition, targetActor->GetActorLocation(), hitResult, true);
        bool wallDetected = ASDTAIController::WallDetection(pawn, world, 200.0f);
        if (wallDetected)
        {
            acc = FVector(100.0f, 100.0f, 0.0f);
        }
        ASDTAIController::PawnMovement(pawn, acc, deltaTime);
    }
}

bool ASDTAIController::WallDetection(APawn* pawn, UWorld* world, float hitDistance)
{
    FVector pawnDirection = pawn->GetLastMovementInputVector();
    FVector pawnLocation = pawn->GetActorLocation();
    FVector targetLocation = pawnLocation + pawnDirection.GetSafeNormal();
    return SDTUtils::Raycast(world, pawnLocation, targetLocation);
}

void ASDTAIController::PawnMovement(APawn* pawn, FVector acc, float deltaTime)
{
    
    FVector currentSpeed = pawn->GetLastMovementInputVector();
    FVector newSpeed = FVector(acc.X * deltaTime, acc.Y * deltaTime, acc.Z * deltaTime);
    float maxSpeed = pawn->GetMovementComponent()->GetMaxSpeed();
    float normSpeed = std::sqrt(std::pow(newSpeed.X, 2) + std::pow(newSpeed.Y, 2));

    if (normSpeed > maxSpeed)
    {
        newSpeed = currentSpeed;
    }

    pawn->AddMovementInput(newSpeed);
    float currentAngle = std::atan2(currentSpeed.Y, currentSpeed.X);
    float newAngle = std::atan2(newSpeed.Y, newSpeed.X);

    FQuat rotation = FQuat(FVector(0.0f, 0.0f, 1.0f), newAngle - currentAngle);
    pawn->AddActorWorldRotation(rotation);
}



