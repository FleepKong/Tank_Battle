// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//forward declaractions
class ATank;

/**
 * 
 */
UCLASS()
class TANK_BATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay();	
protected:
	
};
