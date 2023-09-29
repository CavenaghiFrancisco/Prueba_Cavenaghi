// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIKamikazeEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBA_CAVENAGHI_API AAIKamikazeEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	AAIKamikazeEnemyController(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get());
	
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	class UBlackboardComponent* GetBlackboard() const;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAcces = "true"))
		class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAcces = "true"))
		class UBehaviorTree* BehaviorTree;
private:

	class UBlackboardComponent* Blackboard;

};
