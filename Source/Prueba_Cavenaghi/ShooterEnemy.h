// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterEnemy.generated.h"

UCLASS()
class PRUEBA_CAVENAGHI_API AShooterEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterEnemy();

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* MannequinMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* GunPointLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnFire();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float Health = 150.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float MaxHealth = 150.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float PointsPerDeath = 10.0f;

	void DealDamage(float DamageAmount);

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AEnemyProjectile> Projectile;
	
	class UWorld* World;

	FRotator SpawnRotation;
	FVector SpawnLocation;
};
