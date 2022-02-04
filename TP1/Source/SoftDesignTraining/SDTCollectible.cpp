// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTCollectible.h"
#include "SoftDesignTraining.h"
#include <SoftDesignTraining/SDTUtils.h>

ASDTCollectible::ASDTCollectible()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASDTCollectible::BeginPlay()
{
    Super::BeginPlay();

}

void ASDTCollectible::Collect()
{
    GetWorld()->GetTimerManager().SetTimer(m_CollectCooldownTimer, this, &ASDTCollectible::OnCooldownDone, m_CollectCooldownDuration, false);

    GetStaticMeshComponent()->SetVisibility(false);
}

void ASDTCollectible::OnCooldownDone()
{
    GetWorld()->GetTimerManager().ClearTimer(m_CollectCooldownTimer);

    GetStaticMeshComponent()->SetVisibility(true);
}

bool ASDTCollectible::IsOnCooldown()
{
    return m_CollectCooldownTimer.IsValid();
}

void ASDTCollectible::Tick(float deltaTime)
{
    Super::Tick(deltaTime);
    if (isMoveable)
    {
        FVector location = GetActorLocation();
        UWorld* world = GetWorld();
        
        if (ASDTCollectible::WallDetected(location, world))
        {
            acc = -acc;
        }
        ASDTCollectible::MoveCollectible(location, deltaTime);
    }
}

void ASDTCollectible::MoveCollectible(FVector location, float deltaTime)
{
    speed = speed + acc * deltaTime;
    if (std::abs(speed) > 500.0f) 
    {
        speed = (speed > 0) ? 500.0f : -500.0f;
    }
    SetActorLocation(location + FVector(0.0f, speed * deltaTime, 0.f), true);
}

bool ASDTCollectible::WallDetected(FVector location, UWorld* world)
{
    FVector orientation = FVector(0.0f, acc, 0.0f).GetSafeNormal();
    FVector targetLocation = location + orientation * 750.0f;
    return SDTUtils::Raycast(world, location, targetLocation);
}