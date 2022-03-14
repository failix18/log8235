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
        
    //for (FNavPathPoint pts : points)
    //{
    //    if (FNavMeshNodeFlags(pts.Flags).IsNavLink()) {
    //        CurrentTarget = pts;
    //        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
    //        break;
    //    }
    //}

    if (destinationDiff.IsNearlyZero(10.0f))
    {
        SetMoveSegment(0);
    }

    if (SDTUtils::HasJumpFlag(segmentStart))
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("envie de mourir"));
    }
    else
    {
        //DrawDebugLine(
        //    GetWorld(),
        //    currentLocation,
        //    CurrentTarget,
        //    FColor(255, 0, 0),
        //    false, -1, 0,
        //    5.f
        //);
        //update navigation along path
        //CurrentTarget = pathToFollow[1];
        FVector MoveVelocity = (CurrentTarget - currentLocation) / DeltaTime;
        //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, MoveVelocity.ToString());
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
       /* if (MovementComp->GetActorFeetLocation() == CurrentTarget) {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
        }*/

        //Handle normal segments
        if (CurrentSegmentIndex + 1 < points.Num())
        {
            CurrentSegmentIndex++;
            CurrentTarget = points[CurrentSegmentIndex];
   //         int linkId = 0;
   //         for (FNavPathPoint pts : points)
   //         {
   //             if (FNavMeshNodeFlags(pts.Flags).IsNavLink()) {
   //                 linkId = pts.CustomLinkId;
   //             }
   //         }
   //         UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
			//INavLinkCustomInterface* CustomNavLink = NavSys->GetCustomLink(linkId);
   //         UObject* NewNavLinkOb = Cast<UObject>(CustomNavLink);


            if (FNavMeshNodeFlags(points[CurrentSegmentIndex].Flags).IsNavLink()) {

                 for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It) {
                     APawn* Pawn = Cast<APawn>(*It);
                     if ((Pawn->GetActorLocation() - MovementComp->GetActorFeetLocation()).IsNearlyZero(100.0f)) {
                         //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some  message!"));
                         //Pawn->LaunchPawn(FVector(0, 0, 1000), false, false);
                         Pawn->SetActorLocation(points[CurrentSegmentIndex+1]);
                     }
                 }
                 DrawDebugLine(
                   GetWorld(),
                   MovementComp->GetActorFeetLocation(),
                   CurrentTarget,
                   FColor(255, 0, 0),
                   false, -1, 0,
                   5.f
       );
            }

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
