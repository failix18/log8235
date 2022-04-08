// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DrawDebug.h"

#include "SDTAIController.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h"
#include <chrono>
#include "BehaviorTree/Blackboard/BlackboardKeyType_String.h"

EBTNodeResult::Type UBTTask_DrawDebug::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

        APawn* selfPawn = aiController->GetPawn();

        auto stopTime = std::chrono::system_clock::now();
        long duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - aiController->StartTime).count();
        DrawDebugString(GetWorld(), FVector(0.f, 0.f, 10.f), "Player: " + FString::FromInt(duration) + " microseconds", selfPawn, FColor::Blue, 5.f, false);
        
        FString debugString = OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_String>(aiController->GetPawnStateBBKeyID());
        DrawDebugString(GetWorld(), FVector(0.f, 0.f, 5.f), debugString, selfPawn, FColor::Orange, 0.f, false);

        FVector detectionStartLocation = selfPawn->GetActorLocation() + selfPawn->GetActorForwardVector() * aiController->m_DetectionCapsuleForwardStartingOffset;
        DrawDebugCapsule(GetWorld(), detectionStartLocation + aiController->m_DetectionCapsuleHalfLength * selfPawn->GetActorForwardVector(), aiController->m_DetectionCapsuleHalfLength, aiController->m_DetectionCapsuleRadius, selfPawn->GetActorQuat() * selfPawn->GetActorUpVector().ToOrientationQuat(), FColor::Blue);

        return EBTNodeResult::Succeeded;
    }
}
