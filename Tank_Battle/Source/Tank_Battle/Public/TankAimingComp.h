// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_BATTLE_API UTankAimingComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComp();
	
	void AimAt(FVector HitLocation, float LaunchSpeed);
	
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	//TODO add setTurrent Reference

private: 
	UStaticMeshComponent * Barrel = nullptr;
	
	void MoveBarrel(FVector AimDirection);
		
};
