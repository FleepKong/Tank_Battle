// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComp.h"


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComp->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComp->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	
	UE_LOG(LogTemp, Warning, TEXT("BANG"))
	
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No Need to protect points as added at construction
	TankAimingComp = CreateDefaultSubobject<UTankAimingComp>(FName("Aiming Componenet"));
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComp->AimAt(HitLocation, LaunchSpeed);
}

