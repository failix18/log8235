// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_TryDetectPlayer.h"

#include <SoftDesignTraining/SDTAIController.cpp>
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"


UBTService_TryDetectPlayer::UBTService_TryDetectPlayer() {
	 bCreateNodeInstance = true; 
}

void UBTService_TryDetectPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		bool isPlayerDetected = aiController->ProcessDetectPlayer();
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerDetectedBBKeyID(), isPlayerDetected);
	}
	
}
