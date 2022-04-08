// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//BT
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include <chrono>

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

    UPROPERTY(EditAnywhere, category = Behavior)
    UBehaviorTree* m_aiBehaviorTree;

protected:

    enum PlayerInteractionBehavior
    {
        PlayerInteractionBehavior_Collect,
        PlayerInteractionBehavior_Chase,
        PlayerInteractionBehavior_Flee
    };

    void GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit);
    void UpdatePlayerInteractionBehavior(const FHitResult& detectionHit, float deltaTime);
    PlayerInteractionBehavior GetCurrentPlayerInteractionBehavior(const FHitResult& hit);
    bool HasLoSOnHit(const FHitResult& hit);
    void MoveToRandomCollectible();
    void MoveToPlayer();
    void MoveToBestFleeLocation();
    void PlayerInteractionLoSUpdate();
    void OnPlayerInteractionNoLosDone();
    void OnMoveToTarget();

    //BT
    virtual void OnPossess(APawn* pawn) override;


public:
    virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
    void RotateTowards(const FVector& targetLocation);
    void SetActorLocation(const FVector& targetLocation);
    void AIStateInterrupted();

    //behavior tree
    UBehaviorTree* GetBehaviorTree() const { return m_aiBehaviorTree; }
    void           StartBehaviorTree(APawn* pawn);
    void           StopBehaviorTree(APawn* pawn);

    uint8   GetIsChasingOrFleeingBBKeyID() const{ return isChasingOrFleeingBBKeyID; };
    uint8   GetIsPlayerPoweredUpBBKeyID() const{ return isPlayerPoweredUpBBKeyID; };
    uint8   GetPawnStateBBKeyID() const{ return pawnStateBBKeyID; };
    uint8   GetNextPositionBBKeyID() const{ return nextPositionBBKeyID; };
    uint8   GetIsJumpingBBKeyID() const{ return isJumpingBBKeyID; };
    uint8   GetIsPlayerDetectedBBKeyID() const{ return isPlayerDetectedBBKeyID; };
    uint8   GetTargetedPlayerBBKeyID() const{ return targetedPlayerBBKeyID; };

private:
    virtual void GoToBestTarget(float deltaTime) override;
    virtual void UpdatePlayerInteraction(float deltaTime) override;
    virtual void ShowNavigationPath() override;


protected:
    FVector m_JumpTarget;
    FRotator m_ObstacleAvoidanceRotation;
    FTimerHandle m_PlayerInteractionNoLosTimer;
    PlayerInteractionBehavior m_PlayerInteractionBehavior;

//behavior tree
private:

    UPROPERTY(transient)
        UBehaviorTreeComponent* m_behaviorTreeComponent;

    UPROPERTY(transient)
        UBlackboardComponent* m_blackboardComponent;


    uint8   isChasingOrFleeingBBKeyID;
    uint8   isPlayerPoweredUpBBKeyID;
    uint8   pawnStateBBKeyID;
    uint8   nextPositionBBKeyID;
    uint8   isJumpingBBKeyID;
    uint8   isPlayerDetectedBBKeyID;
    uint8   targetedPlayerBBKeyID;

public :
    std::chrono::system_clock::time_point StartTime;
    FHitResult NextPointOfInterest;
    
};
