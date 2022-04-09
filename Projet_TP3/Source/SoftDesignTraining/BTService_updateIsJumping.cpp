// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_updateIsJumping.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

UBTService_updateIsJumping::UBTService_updateIsJumping() {
	bCreateNodeInstance = true;
}

void UBTService_updateIsJumping::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

		//Write to blackboard
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsJumpingBBKeyID(), aiController->AtJumpSegment);

	}
}
