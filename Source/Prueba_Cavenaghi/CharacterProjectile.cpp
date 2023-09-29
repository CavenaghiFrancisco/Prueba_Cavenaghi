// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ACharacterProjectile::ACharacterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	CollisionSphere->InitSphereRadius(20.0f);

	RootComponent = CollisionSphere;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->UpdatedComponent = CollisionSphere;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void ACharacterProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACharacterProjectile::OnHit);
}

// Called every frame
void ACharacterProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	AKamikazeEnemy* KamikazeEnemy = Cast<AKamikazeEnemy>(OtherActor);
	AShooterEnemy* ShooterEnemy = Cast<AShooterEnemy>(OtherActor);
	
	if(KamikazeEnemy)
	{
		KamikazeEnemy->DealDamage(DamageValue);
		Destroy();
	}
	else if(ShooterEnemy)
	{
		ShooterEnemy->DealDamage(DamageValue);
		Destroy();
	}
}

