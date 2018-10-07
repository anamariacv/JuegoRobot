// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemigo.h"


// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VidaMaxima = 100.0f;
	VidaActual = VidaMaxima;


}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemigo::RecibirGolpe(float Damage)
{
	VidaActual -= Damage;
	if (VidaActual <= 0)
	{
		Destroy();
	}
}

