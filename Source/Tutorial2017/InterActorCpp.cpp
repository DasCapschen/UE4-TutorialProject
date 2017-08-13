// Fill out your copyright notice in the Description page of Project Settings.

#include "Tutorial2017.h"
#include "InterActorCpp.h"

AInterActorCpp::AInterActorCpp()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void AInterActorCpp::BeginPlay()
{
	Super::BeginPlay();

	for( UActorComponent* Comp : GetComponentsByClass( UMeshComponent::StaticClass() ) )
	{
		UMeshComponent* Mesh = Cast<UMeshComponent>(Comp);
		Meshes.Push(Mesh);
	}

}

void AInterActorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInterActorCpp::OnInteract_Implementation(AActor* Caller)
{
	Destroy();
}
void AInterActorCpp::StartFocus_Implementation()
{
	for( UMeshComponent* Mesh : Meshes)
	{
		Mesh->SetRenderCustomDepth(true);
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, FString::Printf(TEXT("Focus On")));
	}
}
void AInterActorCpp::EndFocus_Implementation()
{
	for( UMeshComponent* Mesh : Meshes)
	{
		Mesh->SetRenderCustomDepth(false);
		GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, FString::Printf(TEXT("Focus Off")));
	}
}
