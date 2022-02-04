// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

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

    // Acceleration vector
    FVector acc = FVector(accX, accY, 0.0f);
    float speed = 500.0f;

    // Helps the pawn decide if he goes left or right
    float preferedDirection = 1.0f;

    bool WallDetected(FRotator orientation, FVector pawnLocation, UWorld* world);
    bool CollectibleDetection(APawn* pawn, UWorld* world);

    void FindDirection(FRotator orientation, FVector pawnLocation, UWorld* world);
    void RefineDirection(FRotator orientation, FVector pawnLocation, UWorld* world);
    void PawnMovement(FRotator orientation, APawn* pawn, float deltaTime);
};