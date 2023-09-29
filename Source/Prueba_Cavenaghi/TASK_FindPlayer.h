// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "TASK_FindPlayer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PRUEBA_CAVENAGHI_API UTASK_FindPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTASK_FindPlayer(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
