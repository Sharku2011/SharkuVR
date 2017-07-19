// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "RepulsiveBulletMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Movement, meta = (BlueprintSpawnableComponent, DisplayName = "Repulsive Projectile Movement", ShortTooltip = "Projectile movement can homing and repulsed"))
class SHARKUVR_API URepulsiveBulletMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()
	
public:
		
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Repulse)
	uint32 bIsRepulsiveProjectile : 1;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = Repulse)
	TWeakObjectPtr<USceneComponent> RepulsiveTargetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Repulse)
	float RepulsiveAccelerationMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Repulse)
	float RepulseForceEffectiveRange;

public:

protected:
	virtual FVector ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const override;
	
	virtual FVector ComputeRepulseAcceleration(const FVector& InVelocity, float DeltaTime) const;

};
