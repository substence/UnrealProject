// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "LauncherWeapon.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API ULauncherWeapon : public UWeapon
{
	GENERATED_BODY()
protected:
	void DoFire();
	void LaunchAtDirection(FVector Direction);
};
