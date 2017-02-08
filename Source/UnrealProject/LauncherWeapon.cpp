// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "LauncherWeapon.h"

void ULauncherWeapon::DoFire()
{
	Super::DoFire();
	LaunchAtDirection(FireDirection);
}

void ULauncherWeapon::LaunchAtDirection(FVector Direction)
{
	const FRotator FireRotation = Direction.Rotation();

	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = GetComponentLocation() + FireRotation.RotateVector(GunOffset);

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, SpawnLocation);
	}

	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		// spawn the projectile
		World->SpawnActor<AUnrealProjectProjectile>(SpawnLocation, FireRotation);
		UE_LOG(LogTemp, Warning, TEXT("fired"));
	}
}
