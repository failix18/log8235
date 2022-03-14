// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTPathFollowingComponent.h"
#include "SoftDesignTraining.h"
#include "SDTUtils.h"
#include "SDTAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "DrawDebugHelpers.h"
#include <Runtime/NavigationSystem/Public/NavigationSystem.h>

USDTPathFollowingComponent::USDTPathFollowingComponent(const FObjectInitializer& ObjectInitializer)
{

}

void USDTPathFollowingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (Path)
    {
        if (Path->GetPathPoints().Num() > 1)
        {
            FollowPathSegment(DeltaTime);
        }
    }
}

void USDTPathFollowingComponent::FollowPathSegment(float DeltaTime)
{
    const TArray<FNavPathPoint>& points = Path->GetPathPoints();
    const FNavPathPoint& segmentStart = points[MoveSegmentStartIndex];
    const FVector currentLocation = MovementComp->GetActorFeetLocation();

    const FVector destinationDiff = CurrentTarget - currentLocation;

    if (FNavMeshNodeFlags(segmentStart.Flags).IsNavLink()) {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
    }
        
    if (destinationDiff.IsNearlyZero(10.0f))
    {
        SetMoveSegment(0);
    }

    if (FNavMeshNodeFlags(points[CurrentSegmentIndex].Flags).IsNavLink() && !nextPathIsJump)
    {
        nextPathIsJump = true;
    }
    else if (hasToJump)
    {
        FVector MoveVelocity = (CurrentTarget - currentLocation).GetSafeNormal() * 50.0f;
        float nextDistance = (points[CurrentSegmentIndex].Location - currentLocation).Size();
        float prevDistance = (points[CurrentSegmentIndex - 1].Location - currentLocation).Size();
        if (nextDistance > prevDistance)
        {
            MoveVelocity.Z = 75.0f;
        }
        else {
            MoveVelocity.Z = -75.0f;
            InAir = true;
        }
        if (currentLocation.Z < 220.0f) {
            InAir = false;
        }
        PostProcessMove.ExecuteIfBound(this, MoveVelocity);
 
        AtJumpSegment = true;
        CurrentPawn->LaunchPawn(MoveVelocity, false, false);

    }
    else
    {
        
        AtJumpSegment = false;

        speed = speed + 250 * DeltaTime;
        if (std::abs(speed) > 500.0f)
        {
            speed = (speed > 0) ? 500.0f : -500.0f;
        }
        FVector MoveVelocity = (CurrentTarget - currentLocation);
        MoveVelocity = MoveVelocity.GetSafeNormal() * speed;
        PostProcessMove.ExecuteIfBound(this, MoveVelocity);
        MovementComp->RequestDirectMove(MoveVelocity, false);
    }
}

void USDTPathFollowingComponent::SetMoveSegment(int32 segmentStartIndex)
{
    Super::SetMoveSegment(segmentStartIndex);

    const TArray<FNavPathPoint>& points = Path->GetPathPoints();

    const FNavPathPoint& segmentStart = points[MoveSegmentStartIndex];
    hasToJump = false;
    if (nextPathIsJump)
    {
        //Handle starting jump
        nextPathIsJump = false;
        hasToJump = true;
    }

    //Handle normal segments
    if (CurrentSegmentIndex + 1 < points.Num())
    {
        CurrentSegmentIndex++;
        CurrentTarget = points[CurrentSegmentIndex];
    }
    else
    {
        CollectibleReached = true;
    }

}

void USDTPathFollowingComponent::SetPath(FNavPathSharedPtr path, APawn* pawn)
{
    Path = path;
    CurrentPawn = pawn;
    CollectibleReached = false;
    CurrentSegmentIndex = 0;
    SetMoveSegment(0);
    speed = 100.0f;
}

bool USDTPathFollowingComponent::IsCollectibleReached()
{
    return CollectibleReached;
}
