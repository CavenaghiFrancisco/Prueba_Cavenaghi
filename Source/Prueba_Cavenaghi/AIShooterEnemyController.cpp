// Fill out your copyright notice in the Description page of Project Settings.


#include "AIShooterEnemyController.h"
#include "BlackboardKeys.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "ShooterEnemy.h"
#include "Kismet/GameplayStatics.h"


AAIShooterEnemyController::AAIShooterEnemyController(FObjectInitializer const& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/FirstPerson/Blueprints/BT_ShooterEnemy.BT_ShooterEnemy'"));
	if (obj.Succeeded())
	{
		BehaviorTree = obj.Object;
	}
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("ShooterBehavior"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void AAIShooterEnemyController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);
	
}

void AAIShooterEnemyController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	if (Blackboard)
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

UBlackboardComponent* AAIShooterEnemyController::GetBlackboard() const
{
	return Blackboard;
}

