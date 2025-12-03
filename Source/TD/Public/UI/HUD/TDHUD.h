// Copyright Tenstar Games(anhyewon)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TDHUD.generated.h"

class UTDUserWidget;
/**
 * 
 */
UCLASS()
class TD_API ATDHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UTDUserWidget>  OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UTDUserWidget> OverlayWidgetClass;
};