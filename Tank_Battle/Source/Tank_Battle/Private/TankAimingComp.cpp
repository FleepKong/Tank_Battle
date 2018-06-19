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

void UTankAimingComp::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if(!Barrel)return;

	FVector OutLaunchvelocity;//OUT PARAM
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
		//Calculate the OutLaunchVelocity


		if (UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchvelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0.f,
			0.f,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	)
	{
		auto TankName = GetOwner()->GetName();
		auto AimDirection = OutLaunchvelocity.GetSafeNormal();//gets direction of barrel
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at at %s"), *TankName, *AimDirection.ToString())
	}
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

