// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindTargetedActor.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Kismet/GameplayStatics.h"
#include "SoftDesignTraining.h"



EBTNodeResult::Type UBTTask_FindTargetedActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {
        ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(aiController->GetWorld(), 0);
        if (!playerCharacter)
            return EBTNodeResult::Failed;
        OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(aiController->GetNextPositionBBKeyID(), playerCharacter->GetActorLocation());

    }
    return EBTNodeResult::Succeeded;
}



