// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot.h"
#include "Public/UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"



// Sets default values
ARobot::ARobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Origen"));
	Cuerpo = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Cuerpo"));
	Cuerpo->SetupAttachment(RootComponent);
	Cuerpo->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	Cabeza = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Cabeza"));
	Cabeza->SetupAttachment(Cuerpo);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CuerpoAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/JuegoRobot/Materials/RobotMaterial.RobotMaterial'"));

	if (CuerpoAsset.Succeeded()) 
	{
		Cuerpo->SetStaticMesh(CuerpoAsset.Object);
		if (MaterialAsset.Succeeded())
		{
			Cuerpo->SetMaterial(0, MaterialAsset.Object);
		}
	}

}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

