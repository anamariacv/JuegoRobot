// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemigo.generated.h"

UCLASS()
class JUEGOROBOT_API AEnemigo : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
		float VidaMaxima;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
		float VidaActual;

	UFUNCTION(BlueprintCallable, Category = "JuegoRobot")
		void RecibirGolpe(float Damage);
};
