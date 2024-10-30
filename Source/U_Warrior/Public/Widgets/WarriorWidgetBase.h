#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WarriorWidgetBase.generated.h"

UCLASS()
class U_WARRIOR_API UWarriorWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owing Hero UI Component Initialized"))
	void BP_OnOwingHeroUIComponentInitialized(class UHeroUIComponent* OwningHeroUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owing Enemy UI Component Initialized"))
	void BP_OnOwingEnemyUIComponentInitialized(class UEnemyUIComponent* OwingEnemyUIComponent);

public :
	UFUNCTION(BlueprintCallable)
	void InitEnemyCreatedWidget(AActor* OwingEnemyActor);

};
