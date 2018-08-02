// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds barrel properties and elevate method
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	uint8 GetCurrentAmmo() const;
	
	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 8000;	// Starting value of 800m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	uint8 CurrentAmmo = 5;

	void MoveBarrelTowards(FVector AimDirection);

	bool bIsBarrelMoving();

	FVector AimDirection;

	double LastFireTime = 0;
};
