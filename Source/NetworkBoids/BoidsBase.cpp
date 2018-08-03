// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsBase.h"

void ABoidsBase::StartPlay()
{
	Super::StartPlay();

	UE_LOG(LogTemp, Display, TEXT("Spawning spawner 2"));

	m_pSpawner = GetWorld()->SpawnActor<ABoidsSpawner>(m_pSpawnerType);
}