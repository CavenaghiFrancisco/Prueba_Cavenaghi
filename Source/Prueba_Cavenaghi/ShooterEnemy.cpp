// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterEnemy.h"

#include "EnemyProjectile.h"
#include "FPSCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShooterEnemy::AShooterEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(40.0f, 95.0f);
	
	MannequinMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Character Mesh"));

	MannequinMesh->SetupAttachment(GetCapsuleComponent());
	MannequinMesh->bCastDynamicShadow = false;
	MannequinMesh->CastShadow = false;
	MannequinMesh->AddRelativeLocation(FVector(0.0f, 0.0f, -87.0f));


	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	
	GunPointLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Gun Point Location"));
	GunPointLocation->SetupAttachment(GunMesh);
	GunPointLocation->AddRelativeLocation(FVector(0.2f, 58.4f, 10.6f));
}

// Called when the game starts or when spawned
void AShooterEnemy::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	
	GunMesh->AttachToComponent(MannequinMesh,
		FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		TEXT("GripPoint"));
	GunMesh->AddRelativeLocation(FVector(-17.0f, 1.0f, 104.0f));
}

void AShooterEnemy::OnFire()
{
	if (World != NULL)
	{
		SpawnRotation = (UGameplayStatics::GetPlayerPawn(GetWorld(),0)->GetActorLocation() -GunPointLocation->GetComponentLocation()).Rotation();

		SpawnLocation = ((GunPointLocation != nullptr) ?
			GunPointLocation->GetComponentLocation() :
			GetActorLocation());

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride =
			ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
		World->SpawnActor<AEnemyProjectile>(Projectile,
			SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
}

// Called every frame
void AShooterEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void AShooterEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShooterEnemy::DealDamage(float DamageAmount)
{
	Health -= DamageAmount;

	if(Health < 0.0f)
	{
		Cast<AFPSCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0))->AddPoints(PointsPerDeath);
		Destroy();
	}
}

