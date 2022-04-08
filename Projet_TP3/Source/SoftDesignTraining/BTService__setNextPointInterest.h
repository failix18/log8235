// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService__setNextPointInterest.generated.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API UBTService__setNextPointInterest : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService__setNextPointInterest();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	void GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit);
	
};
