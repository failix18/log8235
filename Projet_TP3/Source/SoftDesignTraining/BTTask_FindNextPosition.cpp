// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindNextPosition.h"

#include "SDTAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

#include "CoreMinimal.h"
#include "SDTCollectible.h"
#include "SDTFleeLocation.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "SDTUtils.h"
#include "DrawDebugHelpers.h"
#include "Character.h"




EBTNodeResult::Type UBTTask_FindNextPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner())) {


            FVector NextCollectible = findNextCollectible(OwnerComp, aiController);
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(aiController->GetNextPositionBBKeyID(), NextCollectible);
            return EBTNodeResult::Succeeded;

        

    }
}






FVector UBTTask_FindNextPosition::findNextCollectible(UBehaviorTreeComponent& OwnerComp, ASDTAIController* aiController) {
    float closestSqrCollectibleDistance = 18446744073709551610.f;
    ASDTCollectible* closestCollectible = nullptr;

    TArray<AActor*> foundCollectibles;
    UGameplayStatics::GetAllActorsOfClass(aiController->GetWorld(), ASDTCollectible::StaticClass(), foundCollectibles);

    // trouver un collectible aui n'est pas en cooldown
    while (foundCollectibles.Num() != 0)
    {
        int index = FMath::RandRange(0, foundCollectibles.Num() - 1);

        ASDTCollectible* collectibleActor = Cast<ASDTCollectible>(foundCollectibles[index]);
        if (!collectibleActor)
            return FVector();

        if (!collectibleActor->IsOnCooldown())
        {
            return foundCollectibles[index]->GetActorLocation();

        }
        else
        {
            foundCollectibles.RemoveAt(index);
        }
    }
}


FVector UBTTask_FindNextPosition::findBestFleeLocation(UBehaviorTreeComponent & OwnerComp, ASDTAIController * aiController) {
        float bestLocationScore = 0.f;
        ASDTFleeLocation* bestFleeLocation = nullptr;

        ACharacter* playerCharacter = UGameplayStatics::GetPlayerCharacter(aiController->GetWorld(), 0);
        if (!playerCharacter)
            return;

        for (TActorIterator<ASDTFleeLocation> actorIterator(aiController->GetWorld(), ASDTFleeLocation::StaticClass()); actorIterator; ++actorIterator)
        {
            ASDTFleeLocation* fleeLocation = Cast<ASDTFleeLocation>(*actorIterator);
            if (fleeLocation)
            {
                float distToFleeLocation = FVector::Dist(fleeLocation->GetActorLocation(), playerCharacter->GetActorLocation());

                FVector selfToPlayer = playerCharacter->GetActorLocation() - aiController->GetPawn()->GetActorLocation();
                selfToPlayer.Normalize();

                FVector selfToFleeLocation = fleeLocation->GetActorLocation() - aiController->GetPawn()->GetActorLocation();
                selfToFleeLocation.Normalize();

                float fleeLocationToPlayerAngle = FMath::RadiansToDegrees(acosf(FVector::DotProduct(selfToPlayer, selfToFleeLocation)));
                float locationScore = distToFleeLocation + fleeLocationToPlayerAngle * 100.f;

                if (locationScore > bestLocationScore)
                {
                    bestLocationScore = locationScore;
                    bestFleeLocation = fleeLocation;
                }

                DrawDebugString(aiController->GetWorld(), FVector(0.f, 0.f, 10.f), FString::SanitizeFloat(locationScore), fleeLocation, FColor::Red, 5.f, false);
            }
        }

        return bestFleeLocation->GetActorLocation();
    }
