// Fill out your copyright notice in the Description page of Project Settings.
#include "BTService__setNextPointInterest.h"

#include "SDTAIController.h"

UBTService__setNextPointInterest::UBTService__setNextPointInterest() {
    bCreateNodeInstance = true;
}

void UBTService__setNextPointInterest::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::Red, TEXT("in UBTService__setNextPointInterest"));

    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

        APawn* selfPawn = aiController->GetPawn();
        FVector detectionStartLocation = selfPawn->GetActorLocation() + selfPawn->GetActorForwardVector() * aiController->m_DetectionCapsuleForwardStartingOffset;
        FVector detectionEndLocation = detectionStartLocation + selfPawn->GetActorForwardVector() * aiController->m_DetectionCapsuleHalfLength * 2;

        TArray<TEnumAsByte<EObjectTypeQuery>> detectionTraceObjectTypes;
        detectionTraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(COLLISION_PLAYER));

        TArray<FHitResult> allDetectionHits;
        GetWorld()->SweepMultiByObjectType(allDetectionHits, detectionStartLocation, detectionEndLocation, FQuat::Identity, detectionTraceObjectTypes, FCollisionShape::MakeSphere(aiController->m_DetectionCapsuleRadius));

        GetHightestPriorityDetectionHit(allDetectionHits, aiController->NextPointOfInterest);
    }
}

void UBTService__setNextPointInterest::GetHightestPriorityDetectionHit(const TArray<FHitResult>& hits, FHitResult& outDetectionHit)
{
    for (const FHitResult& hit : hits)
    {
        if (UPrimitiveComponent* component = hit.GetComponent())
        {
            if (component->GetCollisionObjectType() == COLLISION_PLAYER)
            {
                //we can't get more important than the player
                outDetectionHit = hit;
                return;
            }
            else if (component->GetCollisionObjectType() == COLLISION_COLLECTIBLE)
            {
                outDetectionHit = hit;
            }
        }
    }
}
