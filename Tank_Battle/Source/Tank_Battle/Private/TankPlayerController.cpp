// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto tank = GetControlledTank();
	if(tank)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("IM %s"), *tank->GetName())
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank does not exist!"))
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //this returns the ATank pawn
}


