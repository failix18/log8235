// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SDTBaseAIController.h"
#include "SDTAIController.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = AI, config = Game)
class SOFTDESIGNTRAINING_API ASDTAIController : public ASDTBaseAIController
{
	GENERATED_BODY()

public:
    ASDTAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float m_DetectionCapsuleHalfLength = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float m_DetectionCapsuleRadius = 250.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float m_DetectionCapsuleForwardStartingOffset = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    UCurveFloat* JumpCurve;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float JumpApexHeight = 300.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
    float JumpSpeed = 1.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI)
    bool AtJumpSegment = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI)
    bool InAir = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AI)
    bool Landing = false;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float MaxSpeed = 300.f;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float RotationRate = 100.f;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
    float Acceleration = 300.f;

public:
    virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
    void AIStateInterrupted();

protected:
    TArray<FVector> PathToFollow;
    int32           CurrentDestinationIndex = -1;
    float           CurrentSpeed = 0.f;
    FVector         Direction = FVector(0.f, 1.f, 0.f);

    bool            IsTurning = false;
    float           SlowDownTargetSpeed = -1.f;
    FVector         SlowDownStartPos = FVector::ZeroVector;
    int32           IndexAfterSlowDown = -1;

    void OnMoveToTarget();
    void GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit);
    void UpdatePlayerInteraction(float deltaTime);

    FVector ComputeDestination(FVector pawnLocation);
    void    UpdateDirection(float DeltaTime, FVector directionGoal);
    FVector ComputeVelocity(float DeltaTime, FVector destination);
    float   ComputeTargetSpeedForTurn();
    void    ApplyVelocity(float DeltaTime, FVector velocity);

	// Exercise function to complete
    void    UseIntermediaryDestination_Behavior(FVector2D position2D, FVector2D destination2D, FVector& destination);
    float   UseSlowDownForTurns_Behavior(FVector destination, float deltaTime);
    void    UseShortcuts_Behavior(FVector2D& destination2D, FVector& destination, FVector pawnLocation);

private:
    virtual void GoToBestTarget(float deltaTime, UWorld* world, FVector pawnLocation) override;
    virtual void ChooseBehavior(float deltaTime) override;
    virtual void ShowNavigationPath(FVector pawnLocation) override;
};
