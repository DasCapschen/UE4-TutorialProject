// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractionInterfaceCpp.generated.h"

UINTERFACE(MinimalAPI)
class UInteractionInterfaceCpp : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TUTORIAL2017_API IInteractionInterfaceCpp
{
	GENERATED_IINTERFACE_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void OnInteract(AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void StartFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void EndFocus();
};
