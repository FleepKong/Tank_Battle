// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComp.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComp::UTankAimingComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComp::SetBarrelReference(UTankBarrel* BarrelToSet)
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
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	)
	{
		auto TankName = GetOwner()->GetName();
		auto AimDirection = OutLaunchvelocity.GetSafeNormal();//gets direction of barrel
		MoveBarrel(AimDirection);

		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at at %s"), *TankName, *AimDirection.ToString())
	}
}

void UTankAimingComp::MoveBarrel(FVector AimDirection)
{
	//Workout difference between current barrel rotaion, AimDirection 
	auto BarrelRotaion = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation(); 
	auto DeltaRotator = AimAsRotator - BarrelRotaion;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString())
		//Move the barrel the right amount this frame
		Barrel->Elavate(5);
	//Given a max elevation speed, and the frame time
}


