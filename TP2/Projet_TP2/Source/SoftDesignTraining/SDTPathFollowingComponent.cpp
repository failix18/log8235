// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTPathFollowingComponent.h"
#include "SoftDesignTraining.h"
#include "SDTUtils.h"
#include "SDTAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "DrawDebugHelpers.h"

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
    if (destinationDiff.IsNearlyZero(10.0f))
    {
        SetMoveSegment(0);
    }

    if (SDTUtils::HasJumpFlag(segmentStart))
    {
        //update jump
    }
    else
    {
        DrawDebugLine(
            GetWorld(),
            currentLocation,
            CurrentTarget,
            FColor(255, 0, 0),
            false, -1, 0,
            5.f
        );
        //update navigation along path
        //CurrentTarget = pathToFollow[1];
        FVector MoveVelocity = (CurrentTarget - currentLocation) / DeltaTime;

        PostProcessMove.ExecuteIfBound(this, MoveVelocity);
        MovementComp->RequestDirectMove(MoveVelocity, true);
    }
}

void USDTPathFollowingComponent::SetMoveSegment(int32 segmentStartIndex)
{
    Super::SetMoveSegment(segmentStartIndex);

    const TArray<FNavPathPoint>& points = Path->GetPathPoints();

    const FNavPathPoint& segmentStart = points[MoveSegmentStartIndex];

    if (SDTUtils::HasJumpFlag(segmentStart) && FNavMeshNodeFlags(segmentStart.Flags).IsNavLink())
    {
        //Handle starting jump
    }
    else
    {
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
}

void USDTPathFollowingComponent::SetPath(FNavPathSharedPtr path)
{
    Path = path;
    CollectibleReached = false;
    CurrentSegmentIndex = 0;
    SetMoveSegment(0);
}

bool USDTPathFollowingComponent::IsCollectibleReached()
{
    return CollectibleReached;
}
