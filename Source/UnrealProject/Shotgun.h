// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LauncherWeapon.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UShotgun : public ULauncherWeapon
{
	GENERATED_BODY()
public:
	float Spread = 10.0f;
	int ShotCount = 10;
protected:
	void DoFire();
};
