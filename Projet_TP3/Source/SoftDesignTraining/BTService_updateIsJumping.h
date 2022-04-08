// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_updateIsJumping.generated.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API UBTService_updateIsJumping : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	

public:
	UBTService_updateIsJumping();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
