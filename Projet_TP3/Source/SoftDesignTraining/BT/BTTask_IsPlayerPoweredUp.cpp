// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IsPlayerPoweredUp.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include <SoftDesignTraining/SDTAIController.h>
EBTNodeResult::Type UBTTask_IsPlayerPoweredUp::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		FName n = FName("IsPlayerPoweredUp");
		bool booleen = OwnerComp.GetBlackboardComponent()->GetValueAsBool(n);
		if (booleen) 
			{
				return EBTNodeResult::Succeeded;
			}
		
		
	}
	return EBTNodeResult::Failed;
}
