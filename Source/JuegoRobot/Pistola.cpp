// Fill out your copyright notice in the Description page of Project Settings.

#include "Pistola.h"
#include "Public/UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APistola::APistola()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->SetWorldScale3D(FVector(0.25f));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/JuegoRobot/Materials/RobotMaterial.RobotMaterial'"));

	if (MeshAsset.Succeeded()) // Comprobando que el mesh haya sido encontrado
	{
		Mesh->SetStaticMesh(MeshAsset.Object); // asignado el mesh encontrado como mesh del componente Cuerpo 
		
		if (MaterialAsset.Succeeded()) // Comprobando que el material haya sido encontrado
		{
			Mesh->SetMaterial(0, MaterialAsset.Object); // asignando em material encontrado como material para el mesn del Cupepo
			
		}
	}

	MeshCanon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshCanon"));
	MeshCanon->SetupAttachment(RootComponent);
	MeshCanon->SetRelativeLocation(FVector(100.0f,0.0f,0.0f));
	MeshCanon->SetRelativeRotation(FRotator(-90.0f,0.0f,0.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshCanonAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	if (MeshCanonAsset.Succeeded()) // Comprobando que el mesh haya sido encontrado
	{
		MeshCanon->SetStaticMesh(MeshCanonAsset.Object); // asignado el mesh encontrado como mesh del componente Cuerpo 

		if (MaterialAsset.Succeeded()) // Comprobando que el material haya sido encontrado
		{
			MeshCanon->SetMaterial(0, MaterialAsset.Object); // asignando em material encontrado como material para el mesn del Cupepo

		}
	}

	PuntoDisparo = CreateDefaultSubobject<USceneComponent>(TEXT("PuntoDisparo"));
	PuntoDisparo->SetupAttachment(RootComponent);
	PuntoDisparo->SetRelativeLocation(FVector(150.0f, 0.0f, 0.0f));


	Colision = CreateDefaultSubobject<UBoxComponent>(TEXT("Colision"));
	Colision->SetupAttachment(RootComponent);
	Colision->InitBoxExtent(FVector(0.25f));

}

// Called when the game starts or when spawned
void APistola::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APistola::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APistola::Sujetar_Implementation(USceneComponent * Holder)
{
	AttachToComponent(Holder, FAttachmentTransformRules::KeepRelativeTransform);
	SetActorRelativeLocation(FVector(0.0f));
	SetActorRelativeRotation(FRotator(0.0f));


}

