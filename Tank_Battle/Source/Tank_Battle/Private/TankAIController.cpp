// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




 void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AiTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s is pointing to Player %s"), *(AiTank->GetName()), *GetPlayerTank()->GetTargetLocation().ToString()) same as bottom,  this my my attempt
		
		AiTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
		AiTank->Fire();//TODO Dont fire every frame
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}





