// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SoftDesignTrainingCharacter.h"
#include "SoftDesignTraining.h"
#include "SoftDesignTrainingMainCharacter.h"
#include "SDTUtils.h"
#include "DrawDebugHelpers.h"
#include "SDTCollectible.h"

int counterCollectible = 0;
int counterDeath = 0;

// affiche et met à jour l'affichage du score des agents
void updateCollectibleDisplay() {
    FString t = FString("Score: ");
    FString s = t + FString::FromInt(counterCollectible);
    GEngine->AddOnScreenDebugMessage(1, 10000.f, FColor::Red, s);
}

// affiche et met à jour jl'affichage du nombre de mort des agents
void updateDeathDisplay() {
    FString t = FString("Death: ");
    FString s = t + FString::FromInt(counterDeath);
    GEngine->AddOnScreenDebugMessage(2, 10000.f, FColor::Blue, s);

}


ASoftDesignTrainingCharacter::ASoftDesignTrainingCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

}

void ASoftDesignTrainingCharacter::BeginPlay()
{
    Super::BeginPlay();

    //initialisation des affichages
    counterCollectible = 0;
    counterDeath = 0;
    updateCollectibleDisplay();
    updateDeathDisplay();

    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ASoftDesignTrainingCharacter::OnBeginOverlap);
    m_StartingPosition = GetActorLocation();
}

void ASoftDesignTrainingCharacter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherComponent->GetCollisionObjectType() == COLLISION_DEATH_OBJECT)
    {
        SetActorLocation(m_StartingPosition);

        //mise à jour nombre de mort
        counterDeath += 1;
        updateDeathDisplay();
    }
    else if(ASDTCollectible* collectibleActor = Cast<ASDTCollectible>(OtherActor))
    {
        if (!collectibleActor->IsOnCooldown())
        {
            OnCollectPowerUp();
        }

        collectibleActor->Collect();

        //mise à jour du score
        counterCollectible += 1;
        updateCollectibleDisplay();
    }
    else if (ASoftDesignTrainingMainCharacter* mainCharacter = Cast<ASoftDesignTrainingMainCharacter>(OtherActor))
    {
        if(mainCharacter->IsPoweredUp())
            SetActorLocation(m_StartingPosition);
    }
}
