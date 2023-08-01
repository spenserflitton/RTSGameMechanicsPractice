// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "Components/ActorComponent.h"
#include "CoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFIRSTRTS_API UCoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCoreComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HealthMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ETeamAttitude::Type> FactionAttitude;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageTotal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ArmorTotal;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintNativeEvent)
	void OnOwnerTakeAnyDamage(float Damage);
	void OnOwnerTakeAnyDamage_Implementation(float Damage);

	UFUNCTION(BlueprintNativeEvent)
	void OnOwnerTakeRepair(float Repair);
	void OnOwnerTakeRepair_Implementation(float Repair);
};
