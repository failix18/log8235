// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CollectPickUp.h"

#include <SoftDesignTraining/SDTAIController.cpp>


EBTNodeResult::Type UBTTask_CollectPickUp::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		aiController->MoveToRandomCollectible();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
