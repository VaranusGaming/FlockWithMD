// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsTarget.h"


// Sets default values
ABoidsTarget::ABoidsTarget()
{
	m_nCurrentAngle = 0;

	//Add sphere component
	static ConstructorHelpers::FObjectFinder<UStaticMesh> pMesh(TEXT("/Engine/BasicShapes/Sphere"));

	m_pSphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Display Sphere"));
	m_pSphereComponent->SetStaticMesh(pMesh.Object);

	m_pSphereComponent->bOwnerNoSee = false;
	m_pSphereComponent->CastShadow = true;
	m_pSphereComponent->SetHiddenInGame(false);

	m_pSphereComponent->BodyInstance.SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RootComponent = m_pSphereComponent;
}

// Called when the game starts or when spawned
void ABoidsTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoidsTarget::Update(float DeltaTime)
{
	m_nCurrentAngle += DeltaTime * m_nSpeed;
	SetActorLocation(FVector(m_nRadius * cos(m_nCurrentAngle), m_nRadius * sin(m_nCurrentAngle), 0.1f));
}

