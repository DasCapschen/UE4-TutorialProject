// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractionInterfaceCpp.h"
#include "InterActorCpp.generated.h"

UCLASS()
class TUTORIAL2017_API AInterActorCpp : public AActor, public IInteractionInterfaceCpp
{
	GENERATED_BODY()

public:
	AInterActorCpp();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void StartFocus();
	virtual void StartFocus_Implementation() override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	void EndFocus();
	virtual void EndFocus_Implementation() override;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	TArray<UMeshComponent*> Meshes;
};
