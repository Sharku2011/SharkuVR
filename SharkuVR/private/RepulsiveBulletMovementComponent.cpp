// Fill out your copyright notice in the Description page of Project Settings.

#include "RepulsiveBulletMovementComponent.h"

FVector URepulsiveBulletMovementComponent::ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const
{
	FVector Acceleration(FVector::ZeroVector);

	Acceleration.Z += GetGravityZ();

	if (bIsRepulsiveProjectile && RepulsiveTargetComponent.IsValid())
	{
		Acceleration += ComputeRepulseAcceleration(InVelocity, DeltaTime);

	}

	if (bIsHomingProjectile && HomingTargetComponent.IsValid())
	{
		Acceleration += ComputeHomingAcceleration(InVelocity, DeltaTime);
	}

	return Acceleration;
}

FVector URepulsiveBulletMovementComponent::ComputeRepulseAcceleration(const FVector& InVelocity, float DeltaTime) const
{
	FVector DistVector = UpdatedComponent->GetComponentLocation() - RepulsiveTargetComponent->GetComponentLocation();
	FVector Norm = DistVector.GetSafeNormal();
	float DistSQ = DistVector.SizeSquared();

	FVector RepulseAcceleration = ((1 - (FMath::Clamp((RepulsiveTargetComponent->GetComponentLocation() - UpdatedComponent->GetComponentLocation()).SizeSquared() / (RepulseForceEffectiveRange * RepulseForceEffectiveRange), 0.0f, 1.0f))) * RepulsiveAccelerationMagnitude) * Norm;
	return RepulseAcceleration;
}