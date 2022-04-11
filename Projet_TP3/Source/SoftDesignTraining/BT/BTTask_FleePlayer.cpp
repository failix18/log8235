// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FleePlayer.h"

#include <SoftDesignTraining/SDTAIController.h>
#include <chrono>
#include "DrawDebugHelpers.h"


EBTNodeResult::Type UBTTask_FleePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		auto startTime = std::chrono::system_clock::now();

		aiController->MoveToBestFleeLocation();
		auto stopTime = std::chrono::system_clock::now();
		long duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
		DrawDebugString(GetWorld(), FVector(100.f, 0.f, 10.f), "Flee: " + FString::FromInt(duration) + " microseconds", aiController->GetPawn(), FColor::Red, 0.05f, false);
		return EBTNodeResult::Succeeded;

	}
	return EBTNodeResult::Failed;
}
