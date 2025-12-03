// Copyright Tenstar Games(anhyewon)

#pragma once

#include "CoreMinimal.h"
#include "Character/TDCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "TDEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TD_API ATDEnemy : public ATDCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	ATDEnemy();
	
public:
		
	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */
	
protected:
	virtual void BeginPlay() override;

};
