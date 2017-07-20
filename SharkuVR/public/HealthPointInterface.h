// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthPointInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHealthPointInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHARKUVR_API IHealthPointInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	////// HealthPointInterface 선언부

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HealthPointInterface")
		float GetCurrentHP() const;
	//virtual float GetCurrentHP_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HealthPointInterface")
		float GetMaxHP() const;
	//virtual float GetMaxHP_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HealthPointInterface")
		float GetPercentageHP() const;
	//virtual float GetPercentageHP_Implementation() const;

	////// HealthPointInterface 선언부 끝

	/*

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthPointInterface")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthPointInterface")
	float CurrentHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HealthPointInterface")
	float PercentageHP;

	*/

protected:
	////// HealthPointInterface 선언부

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HealthPointInterface")
		bool ModifyHP(const float& NewHP);
	//virtual bool ModifyHP_Implementation(const float& NewHP);

	////// HealthPointInterface 선언부 끝

	
};
