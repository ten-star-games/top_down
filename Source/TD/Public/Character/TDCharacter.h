// Copyright Tenstar Games(anhyewon)

#pragma once

#include "CoreMinimal.h"
#include "Character/TDCharacterBase.h"
#include "TDCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TD_API ATDCharacter : public ATDCharacterBase
{
	GENERATED_BODY()
public:
	ATDCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};
