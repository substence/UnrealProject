// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "Shotgun.h"

void UShotgun::DoFire()
{
	for (size_t i = 0; i < ShotCount; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("rotation %f"), FireDirection.Rotation().Yaw);
		FRotator rotator = FireDirection.Rotation();
		rotator.Yaw += 10.0f;
		FireDirection.Rotation() = rotator;
		UE_LOG(LogTemp, Warning, TEXT("	altered %f"), FireDirection.Rotation().Yaw);
		//FVector direction = FireDirection.RotateAngleAxis(FMath::Rand() * 10.0f, FireDirection.ForwardVector);// FireDirection + ;
		LaunchAtDirection(FireDirection);
	}
}
