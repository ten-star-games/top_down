// Copyright Tenstar Games(anhyewon)


#include "Player/TDPlayerController.h"
#include "EnhancedInputSubsystems.h"

ATDPlayerController::ATDPlayerController()
{
	bReplicates = true;
}

void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(TDContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	check(Subsystem);
	Subsystem->AddMappingContext(TDContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
