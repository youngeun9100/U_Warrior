#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "HeroUIComponent.generated.h"

UCLASS()
class U_WARRIOR_API UHeroUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()
	
public :
	UPROPERTY(BlueprintAssignable)
	FOnPercontChangedDelegate OnCurrentRageChanged;
};
