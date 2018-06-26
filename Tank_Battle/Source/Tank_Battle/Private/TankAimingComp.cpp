// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComp.h"
#include "TankBarrel.h"
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
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace //comment this if you want to initiate the unreal bug (we need this)
		)
	)
	{
		
		auto AimDirection = OutLaunchvelocity.GetSafeNormal();//gets direction of barrel
		MoveBarrel(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f:Aim Solution Found!"), Time)
	}
		else
		{
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f: No Aim solve found"), Time)
		}
}

void UTankAimingComp::MoveBarrel(FVector AimDirection)
{
	//Workout difference between current barrel rotaion, AimDirection 
	auto BarrelRotaion = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation(); 
	auto DeltaRotator = AimAsRotator - BarrelRotaion;
	
	Barrel->Elavate(DeltaRotator.Pitch);
}


