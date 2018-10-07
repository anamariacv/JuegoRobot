// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Components/SphereComponent.h"
#include "BalaLaser.generated.h"

/**
 * 
 */
UCLASS()
class JUEGOROBOT_API ABalaLaser : public AProyectil
{
	GENERATED_BODY()
	
	public:
		// Sets default values for this actor's properties
		ABalaLaser();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;
		virtual void Disparar() override;
	
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		float Poder;
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		float Velocidad;
				
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		UStaticMeshComponent *Bala;
		
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		USphereComponent *Colision;


};
