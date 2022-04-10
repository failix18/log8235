// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_isPlayerDetected.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include <SoftDesignTraining/SDTAIController.h>

EBTNodeResult::Type UMyBTTask_isPlayerDetected::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		FName n = FName("IsPlayerDetected");
		bool booleen = OwnerComp.GetBlackboardComponent()->GetValueAsBool(n);
		if (booleen) 
		{
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
