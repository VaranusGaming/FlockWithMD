// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "EngineGlobals.h"
#include "GameFramework/Actor.h"
#include "World/BoidsObstacle.h"
#include "BoidsActor.generated.h"

UCLASS()
class NETWORKBOIDS_API ABoidsActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidsActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void FollowTarget(const float DeltaTime, const FVector pPosition, const TArray<ABoidsActor*> aOtherActors, const TArray<ABoidsObstacle*> aObstacles);
	void MolecularDynamics(const float DeltaTime, const FVector pPosition, const TArray<ABoidsActor*> aOtherActors, const TArray<ABoidsObstacle*> aObstacles);

	FVector GetFlockingVelocity() { return m_pVelocity; }

private:
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* m_pSphereComponent;

	float m_nCurrentSpeed;

	UPROPERTY(EditAnywhere)
		float m_nAcceleration = 3000;

	UPROPERTY(EditAnywhere)
		float m_nFlightSpeed = 2000;

	UPROPERTY(EditAnywhere)
		float m_nTurnSpeed = 3.0f;
	
	UPROPERTY(EditAnywhere)
		float m_nSeperationStrength = 2.0f;

	UPROPERTY(EditAnywhere)
		float m_nSeperationDistance = 160;

	UPROPERTY(EditAnywhere)
		float m_nAlignmentStrength = 1.0f;

	UPROPERTY(EditAnywhere)
		float m_nAlignmentDist = 50;

	UPROPERTY(EditAnywhere)
		float m_nCohesionDistance = 100;

	UPROPERTY(EditAnywhere)
		float m_nCohesionStrength = 1.0f;

	UPROPERTY(EditAnywhere)
		float m_nAvoidanceDistance = 1000;

	UPROPERTY(EditAnywhere)
		float m_nAvoidanceStrength = 10;

	float herdDinoMass = 1.0;
	FVector herdDinoPosition, herdDinoVelocity, herdDinoOldForce, herdDinoForce;
	FVector m_pVelocity;

	FVector GetForces(const FVector pTargetPosition, const TArray<ABoidsActor*> aOtherActors, const TArray<ABoidsObstacle*> aObstacles);
	FVector CalculateSeperationVector(const TArray<ABoidsActor*> aBoids);
	FVector CalculateAlignmentVector(const TArray<ABoidsActor*> aBoids);
	FVector CalculateCohesionVector(const TArray<ABoidsActor*> aBoids);
	FVector CalculateAvoidanceVector(const TArray<ABoidsObstacle*> aObstacles);
};
