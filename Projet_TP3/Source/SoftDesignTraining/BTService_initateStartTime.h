// Fill out your copyright notice in the Description page of Project Settings.

#pragma once




#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_initateStartTime.generated.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API UBTService_initateStartTime : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_initateStartTime();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
