// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_updatePlayerState.h"

#include "SDTAIController.h"
#include "SDTUtils.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"



void UBTService_updatePlayerState::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
    {
        uint8 id_IsPlayerPoweredUp = OwnerComp.GetBlackboardComponent()->GetKeyID("IsPlayerPoweredUp");

        //Trigger from service the detect
        if (SDTUtils::IsPlayerPoweredUp(GetWorld())) {
            //write to bb that the player is powered up
            
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(id_IsPlayerPoweredUp, true);

            }
        else
        {
            //write to bb that the player is not powered up
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(id_IsPlayerPoweredUp, false);
        }

    }
}

/*
void getBoolID(ASDTAIController* aiController) {

    aiController->GetBehaviorTree())
    {
        m_blackboardComponent->InitializeBlackboard(*aiBaseCharacter->GetBehaviorTree()->BlackboardAsset);

        m_targetPosBBKeyID = m_blackboardComponent->GetKeyID("TargetPos");
        m_isTargetSeenBBKeyID = m_blackboardComponent->GetKeyID("TargetIsSeen");
        m_nextPatrolDestinationBBKeyID = m_blackboardComponent->GetKeyID("NextPatrolDest");
        m_currentPatrolDestinationBBKeyID = m_blackboardComponent->GetKeyID("CurrentPatrolDest");

        //Set this agent in the BT
        m_blackboardComponent->SetValue<UBlackboardKeyType_Object>(m_blackboardComponent->GetKeyID("SelfActor"), pawn);

    }
}
*/