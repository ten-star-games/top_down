// Copyright Tenstar Games(anhyewon)


#include "Player/TDPlayerState.h"

#include "AbilitySystem/TDAbilitySystemComponent.h"
#include "AbilitySystem/TDAttributeSet.h"


ATDPlayerState::ATDPlayerState()

{
	AbilitySystemComponent = CreateDefaultSubobject<UTDAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UTDAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f); //	NetUpdateFrequency는 ue5.6 이상부터 폐기
	
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ATDPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
