// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_initateStartTime.h"

#include "SDTAIController.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include <chrono>
#include "BehaviorTree/Blackboard/BlackboardKeyType_String.h"


UBTService_initateStartTime::UBTService_initateStartTime() {
	bCreateNodeInstance = true;
}


void UBTService_initateStartTime::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

		auto startTime = std::chrono::system_clock::now();
		aiController->StartTime = startTime;

	}

}
