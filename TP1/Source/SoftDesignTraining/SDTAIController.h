// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PhysicsHelpers.h"

#include "SDTAIController.generated.h"

/**
 *
 */
UCLASS(ClassGroup = AI, config = Game)
class SOFTDESIGNTRAINING_API ASDTAIController : public AAIController
{
    GENERATED_BODY()
public:
    virtual void Tick(float deltaTime) override;

    // Pawn's max speed
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "10.0", ClampMax = "100.0", UIMin = "10.0", UIMax = "100.0"))
        float maxSpeed = 500.0f;

    // Pawn's acceleration along X axis
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
        float accX = 100.0f;

    // Pawn's acceleration along Y axis
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
        float accY = 0.0f;

    // Distance where the wall is detected
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "10.0", ClampMax = "1000.0", UIMin = "10.0", UIMax = "1000.0"))
        float hitDistance = 200.0f;

    // Distance where the pawn sees
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "10.0", ClampMax = "10000.0", UIMin = "10.0", UIMax = "10000.0"))
        float visionDistance = 2000.0f;

    // Radius of the sphere cast sent
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (ClampMin = "10.0", ClampMax = "10000.0", UIMin = "10.0", UIMax = "10000.0"))
        float radiusDetection = 500.0f;

    // Radius of the sphere cast sent
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        bool drawDebug = false;

    // Acceleration vector
    FVector acc = FVector(accX, accY, 0.0f);
    float speed = 100.0f;

    // Helps the pawn decide if he goes left or right
    float preferedDirection = 1.0f;

    bool WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper);
    bool PickupDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn);
    bool DeathTrapDetected(FRotator orientation, FVector pawnLocation, UWorld* world, PhysicsHelpers physicsHelper, APawn* pawn);

    void FindDirection(FRotator orientation, FVector pawnLocation, UWorld* world);
    void PawnMovement(FRotator orientation, APawn* pawn, float deltaTime);
};