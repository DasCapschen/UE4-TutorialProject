// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCpp.generated.h"

UCLASS()
class TUTORIAL2017_API APlayerCpp : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCpp();

	UFUNCTION(Server, Reliable, WithValidation)
	void SrvInteract();

	void HandleHighlight();
	AActor* FindActorInLOS();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	AActor* FocusedActor;
	float InteractionDistance = 200.f;
	FCollisionQueryParams TraceParams;
};
