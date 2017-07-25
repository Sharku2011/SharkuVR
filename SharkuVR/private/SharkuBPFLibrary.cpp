// Fill out your copyright notice in the Description page of Project Settings.

#include "SharkuBPFLibrary.h"
#include "Engine/Engine.h"
#include "Components/WidgetComponent.h"
#include "UserWidget.h"
#include "Visibility.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include <bitset>


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

FString USharkuBPFLibrary::GetBitSet(const int32& Bitset)
{
	return FString(std::bitset<32>(Bitset).to_string().c_str());
}

void USharkuBPFLibrary::SetBitOn(UPARAM(ref) int32& Bitmask, uint8 Index)
{
	(Bitmask |= (1 << Index));
}

void USharkuBPFLibrary::SetBitOff(UPARAM(ref) int32& Bitmask, uint8 Index)
{
	(Bitmask &= (0 << Index));
}

void USharkuBPFLibrary::SetBit(UPARAM(ref) int32& Bitmask, uint8 Index, bool NewBit)
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

bool USharkuBPFLibrary::FCalcVarWithFlowCheck(UPARAM(ref) float& Var, const float& ModAmount, ECheckFlowResult& result)
{
	float CalcResult = Var + ModAmount;

	result = ECheckFlowResult::Pass;

	if (!(FIsNegative(Var) ^ FIsNegative(ModAmount)))
	{
		if (FIsNegative(CalcResult) != FIsNegative(Var))
		{
			if (FIsNegative(CalcResult))
			{
				result = ECheckFlowResult::Underflow;
			}
			else
			{
				result = ECheckFlowResult::Overflow;
			}
			return true;
		}
	}
	Var = CalcResult;
	return false;
}

bool USharkuBPFLibrary::CalcVarWithFlowCheck(UPARAM(ref) int& Var, const int& ModAmount, ECheckFlowResult& result)
{
	int CalcResult = Var + ModAmount;

	result = ECheckFlowResult::Pass;

	if (!(IsNegative(Var) ^ IsNegative(ModAmount)))
	{
		if (IsNegative(CalcResult) != IsNegative(Var))
		{
			if (IsNegative(CalcResult))
			{
				result = ECheckFlowResult::Underflow;
			}
			else
			{
				result = ECheckFlowResult::Overflow;
			}
			return true;
		}
	}
	Var = CalcResult;
	return false;
}

bool USharkuBPFLibrary::FIsNegative(const float& Data)
{
	// 실수를 비트 변경 없이 그대로 int값으로 변환
	union FloatInt
	{
		float input;
		int output;
	} temp;

	temp.input = Data;

	return std::bitset<32>(temp.output).test(31);
}

bool USharkuBPFLibrary::IsNegative(const int32& Data)
{
	return (Data & (1 << 31)) != 0;
	//return std::bitset<32>(Data).test(31);
}