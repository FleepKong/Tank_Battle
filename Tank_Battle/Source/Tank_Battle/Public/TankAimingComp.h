// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComp.generated.h"

//forward declaraction 
class UTankBarrel;

//Holds Barrels Properties

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_BATTLE_API UTankAimingComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComp();
	
	void AimAt(FVector HitLocation, float LaunchSpeed);
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//TODO add setTurrent Reference

private: 
	UTankBarrel * Barrel = nullptr;
	
	void MoveBarrel(FVector AimDirection);
		
};
