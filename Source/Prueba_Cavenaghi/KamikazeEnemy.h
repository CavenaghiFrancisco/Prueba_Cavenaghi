// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KamikazeEnemy.generated.h"

UCLASS()
class PRUEBA_CAVENAGHI_API AKamikazeEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKamikazeEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageCollision;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& Hit);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float Health = 150.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float MaxHealth = 150.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float PointsPerDeath = 20.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		float DamageValue = 10.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		class UParticleSystemComponent* ParticleSystem;
	

	void DealDamage(float DamageAmount);
};
