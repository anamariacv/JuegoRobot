// Fill out your copyright notice in the Description page of Project Settings.

#include "BalaLaser.h"
#include "Public/UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "Engine/StaticMesh.h"

// Sets default values
ABalaLaser::ABalaLaser()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocidad = 4000.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/JuegoRobot/Materials/BlueLaserMaterial.BlueLaserMaterial'"));

	Bala = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bala"));
	RootComponent = Bala;
	Bala->SetWorldScale3D(FVector(0.15f));
	if (MeshAsset.Succeeded())
	{
		Bala->SetStaticMesh(MeshAsset.Object);

		if (MaterialAsset.Succeeded())
		{
			Bala->SetMaterial(0,MaterialAsset.Object);
		}

	}

	Colision = CreateDefaultSubobject<USphereComponent>(TEXT("Colision"));
	Colision->SetupAttachment(RootComponent);
	Colision->InitSphereRadius(7.5f);


}

// Called when the game starts or when spawned
void ABalaLaser::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABalaLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDisparado)
	{
		SetActorLocation(GetActorLocation() + GetActorForwardVector() * Velocidad * DeltaTime);
	}

}

void ABalaLaser::Disparar()
{
	Super::Disparar();

}




