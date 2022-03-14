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
        }
        PostProcessMove.ExecuteIfBound(this, MoveVelocity);
        CurrentPawn->LaunchPawn(MoveVelocity, false, false);
    }
    else
    {
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
}

bool USDTPathFollowingComponent::IsCollectibleReached()
{
    return CollectibleReached;
}
