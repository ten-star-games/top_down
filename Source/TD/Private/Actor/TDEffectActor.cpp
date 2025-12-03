
#include "Actor/TDEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/TDAttributeSet.h"
#include "Components/SphereComponent.h"

ATDEffectActor::ATDEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ATDEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UTDAttributeSet* TDAttributeSet = Cast<UTDAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UTDAttributeSet::StaticClass()));

		UTDAttributeSet* MutableTDAttributeSet = const_cast<UTDAttributeSet*>(TDAttributeSet);
		MutableTDAttributeSet->SetHealth(TDAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ATDEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ATDEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ATDEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ATDEffectActor::EndOverlap);
}
