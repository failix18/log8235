// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_updateState.h"


#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_String.h"
#include "SDTAIController.h"

EBTNodeResult::Type UBTTask_updateState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {
        FName n = FName("IsChasingOrFleeing");
        bool booleen = OwnerComp.GetBlackboardComponent()->GetValueAsBool(n);
        if (booleen) {

            if (OwnerComp.GetBlackboardComponent()->GetValueAsBool(FName("IsPlayerPoweredUp"))) {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Flee");
            }
            else {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Chase");
            }

        }
        else {
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Collect");
        }
        
    }
    return EBTNodeResult::Succeeded;
}

//EBTNodeResult::Type BTTask_updateState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{

    //if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {
        /*FName n = FName("IsChasingOrFleeing");
        bool booleen = OwnerComp.GetBlackboardComponent()->GetValueAsBool(n);
        if (booleen) {

            if (OwnerComp.GetBlackboardComponent()->GetValueAsBool(FName("IsPlayerPoweredUp"))) {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Flee");
            }
            else {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Chase");
            }

        }
        else {
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Collect");
        }*/
    //}

    //return EBTNodeResult::Succeeded;
//}


/*EBTNodeResult::Type UBTTask_updateState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

        if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(aiController->GetIsChasingOrFleeingBBKeyID())) {

            if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerPoweredUpBBKeyID())) {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Flee");
            }
            else {
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Chase");
            }

        }
        else {
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID(), "Collect");
        }

        return EBTNodeResult::Succeeded;
       }
}
*/


