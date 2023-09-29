// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "TASK_ShootPlayer.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBA_CAVENAGHI_API UTASK_ShootPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTASK_ShootPlayer(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
