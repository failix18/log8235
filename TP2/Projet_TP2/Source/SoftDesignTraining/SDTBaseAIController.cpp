// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTBaseAIController.h"
#include "SoftDesignTraining.h"


ASDTBaseAIController::ASDTBaseAIController(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    m_ReachedTarget = true;
}

void ASDTBaseAIController::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    APawn* const pawn = GetPawn();
    UWorld* world = GetWorld();
    FVector pawnLocation = pawn->GetActorLocation();
    FRotator orientation = pawn->GetActorRotation();

    FVector speedvect = pawn->GetMovementComponent()->Velocity;
    AnimationNavigationSpeed = speedvect.Size();


    ChooseBehavior(deltaTime);

    if (m_ReachedTarget)
    {
        GoToBestTarget(deltaTime, world, pawnLocation);
    }
    else
    {
        ShowNavigationPath(pawnLocation);
    }
}


