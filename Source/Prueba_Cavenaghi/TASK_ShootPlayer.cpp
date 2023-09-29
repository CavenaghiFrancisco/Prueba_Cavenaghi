// Fill out your copyright notice in the Description page of Project Settings.


#include "TASK_ShootPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "AIShooterEnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BlackboardKeys.h"
#include "DrawDebugHelpers.h"
#include "FPSCharacter.h"
#include "ShooterEnemy.h"
#include "Debug/ReporterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

UTASK_ShootPlayer::UTASK_ShootPlayer(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Shoot Player");
}

EBTNodeResult::Type UTASK_ShootPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(Player != NULL)
	{
		auto const Controller = Cast<AAIShooterEnemyController>(OwnerComp.GetAIOwner());
		auto const NPC = Controller->GetPawn();

		FVector Start = NPC->GetActorLocation() + FVector(0,0,50);
		FVector End = Player->GetActorLocation()+ FVector(0,0,50);
		FHitResult HitResult;
		FCollisionObjectQueryParams QueryParams;
		FCollisionResponseParams Params;

		FVector Distance = End - NPC->GetActorLocation();
		Distance.Z = 0.0f;
		NPC->SetActorRotation(Distance.Rotation());
	
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult,
			Start,
			End,
			ECC_Visibility,
			FCollisionQueryParams::DefaultQueryParam,
			FCollisionResponseParams::DefaultResponseParam);
		
		if(bHit)
		{
			AFPSCharacter* Character =  Cast<AFPSCharacter>(HitResult.GetActor());
			if(Character && Distance.Size() < 1100)
			{
				Cast<AShooterEnemy>(NPC)->OnFire();
			}
		}
	}
	

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
