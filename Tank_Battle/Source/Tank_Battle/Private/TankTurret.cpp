// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Spin(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("IZ ME DAH TURRET BIATCH!"))
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElavationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = RelativeRotation.Yaw + ElavationChange;
	auto Elavation = FMath::Clamp<float>(RawNewElavation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(0, Elavation, 0));
}



