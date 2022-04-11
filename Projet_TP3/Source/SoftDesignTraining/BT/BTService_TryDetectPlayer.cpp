// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_TryDetectPlayer.h"

#include <SoftDesignTraining/SDTAIController.h>
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include <chrono>
#include "DrawDebugHelpers.h"




UBTService_TryDetectPlayer::UBTService_TryDetectPlayer() {
	 bCreateNodeInstance = true; 
}

void UBTService_TryDetectPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		auto startTime = std::chrono::system_clock::now();

		bool isPlayerDetected = aiController->ProcessDetectPlayer();
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerDetectedBBKeyID(), isPlayerDetected);
		auto stopTime = std::chrono::system_clock::now();
		long duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
		DrawDebugString(GetWorld(), FVector(0.f, 0.f, 10.f), "Player: " + FString::FromInt(duration) + " microseconds", aiController->GetPawn(), FColor::Blue, 0.4f, false);


	}
	
}
