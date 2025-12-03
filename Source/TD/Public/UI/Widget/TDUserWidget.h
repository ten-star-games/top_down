#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TD_API UTDUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};