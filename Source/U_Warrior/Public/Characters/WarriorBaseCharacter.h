#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "Interfaces/PawnUIInterface.h"
#include "WarriorBaseCharacter.generated.h"

UCLASS()
class U_WARRIOR_API AWarriorBaseCharacter : 
	public ACharacter, 
	public IAbilitySystemInterface,
	public IPawnCombatInterface,
	public IPawnUIInterface
{
	GENERATED_BODY()

public:
	AWarriorBaseCharacter();
	 
	//~ Bigin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

	//~ Bigin IPawnCombatInterface Interface.
	virtual class UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.

	//~ Bigin IPawnUIInterface Interface.
	virtual class UPawnUIComponent* GetPawnUIComponent() const override;
	//~ End IPawnUIInterface Interface.

protected:
	//~ Bigin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	class UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	class UWarriorAttributeSet* WarriorAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<class UDataAsset_StartUpDataBase> CharacterStartUpData;

public :
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }
};
