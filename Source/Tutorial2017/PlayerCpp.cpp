// Fill out your copyright notice in the Description page of Project Settings.

#include "Tutorial2017.h"
#include "PlayerCpp.h"
#include "InteractionInterfaceCpp.h"

APlayerCpp::APlayerCpp()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceParams = FCollisionQueryParams(FName(TEXT("Trace")), true, this);

}

void APlayerCpp::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if( IsLocallyControlled() )
		HandleHighlight();
}

void APlayerCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCpp::SrvInteract);
}


void APlayerCpp::SrvInteract_Implementation()
{
	AActor* interactable = FindActorInLOS();

	if(interactable)
	{
		IInteractionInterfaceCpp* interface = Cast<IInteractionInterfaceCpp>(interactable);
		if(interface)
		{
			interface->Execute_OnInteract(interactable, this);
		}
	}
}
bool APlayerCpp::SrvInteract_Validate()
{
	return true;
}

AActor* APlayerCpp::FindActorInLOS()
{
	if(!Controller)
	{
		return nullptr;
	}

	FVector Loc;
	FRotator Rot;
	FHitResult Hit (ForceInit);
	GetController()->GetPlayerViewPoint( Loc, Rot );

	FVector Start = Loc;
	FVector End = Start + ( Rot.Vector() * InteractionDistance );

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	return Hit.GetActor();
}

void APlayerCpp::HandleHighlight()
{
	AActor* interactable = FindActorInLOS();

	if(interactable)
	{
		if(interactable != FocusedActor)
		{
			if( FocusedActor )
			{
				IInteractionInterfaceCpp* interface = Cast<IInteractionInterfaceCpp>(FocusedActor);
				if(interface)
				{
					interface->Execute_EndFocus(FocusedActor);
				}
			}
			IInteractionInterfaceCpp* interface = Cast<IInteractionInterfaceCpp>(interactable);
			if(interface)
			{
				interface->Execute_StartFocus(interactable);
			}
			FocusedActor = interactable;
		}
	}
	else
	{
		if(FocusedActor)
		{
			IInteractionInterfaceCpp* interface = Cast<IInteractionInterfaceCpp>(FocusedActor);
			if(interface)
			{
				interface->Execute_EndFocus(FocusedActor);
			}
		}
		FocusedActor = nullptr;
	}
}
