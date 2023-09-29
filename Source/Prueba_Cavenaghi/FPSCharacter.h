// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class PRUEBA_CAVENAGHI_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* HandsMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* GunMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* GunPointLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = camera)
		class UCameraComponent* FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = camera)
		float TurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = camera)
		float LookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = camera)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BulletsAmount = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BulletSpread = 2;

protected:

	void OnFire();
	void OnSecondFire();

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void Turn(float AxisValue);
	void LookUp(float AxisValue);

public:
	
	void AddPoints(float PointsToAdd)
	{
		Points += PointsToAdd;
	}
	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class ACharacterProjectile> Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	class UAnimInstance* AnimInstance;

	class UWorld* World;

	FRotator SpawnRotation;
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float Health = 100.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float Points = 0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float MaxHealth = 100.0f;

	void DealDamage(float DamageAmount);
};
