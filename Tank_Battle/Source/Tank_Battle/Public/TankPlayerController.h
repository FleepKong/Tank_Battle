// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class TANK_BATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank * GetControlledTank() const;
	
	virtual void BeginPlay() override;

//public:

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
