// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.generated.h"


class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

	
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UProjectileMovementComponent* ProjectileMovement = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UStaticMeshComponent* ProjectileMesh = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components", meta= (AllowPrivateAcess = "true"))
	UParticleSystemComponent* ParticleTrail = nullptr;
	
	// VARIABLES
	UPROPERTY(EditDefaultsOnly, Category= "Damage")
	TSubclassOf<UDamageType> DamegeType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Move", meta= (AllowPrivateAcess = "true"))
	float MovementSpeed = 1300.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Damage", meta= (AllowPrivateAcess = "true"))
	float Damage = 50.f;
	UPROPERTY(EditAnywhere, Category= "Effects")
	UParticleSystem* HitParticle = nullptr;
	UPROPERTY(EditAnywhere, Category= "Effects")
	USoundBase* HitSound = nullptr;
	UPROPERTY(EditAnywhere, Category= "Effects")
	USoundBase* LaunchSound = nullptr;
	// UPROPERTY(EditAnywhere, Category= "Effects")
	// TSubclassOf<UMatineeCameraShake> HitShake; 
	
	// FUNCTIONS
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitCompo, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
