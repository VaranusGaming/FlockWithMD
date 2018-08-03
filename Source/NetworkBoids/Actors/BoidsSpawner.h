// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "BoidsActor.h"
#include "World/BoidsTarget.h"
#include "World/BoidsObstacle.h"
#include "BoidsSpawner.generated.h"

UCLASS()
class NETWORKBOIDS_API ABoidsSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidsSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABoidsActor> m_pActorType;

	float runningTime;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABoidsTarget> m_pTargetType;

	ABoidsTarget * m_pTarget;
	TArray<ABoidsActor*> m_aActors;
	TArray<ABoidsObstacle*> m_aObstacles;

	UPROPERTY(EditDefaultsOnly)
		float m_nTotalActors = 50;

	UPROPERTY(EditDefaultsOnly)
		float m_nTimeBetweenActor = 0.001f;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABoidsObstacle> m_pObstacleType;

	float m_nTimeSinceSpawn;

	void CreateActor();
};
