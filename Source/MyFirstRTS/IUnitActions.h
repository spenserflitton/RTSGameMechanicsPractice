// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IUnitActions.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UIUnitActions : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class MYFIRSTRTS_API IIUnitActions
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MoveUnitToLocation(FVector destination);

	void GatherResource(AActor *resource);

	void InteractWithBuilding(AActor *building);

	void AttackTarget(AActor *attackTarget);
};
