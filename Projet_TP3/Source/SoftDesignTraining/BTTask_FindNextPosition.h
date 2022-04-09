// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SDTAIController.h"
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindNextPosition.generated.h"

/**
 * 
 */
UCLASS()
class SOFTDESIGNTRAINING_API UBTTask_FindNextPosition : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	FVector findNextCollectible(UBehaviorTreeComponent& OwnerComp, ASDTAIController* aiController);

	FVector findBestFleeLocation(UBehaviorTreeComponent& OwnerComp, ASDTAIController* aiController);


};
