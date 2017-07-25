// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

class UMotionControllerComponent;

UCLASS()
class SHARKUVR_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	

protected:


public:
	// Sets default values for this character's properties
	AVRCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
