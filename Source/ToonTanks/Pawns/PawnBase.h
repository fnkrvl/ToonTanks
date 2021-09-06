// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UHealthComponent* HealthComponent = nullptr; 

	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Projectile Type", meta= (AllowPrivateAcess = "true"))
	TAssetSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category= "Effects")
	UParticleSystem* DeathParticle = nullptr;

	UPROPERTY(EditAnywhere, Category= "Effects")
	USoundBase* DeathSound = nullptr;

	// UPROPERTY(EditAnywhere, Category= "Effects")
	// TSubclassOf<UMatineeCameraShake> DeathShake;  
	
	void RotateTurret(FVector LookAtTarget);

	void Fire();
	 
public:
	// Sets default values for this pawn's properties
	APawnBase();

	virtual void HandleDestruction();

	
	
};
