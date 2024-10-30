#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U_WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 컴포넌트의 소유 폰을 찾고 해당 클래스로 캐스팅 하는 함수
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Paramet get GetPawn must bo derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	// 위의 함수를 한번 검사후 폰을 가져오는 함수
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	// 컴포넌트의 소유 폰의 컨트롤러를 가져오는 함수
	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Paramet get GetController must bo derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
