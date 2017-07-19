// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GrabberComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberBeginInteractionSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberEndInteractionSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberGrabbedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberDroppedSignature);

UCLASS( ClassGroup=(GrabInterface), meta=(BlueprintSpawnableComponent) )
class SHARKUVR_API UGrabberComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabberComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
