// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimationStudyGameMode.h"
#include "AnimationStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAnimationStudyGameMode::AAnimationStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
