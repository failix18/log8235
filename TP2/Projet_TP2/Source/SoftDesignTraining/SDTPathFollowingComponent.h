// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "SDTPathFollowingComponent.generated.h"

/**
*
*/
UCLASS(ClassGroup = AI, config = Game)
class SOFTDESIGNTRAINING_API USDTPathFollowingComponent : public UPathFollowingComponent
{
    GENERATED_UCLASS_BODY()
    bool CollectibleReached = false;
    int CurrentSegmentIndex = 1;
    FVector CurrentTarget = FVector::ZeroVector;
    float speed = 0.0f;
    bool nextPathIsJump = false;
    bool hasToJump = false;
    APawn* CurrentPawn;
    bool AtJumpSegment = false;
    bool InAir = false;

public:
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void FollowPathSegment(float deltaTime) override;
    virtual void SetMoveSegment(int32 segmentStartIndex) override;
    void SetPath(FNavPathSharedPtr path, APawn* pawn);
    bool IsCollectibleReached();
};