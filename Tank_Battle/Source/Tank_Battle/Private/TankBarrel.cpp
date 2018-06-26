// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
void UTankBarrel::Elavate(float RelativeSpeed)
{ 
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElavationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()-> DeltaTimeSeconds;
	auto RawNewElavation = RelativeRotation.Pitch + ElavationChange;
	auto Elavation = FMath::Clamp<float>(RawNewElavation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elavation, 0, 0));
}

