#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

UCLASS()
class U_WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
	
public :
	AWarriorEnemyCharacter();

	//~ Bigin IPawnCombatInterface Interface.
	virtual class UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.

	//~ Bigin IPawnUIInterface Interface.
	virtual class UPawnUIComponent* GetPawnUIComponent() const override;
	virtual class UEnemyUIComponent* GetEnemyUIComponent() const override;
	//~ End IPawnUIInterface Interface.

protected:
	//~ Bigin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	class UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	class UEnemyUIComponent* EnemyUIComponent;

private:
	void InitEnemyStartUpData();

public :
	FORCEINLINE class UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
