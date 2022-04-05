// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BlackboardBase_Chase.h"

#include "SDTAIController.h"

/*
#include "SoftDesignTraining.h"
#include "SDTCollectible.h"
#include "SDTFleeLocation.h"
#include "SDTPathFollowingComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include <chrono>
*/


EBTNodeResult::Type UBTTask_BlackboardBase_Chase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (const UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent())
    {
        if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
        {
            //aiController->MoveToPlayer();
            /*
            auto startTime = std::chrono::system_clock::now();
            ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
            if (!playerCharacter)
                return;

            aiController->MoveToActor(playerCharacter, 0.5f, false, true, true, NULL, false);
            OnMoveToTarget();
            auto stopTime = std::chrono::system_clock::now();
            long duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
            DrawDebugString(GetWorld(), FVector(0.f, 0.f, 10.f), "Player: " + FString::FromInt(duration) + " microseconds", GetPawn(), FColor::Blue, 5.f, false);
            */

            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}

