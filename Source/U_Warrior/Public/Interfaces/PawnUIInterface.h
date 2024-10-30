#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnUIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnUIInterface : public UInterface
{
	GENERATED_BODY()
};

class U_WARRIOR_API IPawnUIInterface
{
	GENERATED_BODY()

public:
	virtual class UPawnUIComponent* GetPawnUIComponent() const = 0;

	virtual class UHeroUIComponent* GetHeroUIComponent() const;

	virtual class UEnemyUIComponent* GetEnemyUIComponent() const;
};
