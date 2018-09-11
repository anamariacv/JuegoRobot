// Fill out your copyright notice in the Description page of Project Settings.

#include "JuegoRobotGameModeBase.h"
#include "Public/UObject/ConstructorHelpers.h"

AJuegoRobotGameModeBase::AJuegoRobotGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;

	
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("Class'/Script/JuegoRobot.JuegoRobotGameModeBase'")); //en C++ 
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("BlueprintGeneratedClass'/Game/JuegoRobot/Blueprints/GameModes/JuegoRobotGameModeBaseBP.JuegoRobotGameModeBaseBP_C'"));

	if (PlayerPawnClass.Class != NULL)
	{

		DefaultPawnClass = PlayerPawnClass.Class;

	}
}


AJuegoRobotGameModeBase::AJuegoRobotGameModeBase(const FObjectInitializer & ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;


	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("Class'/Script/JuegoRobot.JuegoRobotGameModeBase'")); //en C++ 
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClass(TEXT("BlueprintGeneratedClass'/Game/JuegoRobot/Blueprints/GameModes/JuegoRobotGameModeBaseBP.JuegoRobotGameModeBaseBP_C'"));

	if (PlayerPawnClass.Class != NULL)
	{

		DefaultPawnClass = PlayerPawnClass.Class;

	}
}







