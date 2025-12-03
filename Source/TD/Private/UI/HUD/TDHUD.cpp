// Copyright Tenstar Games(anhyewon)


#include "UI/HUD/TDHUD.h"

#include "UI/Widget/TDUserWidget.h"

void ATDHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
	
}