// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto tank = GetControlledTank();
	auto AIPoint = GetPlayerTank();

	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is pointing to Player %s"), *tank->GetName(), *AIPoint->GetName())
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank does not exist!"))
	}


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerPawn) { return nullptr;}
	return PlayerPawn;

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //this returns the ATank pawn
}



