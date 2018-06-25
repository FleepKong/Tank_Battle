// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




 void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiTank = GetControlledTank();

	if (GetPlayerTank())
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s is pointing to Player %s"), *(AiTank->GetName()), *GetPlayerTank()->GetTargetLocation().ToString()) same as bottom,  this my my attempt
		
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready
	}
}

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





