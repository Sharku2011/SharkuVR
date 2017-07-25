﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "GrabInterface.generated.h"

class UMaterialInterface;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGrabInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHARKUVR_API IGrabInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	////// GrabInterface 선언부

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void Grab(class AVRHand* GrabbingHand);
	virtual void Grab_Implementation(class AVRHand* GrabbingHand) {};

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void Drop();
	virtual void Drop_Implementation() {};

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void InteractionOn();
	virtual void InteractionOn_Implementation() {};

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void InteractionOff();
	virtual void InteractionOff_Implementation() {};

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void SetGlow(bool NewBool, UMaterialInterface* GlowMat = nullptr);
	virtual void SetGlow_Implementation(bool NewBool, UMaterialInterface* GlowMat = nullptr) {};
	
	////// GrabInterface 선언부 끝

};
