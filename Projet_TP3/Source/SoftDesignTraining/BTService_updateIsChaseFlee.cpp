// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_updateIsChaseFlee.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

UBTService_updateIsChaseFlee::UBTService_updateIsChaseFlee() {
	bCreateNodeInstance = true;
}


void UBTService_updateIsChaseFlee::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::Red, TEXT("in UBTService_updateIsChaseFlee"));

	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

		if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerDetectedBBKeyID())) {

			//Write to blackboard
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerDetectedBBKeyID(), false);
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsChasingOrFleeingBBKeyID() , true);

		}
	}
}
