// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsSpawner.h"


// Sets default values
ABoidsSpawner::ABoidsSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ABoidsSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	runningTime = 0.0;

	UE_LOG(LogTemp, Display, TEXT("Spawner created"));

	if (m_pTargetType == nullptr)
		return;

	m_pTarget = GetWorld()->SpawnActor<ABoidsTarget>(m_pTargetType);

	if (m_pObstacleType == nullptr)
		return;

	ABoidsObstacle* pObstacle = GetWorld()->SpawnActor<ABoidsObstacle>(m_pObstacleType, FVector(1900, 0, 0), FRotator(0, 0, 0));
	m_aObstacles.Add(pObstacle);
}

// Called every frame
void ABoidsSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_pActorType != nullptr)
	{
		m_nTimeSinceSpawn += DeltaTime;

		if (m_nTimeSinceSpawn > m_nTimeBetweenActor && m_aActors.Num() < m_nTotalActors)
		{
			CreateActor();
			m_nTimeSinceSpawn = 0;
		}
	}

	m_pTarget->Update(DeltaTime);
	FVector pTargetPosition = m_pTarget->GetActorLocation();

//	if (int(runningTime)%60<30) {
	if (runningTime<200*DeltaTime) {
		for (int i = 0; i < m_aActors.Num(); i++)
			m_aActors[i]->FollowTarget(DeltaTime, pTargetPosition, m_aActors, m_aObstacles);
	} else {
		for (int i = 0; i < m_aActors.Num(); i++)
			m_aActors[i]->MolecularDynamics(DeltaTime, pTargetPosition, m_aActors, m_aObstacles);
	}
	
	runningTime += DeltaTime;
}

void ABoidsSpawner::CreateActor()
{
	ABoidsActor* pActor = GetWorld()->SpawnActor<ABoidsActor>(m_pActorType);
	m_aActors.Add(pActor);
}

