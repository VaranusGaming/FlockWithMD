// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsObstacle.h"


// Sets default values
ABoidsObstacle::ABoidsObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
void ABoidsObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoidsObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

