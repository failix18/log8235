// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CollectPickUp.h"

#include <SoftDesignTraining/SDTAIController.h>
#include <chrono>
#include "DrawDebugHelpers.h"



EBTNodeResult::Type UBTTask_CollectPickUp::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		if(aiController->m_ReachedTarget) {
		auto startTime = std::chrono::system_clock::now();
		aiController->MoveToRandomCollectible();
		auto stopTime = std::chrono::system_clock::now();
		long duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
		DrawDebugString(GetWorld(), FVector(100.f, 0.f, 10.f), "Collectible: " + FString::FromInt(duration) + " microseconds", aiController->GetPawn(), FColor::Orange, 1.f, false);

		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
