// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Pistola.h"
#include "Robot.generated.h"



UCLASS()
class JUEGOROBOT_API ARobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARobot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="JuegoRobot")
	UStaticMeshComponent *Cuerpo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
	UStaticMeshComponent *Cabeza;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
	UStaticMeshComponent *ManoDerecha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
	UStaticMeshComponent *ManoIzquierda;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
	UStaticMeshComponent *PieDerecho;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
	UStaticMeshComponent *PieIzquierdo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		UCameraComponent *Camara;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JuegoRobot")
		UBoxComponent *Colision;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
		float Velocidad;

	FVector Movimiento;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	float DistanceCamera;
	void RotatePitch(float AxisValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	float VelocidadCorrer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	float VelocidadCaminar;

	void Caminar();
	void Correr();
	void DispararPressed();
	void DispararReleased();

	UFUNCTION()
	void OnBeginOverlapColision(UPrimitiveComponent * OverlapedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnEndOverlapColision(UPrimitiveComponent * OverlapedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);
	
	APistola * Pistola;


};

