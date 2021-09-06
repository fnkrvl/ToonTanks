// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()
	
protected:
	// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UCapsuleComponent* CapsuleComp = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	USceneComponent* ProjectileSpawnPoint = nullptr;

	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Projectile Type", meta= (AllowPrivateAcess = "true"))
	TAssetSubclassOf<AProjectileBase> ProjectileClass;

	void RotateTurret(FVector LookAtTarget);

	void Fire();
	 
public:
	// Sets default values for this pawn's properties
	APawnBase();

	virtual void HandleDestruction();

	
	
};
