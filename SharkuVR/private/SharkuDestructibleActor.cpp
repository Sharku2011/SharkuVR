// Fill out your copyright notice in the Description page of Project Settings.

#include "SharkuDestructibleActor.h"


// Sets default values
ASharkuDestructibleActor::ASharkuDestructibleActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ASharkuDestructibleActor::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void ASharkuDestructibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}



