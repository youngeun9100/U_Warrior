#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

UCLASS()
class U_WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()
	
public :
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	class UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
