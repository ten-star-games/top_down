// Copyright Tenstar Games(anhyewon)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class TD_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATDPlayerController();
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> TDContext;
};
