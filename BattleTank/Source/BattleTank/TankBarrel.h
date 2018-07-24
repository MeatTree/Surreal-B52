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
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "0.0", ClampMax = "20.0"))
		float ElevateMax = 10;
	UPROPERTY(EditAnywhere, Category = Setup, meta = (ClampMin = "-10.0", ClampMax = "0.0"))
		float ElevateMin = -5;
};
