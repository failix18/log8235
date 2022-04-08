// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_updateIsPlayerDetected.h"

#include "SDTUtils.h"
#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

void UBTService_updateIsPlayerDetected::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {

        FHitResult hit = aiController->NextPointOfInterest;

        // aucun objet repere
        if (!hit.GetComponent())
            updateInBlackboard(OwnerComp, aiController, false);

        // le joueur ne fait pas parti des objets repere
        else if (hit.GetComponent()->GetCollisionObjectType() != COLLISION_PLAYER)
            updateInBlackboard(OwnerComp, aiController, false);

        // le joueur est repere mais pas visible par le pawn
        else if (!HasLoSOnHit(hit, aiController))
            updateInBlackboard(OwnerComp, aiController, false);

        else 
            updateInBlackboard(OwnerComp, aiController, true);


	}
}

//Write to blackboard
void UBTService_updateIsPlayerDetected::updateInBlackboard(UBehaviorTreeComponent& OwnerComp, ASDTAIController* aiController, bool value) {
	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(aiController->GetIsPlayerDetectedBBKeyID(),value );

}



// joueur est visible ?
bool UBTService_updateIsPlayerDetected::HasLoSOnHit(const FHitResult& hit, ASDTAIController* aiController)
{
    
    if (!hit.GetComponent())
        return false;

    TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;
    TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

    FVector hitDirection = hit.ImpactPoint - hit.TraceStart;
    hitDirection.Normalize();

    FHitResult losHit;
    FCollisionQueryParams queryParams = FCollisionQueryParams();
    queryParams.AddIgnoredActor(hit.GetActor());

    aiController->GetWorld()->LineTraceSingleByObjectType(losHit, hit.TraceStart, hit.ImpactPoint + hitDirection, TraceObjectTypes, queryParams);

    return losHit.GetActor() == nullptr;
}