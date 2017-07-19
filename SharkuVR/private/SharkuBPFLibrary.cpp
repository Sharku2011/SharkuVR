// Fill out your copyright notice in the Description page of Project Settings.

#include "SharkuBPFLibrary.h"
#include "Engine/Engine.h"
#include "Components/WidgetComponent.h"
#include "UserWidget.h"
#include "Visibility.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"


void USharkuBPFLibrary::SetWidgetComponentActive(UObject* WorldContextObject, UWidgetComponent* WidgetComponent, bool NewActive)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, false);
	if (World)
	{
		WidgetComponent->SetCollisionEnabled((NewActive) ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);

		WidgetComponent->GetUserWidgetObject()->SetVisibility((NewActive) ? (ESlateVisibility::Visible) : (ESlateVisibility::Hidden));
	}
}

bool USharkuBPFLibrary::AttachOnSurface(UObject* WorldContextObject, USceneComponent* Target, UPrimitiveComponent* BodyToAttach)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, false);

	if (World)
	{
		FVector Origin; FVector BoxExtent; float SphereRadius;

		UKismetSystemLibrary::GetComponentBounds(BodyToAttach, Origin, BoxExtent, SphereRadius);
		FVector RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(Origin, BoxExtent);

		FVector AttachedPoint;

		float Range = BodyToAttach->GetClosestPointOnCollision(RandomPoint, AttachedPoint);

		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(AttachedPoint, RandomPoint);

		bool ReturnValue = Target->AttachToComponent(BodyToAttach, FAttachmentTransformRules::KeepWorldTransform);
		Target->SetWorldLocationAndRotation(AttachedPoint, Rot);

		return ReturnValue;
	}
	else
	{
		return false;
	}
}

bool USharkuBPFLibrary::GetBit(const int32& Bitmask, uint8 Index)
{
	return (Bitmask & (1 << Index)) != 0;
}

void USharkuBPFLibrary::SetBitOn(int32& Bitmask, uint8 Index)
{
	(Bitmask |= (1 << Index));
}

void USharkuBPFLibrary::SetBitOff(int32& Bitmask, uint8 Index)
{
	(Bitmask &= (0 << Index));
}

void USharkuBPFLibrary::SetBit(int32& Bitmask, uint8 Index, bool NewBit)
{
	(NewBit) ? (SetBitOn(Bitmask, Index)) : (SetBitOff(Bitmask, Index));
}

void USharkuBPFLibrary::SetRenderCustomDepthOn(UPrimitiveComponent* Target)
{
	if (IsValid(Target))
	{
		Target->SetRenderCustomDepth(true);
	}
}

void USharkuBPFLibrary::SetRenderCustomDepthOff(UPrimitiveComponent* Target)
{
	if (IsValid(Target))
	{
		Target->SetRenderCustomDepth(false);
	}
}

float USharkuBPFLibrary::GetDegreeFromVector2D(const FVector2D& Vec2D)
{
	float Degree = (180.f) / PI * FMath::Acos((Vec2D.GetSafeNormal() | FVector2D(1.0f, 0.0f)));
	return ((Vec2D.Y < 0.0f) ? 360.0f - Degree : Degree);
}

FLinearColor USharkuBPFLibrary::GetColorFromVector2D(const FVector2D& Vec2D)
{
	FVector2D H; float S;
	Vec2D.ToDirectionAndLength(H, S);

	float Degree = 360.0f - GetDegreeFromVector2D(Vec2D);

	return FLinearColor(Degree, S, 1.0f).HSVToLinearRGB();
}

void USharkuBPFLibrary::GetRadialPointsForAngle(TArray<FVector>& PointsArray, const float Length, const FVector Origin, const FRotator Rot, const int NumOfAngles)
{
	if (NumOfAngles <= 0)
	{
		UE_LOG(SharkuVRLog, Warning, TEXT("Parameter \"NumOfAngles\" should be an integer, bigger thans 0."))
		return;
	}

	PointsArray.Reset();
	PointsArray.Reserve(NumOfAngles);

	float X, Y;

	for (int32 i = 0; i < NumOfAngles; ++i)
	{
		FMath::SinCos(&Y, &X, (2 * PI / NumOfAngles) * (float)i);

		PointsArray.Add(Origin + (Rot.RotateVector(FVector(X, Y, 0.0f)) * Length));
	}

}