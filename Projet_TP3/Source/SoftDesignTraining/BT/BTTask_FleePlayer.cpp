// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FleePlayer.h"

#include <SoftDesignTraining/SDTAIController.cpp>


EBTNodeResult::Type UBTTask_FleePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		aiController->MoveToBestFleeLocation();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
