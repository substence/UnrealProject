// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UnrealProject.h"
#include "UnrealProjectGameMode.h"
#include "UnrealProjectPawn.h"

AUnrealProjectGameMode::AUnrealProjectGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AUnrealProjectPawn::StaticClass();
}

