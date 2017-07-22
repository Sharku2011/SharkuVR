// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabberComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VictoryBPFunctionLibrary.h"
#include "VRHand.h"

// Sets default values for this component's properties
UGrabberComponent::UGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	GrabType = EGrabType::GT_ATTACH;
	ObjectName = TEXT("Default");

	DamageMultiplier = 1.0f;
	DamageBonus = 0.0f;
}


void UGrabberComponent::GrabberSetup()
{
	TargetComponent = GetAttachParent();

	bIsTargetPrimitive = IsValid(Cast<UPrimitiveComponent>(TargetComponent));

	if (bIsTargetPrimitive)
	{
		GetPrimTargetComponent()->OnComponentHit.AddDynamic(this, &UGrabberComponent::OnPrimTargetCompHit);

		GetPrimTargetComponent()->SetCustomDepthStencilValue(252);
		if (GrabType == EGrabType::GT_ATTACH)
		{
			GetPrimTargetComponent()->OnComponentBeginOverlap.AddDynamic(this, &UGrabberComponent::OnPrimTargetCompBeginOverlap);
		}

		if (GrabType == EGrabType::GT_HANDLE)
		{
			ObjectName = TEXT("Default");
		}

		if (GrabType == EGrabType::GT_DRAWER)
		{
			GetPrimTargetComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Ignore);

			SetWorldLocation(GetPrimTargetComponent()->GetCenterOfMass());
		}
	}
}

void UGrabberComponent::Grab_Implementation(AVRHand* NewHand)
{

}

void UGrabberComponent::Drop_Implementation()
{

}

void UGrabberComponent::SetGlow_Implementation(bool NewBool, UMaterialInterface* GlowMat)
{

}

// Called when the game starts
void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GrabberSetup();
}


// Called every frame
void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrabberComponent::OnPrimTargetCompBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*
	if (OtherActor->IsA(AVRHand::StaticClass()))
	{
		return;
	}

	FVector OverlapedCompHitLocation;
	FVector OtherCompHitLocation;

	UVictoryBPFunctionLibrary::GetDistanceBetweenComponentSurfaces(OverlappedComp, OtherComp, OverlapedCompHitLocation, OtherCompHitLocation);

	FVector HitDirection = (OtherCompHitLocation - OverlapedCompHitLocation).GetSafeNormal();

	FHitResult TraceHit;

	FCollisionQueryParams CQP;

	OverlappedComp->LineTraceComponent(TraceHit, OverlapedCompHitLocation, OtherCompHitLocation + HitDirection, CQP);

	float Damage = 0;

	if (bIsGrabbed)
	{
		Damage = ((GrabbingHand->GetVrVelocity() / 400.0f).SizeSquared() * DamageMultiplier * GrabbingHand->BaseDamage) + DamageBonus;

		GrabbingHand->DrawHitEffect(Damage, TraceHit);
	}

	UGameplayStatics::ApplyDamage(OtherActor, Damage * 0.9f, nullptr, OverlappedComp->GetOwner(), nullptr);
	UGameplayStatics::ApplyPointDamage(OtherActor, Damage * 0.1f, HitDirection, TraceHit, nullptr, OverlappedComp->GetOwner(), nullptr);

	if (OtherComp->IsAnySimulatingPhysics())
	{
		OtherComp->AddImpulse(HitDirection * Damage, TraceHit.BoneName, true);
	}


	*/
}

void UGrabberComponent::OnPrimTargetCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UKismetSystemLibrary::PrintString(TargetComponent, TEXT("EndOverlap"));




}

void UGrabberComponent::OnPrimTargetCompHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	/*
	ASharkuDestructibleActor* DestActor = Cast<ADestructibleBase>(OtherActor);
	UDestructibleMorpherComponent* DestMorpherComp = Cast<UDestructibleMorpherComponent>(OtherComp);

	if (IsValid(OtherActor))
	{
		float Damage;

		FVector HitVelocity = HitComponent->GetPhysicsLinearVelocityAtPoint(Hit.Location);

		Damage = ((HitVelocity / 400.0f).SizeSquared()  * DamageMultiplier * GetPrimTargetComponent()->GetMass()) + DamageBonus;

		if (FMath::IsNearlyEqual(Damage, 0.0f, 0.001f))
		{
			return;
		}

		if (DestActor && DestActor->GetbIsBroken())
		{
			UGameplayStatics::ApplyPointDamage(DestActor, Damage, HitVelocity.GetSafeNormal(), Hit, UGameplayStatics::GetPlayerController(this, 0), TargetComponent->GetOwner(), nullptr);

			return;
		}
		else
		{
			if (DestMorpherComp)
			{
				FDamageEvent DamageEvent;
				DestMorpherComp->ReceiveComponentDamage(Damage, DamageEvent, UGameplayStatics::GetPlayerController(this, 0), TargetComponent->GetOwner());

				return;
			}
			else
			{
				UGameplayStatics::ApplyPointDamage(OtherActor, Damage, HitVelocity.GetSafeNormal(), Hit, UGameplayStatics::GetPlayerController(this, 0), TargetComponent->GetOwner(), nullptr);
				//UKismetSystemLibrary::PrintString(TargetComponent, Hit.BoneName.ToString().Append(FString::Printf(TEXT(" %f Applied"), Damage)));
				return;
			}
		}
	}
	*/
}