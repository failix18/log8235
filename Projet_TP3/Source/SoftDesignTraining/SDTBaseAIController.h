// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SDTBaseAIController.generated.h"
#include "BehaviorTree/BehaviorTree.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API ASDTBaseAIController : public AAIController
{
	GENERATED_BODY()

public:

    ASDTBaseAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
    
    // probably gonna be desable
    virtual void Tick(float deltaTime) override;

	
protected:
    virtual void RotationUpdate(float deltaTime) {};
    virtual void ImpulseToDirection(float deltaTime) {};

    bool m_ReachedTarget;


private:
    virtual void GoToBestTarget(float deltaTime) {};
    virtual void UpdatePlayerInteraction(float deltaTime) {};
    virtual void ShowNavigationPath() {};
};
