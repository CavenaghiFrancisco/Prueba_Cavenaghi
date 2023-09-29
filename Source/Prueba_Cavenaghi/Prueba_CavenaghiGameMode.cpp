// Copyright Epic Games, Inc. All Rights Reserved.

#include "Prueba_CavenaghiGameMode.h"
#include "Prueba_CavenaghiHUD.h"
#include "Prueba_CavenaghiCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrueba_CavenaghiGameMode::APrueba_CavenaghiGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APrueba_CavenaghiHUD::StaticClass();
}
