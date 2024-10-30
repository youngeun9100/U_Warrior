#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPercontChangedDelegate, float, NewPercent);

UCLASS()
class U_WARRIOR_API UPawnUIComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public :
	UPROPERTY(BlueprintAssignable)
	FOnPercontChangedDelegate OnCurrentHealthChanged;
};
