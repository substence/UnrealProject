// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "UnrealProjectProjectile.h"
#include "Weapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UWeapon : public USceneComponent
{
	GENERATED_BODY()

public:	
	//Reload time
	float ReloadTime;

	//Projectile
	class AUnrealProjectProjectile* Projectile;

	// Sets default values for this component's properties
	UWeapon();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void Fire(FVector FireDirection);

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

protected:
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ReloadTimerExpired;

	void Reload();

	void OnReloadTimerExpire();

	uint32 bIsReloaded = 1;

	virtual void DoFire();

	FVector FireDirection;
};
