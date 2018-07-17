// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Spin(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("IZ ME DAH TURRET BIATCH!"))
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -5, 5);
	auto ElavationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = RelativeRotation.Yaw + ElavationChange;
	auto Elavation = FMath::Clamp<float>(RawNewElavation, -360, 360); //gotta use the absolut value to make the turret go all aroundwithout restting
	SetRelativeRotation(FRotator(0, Elavation, 0));
}



