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

    // TODO on final cleanup: make this an enum for pretty? 0-2 -> collectible, chase, flee
    float behavior = 0;

protected:
    TArray<FVector> PathToFollow;

    void OnMoveToTarget();
    void GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit);
    void UpdatePlayerInteraction(float deltaTime);

private:
    virtual void GoToBestTarget(float deltaTime, UWorld* world, FVector pawnLocation) override;
    virtual void ChooseBehavior(float deltaTime) override;
    virtual void ShowNavigationPath(FVector pawnLocation) override;
};
