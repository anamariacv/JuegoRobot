// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ArmaInterface.h"
#include "Pistola.generated.h"


UCLASS()
class JUEGOROBOT_API APistola : public AActor, public IArmaInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APistola();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Sujetar_Implementation(USceneComponent * Holder) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	UStaticMeshComponent *Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	UStaticMeshComponent *MeshCanon;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	UBoxComponent *Colision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "JuegoRobot")
	USceneComponent *PuntoDisparo;


	
};
