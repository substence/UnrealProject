// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "Weapon.h"


// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

#pragma region UPROPERTIES
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	GunOffset = FVector(90.f, 0.f, 0.f);

	ReloadTime = 1.0f;
#pragma endregion
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeapon::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UWeapon::Fire(FVector Direction)
{
	if (!bIsReloaded)
	{
		return;
	}

	if (Direction.SizeSquared() <= 0.0f)
	{
		return;
	}

	FireDirection = Direction;

	UE_LOG(LogTemp, Warning, TEXT("attempting firing"));

	DoFire();
	Reload();
}

void UWeapon::DoFire()
{

}

void UWeapon::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reloading"));

	bIsReloaded = false;

	UWorld* const World = GetWorld();

	if (World != NULL)
	{
		World->GetTimerManager().SetTimer(TimerHandle_ReloadTimerExpired, this, &UWeapon::OnReloadTimerExpire, ReloadTime);
	}
}

void UWeapon::OnReloadTimerExpire()
{
	bIsReloaded = true;
	UE_LOG(LogTemp, Warning, TEXT("Reload Complete"));
}

