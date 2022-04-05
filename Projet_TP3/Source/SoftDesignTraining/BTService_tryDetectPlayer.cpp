// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_tryDetectPlayer.h"

#include "SDTAIController.h"

#include "SoftDesignTraining.h"
#include "SDTCollectible.h"
#include "SDTFleeLocation.h"
#include "SDTPathFollowingComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "SDTUtils.h"
#include "EngineUtils.h"
#include <chrono>
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"


UBTService_tryDetectPlayer::UBTService_tryDetectPlayer()
{
}

void UBTService_tryDetectPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{

        //finish jump before updating AI state
        if (aiController->AtJumpSegment)
            return;

        APawn* selfPawn = aiController->GetPawn();
        if (!selfPawn)
            return;

        ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
        if (!playerCharacter)
            return;

        FVector detectionStartLocation = selfPawn->GetActorLocation() + selfPawn->GetActorForwardVector() * aiController->m_DetectionCapsuleForwardStartingOffset;
        FVector detectionEndLocation = detectionStartLocation + selfPawn->GetActorForwardVector() * aiController->m_DetectionCapsuleHalfLength * 2;

        TArray<TEnumAsByte<EObjectTypeQuery>> detectionTraceObjectTypes;
        detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_PLAYER));

        TArray<FHitResult> allDetectionHits;
        GetWorld()->SweepMultiByObjectType(allDetectionHits, detectionStartLocation, detectionEndLocation, FQuat::Identity, detectionTraceObjectTypes, FCollisionShape::MakeSphere(m_DetectionCapsuleRadius));

        FHitResult detectionHit;
        aiController->GetHightestPriorityDetectionHit(allDetectionHits, detectionHit);

        

        
        FString debugString = "";


        DrawDebugString(GetWorld(), FVector(0.f, 0.f, 5.f), debugString, GetPawn(), FColor::Orange, 0.f, false);
        DrawDebugCapsule(GetWorld(), detectionStartLocation + m_DetectionCapsuleHalfLength * selfPawn->GetActorForwardVector(), m_DetectionCapsuleHalfLength, m_DetectionCapsuleRadius, selfPawn->GetActorQuat() * selfPawn->GetActorUpVector().ToOrientationQuat(), FColor::Blue);

        Updateblackboard(detectionHit, OwnerComp, aiController);

	}

}

void Updateblackboard(FHitResult hit,  UBehaviorTreeComponent& OwnerComp, ASDTAIController* aiController)
{
    uint8 id_IsChasingOrFleeing = OwnerComp.GetBlackboardComponent()->GetKeyID("IsChasingOrFleeing");
    if (!hit.GetComponent() ||
        hit.GetComponent()->GetCollisionObjectType() != COLLISION_PLAYER ||
        !aiController->HasLoSOnHit(hit)){
        OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(id_IsChasingOrFleeing, false);
    }

    else {
        OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(id_IsChasingOrFleeing, true);
    }
        
}
