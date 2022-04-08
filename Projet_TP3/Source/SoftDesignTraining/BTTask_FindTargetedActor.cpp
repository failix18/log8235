// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindTargetedActor.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Kismet/GameplayStatics.h"


EBTNodeResult::Type UBTTask_FindTargetedActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {
        ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
        OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(aiController->GetTargetedPlayerBBKeyID(), Cast<UObject>(playerCharacter));

    }
}
