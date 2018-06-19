// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComp.h"


// Sets default values for this component's properties
UTankAimingComp::UTankAimingComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComp::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComp::AimAt(FVector HitLocation)
{
	auto BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s from %s"), *(GetOwner()->GetName()), *HitLocation.ToString(), *BarrelLocation.ToString())
}

// Called when the game starts
void UTankAimingComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

