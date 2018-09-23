// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ArmaInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UArmaInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class JUEGOROBOT_API IArmaInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Arma")
	void Sujetar(USceneComponent * Holder);
	virtual void Sujetar_Implementation(USceneComponent * Holder);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Arma")
	void AccionPressed();
	virtual void ActionPressed_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Arma")
	void AccionRelease();
	virtual void ActionRelease_Implementation();
	
};
