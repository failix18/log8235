// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SDTCollectible.generated.h"

/**
 *
 */
UCLASS()
class SOFTDESIGNTRAINING_API ASDTCollectible : public AStaticMeshActor
{
    GENERATED_BODY()
public:
    ASDTCollectible();

    void Collect();
    void OnCooldownDone();
    bool IsOnCooldown();
    void MoveCollectible(FVector location, float deltaTime);
    bool WallDetected(FVector location, UWorld* world);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        float m_CollectCooldownDuration = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
        bool isMoveable = false;

    float speed = -500.0f;
    float acc = -250.0f;

    virtual void Tick(float deltaTime) override;
    virtual void BeginPlay() override;

    FVector initialPosition;

protected:
    FTimerHandle m_CollectCooldownTimer;

};