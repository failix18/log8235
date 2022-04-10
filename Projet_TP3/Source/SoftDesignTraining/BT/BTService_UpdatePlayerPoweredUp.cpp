// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdatePlayerPoweredUp.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include <SoftDesignTraining/SDTAIController.h>

UBTService_UpdatePlayerPoweredUp::UBTService_UpdatePlayerPoweredUp() {
	bCreateNodeInstance = true;
}

void UBTService_UpdatePlayerPoweredUp::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

		//Write to blackboard
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerPoweredUpBBKeyID(), SDTUtils::IsPlayerPoweredUp(GetWorld()));

	}
}
