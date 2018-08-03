// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "BoidsTarget.generated.h"

UCLASS()
class NETWORKBOIDS_API ABoidsTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidsTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void Update(float DeltaTime);

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* m_pSphereComponent;

private:
	UPROPERTY(EditDefaultsOnly)
		float m_nRadius = 2000.;

	UPROPERTY(EditDefaultsOnly)
		float m_nSpeed = 0.1;

	float m_nCurrentAngle;
	
};
