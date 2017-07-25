// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumLibrary.h"
#include "Components/SceneComponent.h"
#include "GrabberComponent.generated.h"

class AVRHand;
class AVRPawn;
class UMeshComponent;
class UMaterialInterface;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberBeginInteractionSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberEndInteractionSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberGrabbedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabberDroppedSignature);

UCLASS( ClassGroup=(GrabInterface), meta=(BlueprintSpawnableComponent) )
class SHARKUVR_API UGrabberComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Interaction Signature 시작

	UPROPERTY(BlueprintAssignable, Category = "GrabInterface")
	FGrabberBeginInteractionSignature OnBeginInteraction;

	UPROPERTY(BlueprintAssignable, Category = "GrabInterface")
	FGrabberEndInteractionSignature OnEndInteraction;

	UPROPERTY(BlueprintAssignable, Category = "GrabInterface")
	FGrabberGrabbedSignature OnGrabbed;

	UPROPERTY(BlueprintAssignable, Category = "GrabInterface")
	FGrabberDroppedSignature OnDropped;

	// Interaction Signature 끝

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	AVRHand* GrabbingHand;

	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly)
	UMeshComponent* GlowMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint32 bCanGrabbed : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint32 bIsGlowing : 1;

protected:
	// 손에 쥐게 할 타겟 컴포넌트
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "GrabInterface")
	USceneComponent* TargetComponent;

	// 나중에 Weapon Interface 작업하면서 카테고리 변경할 것"
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GrabInterface")
	float DamageMultiplier;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GrabInterface")
	float DamageBonus;

	// 잡는 타입
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GrabInterface")
	EGrabType GrabType;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "GrabInterface")
	FName ObjectName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GrabInterface")
	uint32 bCanTwoHanded : 1;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GrabInterface")
	uint32 bCanSmash : 1;

	UPROPERTY(BlueprintReadOnly, Category = "GrabInterface")
	uint32 bIsTwoHandGrabbed : 1;

	UPROPERTY(BlueprintReadOnly, Category = "GrabInterface")
	uint32 bIsTargetPrimitive : 1;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "GrabInterface")
	uint32 bIsGrabbed : 1;

public:
	// Sets default values for this component's properties
	UGrabberComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "GrabInterface")
	void GrabberSetup();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void Grab(AVRHand* NewHand);
	virtual void Grab_Implementation(AVRHand* NewHand);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void Drop();
	virtual void Drop_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GrabInterface")
	void SetGlow(bool NewBool, UMaterialInterface* GlowMat = nullptr);
	virtual void SetGlow_Implementation(bool NewBool, UMaterialInterface* GlowMat = nullptr);

	//////////

	UFUNCTION()
	void OnPrimTargetCompBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPrimTargetCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnPrimTargetCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//////////


	FORCEINLINE EGrabType GetGrabType() const { return GrabType; };
	FORCEINLINE void SetGrabType(EGrabType NewGrabType) { GrabType = NewGrabType; };
	FORCEINLINE class USceneComponent* GetTargetComponent() const { return TargetComponent; };
	FORCEINLINE class UPrimitiveComponent* GetPrimTargetComponent() const { return ((UPrimitiveComponent*)TargetComponent); };
	FORCEINLINE FName GetObjectName() const { return ObjectName; };
	FORCEINLINE bool GetCanTwoHanded() const { return bCanTwoHanded; };
	FORCEINLINE bool GetCanSmash() const { return bCanSmash; };
	FORCEINLINE bool GetIsTwoHandGrabbed() const { return bIsTwoHandGrabbed; };
	FORCEINLINE bool GetIsTargetPrimitive() const { return bIsTargetPrimitive; };
	FORCEINLINE bool GetIsRootComponent(USceneComponent* TargetComp) const { return TargetComp == TargetComp->GetOwner()->GetRootComponent(); };
	FORCEINLINE bool GetIsGrabbed() const { return bIsGrabbed; };
	FORCEINLINE bool GetIsGlowing() const { return bIsGlowing; };

protected:	
	// Called when the game starts
	virtual void BeginPlay() override;



	


};
