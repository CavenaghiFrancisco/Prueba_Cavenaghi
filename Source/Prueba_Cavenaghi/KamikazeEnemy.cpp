// Fill out your copyright notice in the Description page of Project Settings.


#include "KamikazeEnemy.h"

#include "Components/BoxComponent.h"
#include "FPSCharacter.h"
#include "MovieSceneSequenceID.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AKamikazeEnemy::AKamikazeEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Collision"));
	DamageCollision->SetupAttachment(RootComponent);

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
}

// Called when the game starts or when spawned
void AKamikazeEnemy::BeginPlay()
{
	Super::BeginPlay();

	MaxHealth = Health;
	
	DamageCollision->OnComponentBeginOverlap.AddDynamic(this, &AKamikazeEnemy::OnHit);
	

}

// Called every frame
void AKamikazeEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKamikazeEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKamikazeEnemy::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	AFPSCharacter* Character = Cast<AFPSCharacter>(OtherActor);

	if(Character)
	{
		Character->DealDamage(DamageValue);
		Destroy();
	}
}

void AKamikazeEnemy::DealDamage(float DamageAmount)
{
	Health -= DamageAmount;

	if(Health < 0.0f)
	{
		Cast<AFPSCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0))->AddPoints(PointsPerDeath);
		Destroy();
	}
}

