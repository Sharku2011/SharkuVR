// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrabInterface.h"
#include "HealthPointInterface.h"
#include "PhysicsEngine/DestructibleActor.h"
#include "SharkuDestructibleActor.generated.h"

/**
 * 
 */
UCLASS()
class SHARKUVR_API ASharkuDestructibleActor : public ADestructibleActor, public IGrabInterface, public IHealthPointInterface
{
	GENERATED_BODY()
	
public:



protected:

public:
	// Sets default values for this actor's properties
	ASharkuDestructibleActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
