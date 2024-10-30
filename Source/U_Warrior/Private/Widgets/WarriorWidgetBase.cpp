#include "Widgets/WarriorWidgetBase.h"
#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/HeroUIComponent.h"
#include "Components/UI/EnemyUIComponent.h"

void UWarriorWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
		{
			BP_OnOwingHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UWarriorWidgetBase::InitEnemyCreatedWidget(AActor* OwingEnemyActor)
{
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwingEnemyActor))
	{
		UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent();

		checkf(EnemyUIComponent, TEXT("Failed to extrac an EnemyUIComponent from %s"), *OwingEnemyActor->GetActorNameOrLabel());
		
		BP_OnOwingEnemyUIComponentInitialized(EnemyUIComponent);
	}
}
