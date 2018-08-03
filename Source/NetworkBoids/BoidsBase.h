// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Actors/BoidsSpawner.h"
#include "BoidsBase.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKBOIDS_API ABoidsBase : public AGameMode
{
	GENERATED_BODY()

protected:
	void StartPlay() override;

private:
		ABoidsSpawner* m_pSpawner;

		UPROPERTY(EditAnywhere)
			TSubclassOf<ABoidsSpawner> m_pSpawnerType;
	
};
