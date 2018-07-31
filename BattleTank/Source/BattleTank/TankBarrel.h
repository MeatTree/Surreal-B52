// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "0.0", ClampMax = "30.0"))
	float MaxElevateDegrees = 20.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup", meta = (ClampMin = "-4.0", ClampMax = "0.0"))
	float MinElevateDegrees = -4.0f;

};
