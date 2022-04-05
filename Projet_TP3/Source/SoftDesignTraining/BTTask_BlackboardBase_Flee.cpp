// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BlackboardBase_Flee.h"

#include "SDTAIController.h"


EBTNodeResult::Type UBTTask_BlackboardBase_Flee::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent())
    {
        if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
        {
            //aiController->MoveToBestFleeLocation();
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}
