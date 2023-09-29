// Fill out your copyright notice in the Description page of Project Settings.


#include "TASK_FindPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "AIKamikazeEnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BlackboardKeys.h"
#include "Kismet/GameplayStatics.h"


UTASK_FindPlayer::UTASK_FindPlayer(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Player");
}

EBTNodeResult::Type UTASK_FindPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const Controller = Cast<AAIKamikazeEnemyController>(OwnerComp.GetAIOwner());
	auto const NPC = Controller->GetPawn();

	const FVector PlayerLocation = UGameplayStatics::GetPlayerPawn(GetWorld(),0)->GetActorLocation();

	NPC->SetActorRotation((PlayerLocation - NPC->GetActorLocation()).Rotation());
	
	Controller->GetBlackboard()->SetValueAsVector(BlackboardKeys::TargetLocation, PlayerLocation);
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
