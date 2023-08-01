// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreComponent.h"

#include "PropertyAccess.h"

// Sets default values for this component's properties
UCoreComponent::UCoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCoreComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AActor* owner = GetOwner();
	if(owner)
	{
		owner->OnTakeAnyDamage.AddDynamic(this, &UCoreComponent::TakeDamage);
	}
}

void UCoreComponent::TakeDamage(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	
}


void UCoreComponent::OnOwnerTakeAnyDamage_Implementation(float const Damage)
{
	if(Damage <= 0)
		return;
	Health -= std::max(0.0f, Health - Damage);
}

void UCoreComponent::OnOwnerTakeRepair_Implementation(float const Repair)
{
	if(Repair <= 0)
		return;
	Health += std::min(0.0f, Health + Repair);
}




