// Fill out your copyright notice in the Description page of Project Settings.


#include "AIKamikazeEnemyController.h"

#include "BlackboardKeys.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "KamikazeEnemy.h"
#include "Kismet/GameplayStatics.h"


AAIKamikazeEnemyController::AAIKamikazeEnemyController(FObjectInitializer const& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/FirstPerson/Blueprints/BT_KamikazeEnemy.BT_KamikazeEnemy'"));
	if (obj.Succeeded())
	{
		BehaviorTree = obj.Object;
	}
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("KamikazeBehavior"));
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
}

void AAIKamikazeEnemyController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BehaviorTreeComponent->StartTree(*BehaviorTree);
	
}

void AAIKamikazeEnemyController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	if (Blackboard)
	{
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

UBlackboardComponent* AAIKamikazeEnemyController::GetBlackboard() const
{
	return Blackboard;
}
