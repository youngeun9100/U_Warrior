#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

UCLASS()
class U_WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public :
	virtual void GiveToAbilitySystemComponent(class UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	// 부여받은 직후에 활성화해야 하는 능력들의 배열
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<class UWarriorGameplayAbility>> ActivateOnGivenAbilities;

	// 특정 조건에서 발동되는 적중 반응이나 사망등의 능력들의 배열
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<class UWarriorGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<class UGameplayEffect>> StartUpGameplayEffects;

	void GrantAbilities(const TArray<TSubclassOf<class UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
