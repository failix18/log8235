// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_updateIsPlayerPowerUp.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

UBTService_updateIsPlayerPowerUp::UBTService_updateIsPlayerPowerUp() {
	bCreateNodeInstance = true;
}

void UBTService_updateIsPlayerPowerUp::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

		//Write to blackboard
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerPoweredUpBBKeyID(), SDTUtils::IsPlayerPoweredUp(GetWorld()));

	}
}
