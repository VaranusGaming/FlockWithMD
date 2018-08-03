// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsPlayerPawn.h"


// Sets default values
ABoidsPlayerPawn::ABoidsPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoidsPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoidsPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoidsPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

