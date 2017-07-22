// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SharkuVR.h"
#include "EnumLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SharkuBPFLibrary.generated.h"

class UWidgetComponent;

/**
 * 
 */
UCLASS()
class SHARKUVR_API USharkuBPFLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext), Category = "SharkuBPFLibrary|Widget")
	static void SetWidgetComponentActive(UObject* WorldContextObject, UWidgetComponent* WidgetComponent, bool NewActive);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext), Category = "SharkuBPFLibrary|Transform")
	static bool AttachOnSurface(UObject* WorldContextObject, USceneComponent* Target, UPrimitiveComponent* BodyToAttach);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Bitmask")
	static bool GetBit(const int32& Bitmask, uint8 Index);

	// UPARAM(ref) 를 파라미터에 붙여주면 블루프린트의 레퍼런스로 전달 과 같은 효과. https://wiki.unrealengine.com/UPARAM 참조
	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Bitmask")
	static void SetBitOn(UPARAM(ref) int32& Bitmask, uint8 Index);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Bitmask")
	static void SetBitOff(UPARAM(ref) int32& Bitmask, uint8 Index);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Bitmask")
	static void SetBit(UPARAM(ref) int32& Bitmask, uint8 Index, bool NewBit);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Rendering")
	static void SetRenderCustomDepthOn(UPrimitiveComponent* Target);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Rendering")
	static void SetRenderCustomDepthOff(UPrimitiveComponent* Target);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SharkuBPFLibrary|Vector2D|Math")
	static float GetDegreeFromVector2D(const FVector2D& Vec2D);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SharkuBPFLibrary|Color")
	static FLinearColor GetColorFromVector2D(const FVector2D& Vec2D);

	UFUNCTION(BlueprintPure, Category = "SharkuBPFLibrary|Math|Transform")
	static void GetRadialPointsForAngle(TArray<FVector>& PointsArray, const float Length, const FVector Origin, const FRotator Rot, const int NumOfAngles = 3);
	
	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Random")
	static void Shuffle() {};

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Math", meta = (DisplayName = "CalculateWithFlowCheck(float)", ExpandEnumAsExecs = "result"))
	static bool FCalcVarWithFlowCheck(UPARAM(ref) float& Var, const float& ModAmount, ECheckFlowResult& result);

	UFUNCTION(BlueprintCallable, Category = "SharkuBPFLibrary|Math", meta = (DisplayName = "CalculateWithFlowCheck(int)", ExpandEnumAsExecs = "result"))
	static bool CalcVarWithFlowCheck(UPARAM(ref) int& Var, const int& ModAmount, ECheckFlowResult& result);
};