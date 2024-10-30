#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U_WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// ������Ʈ�� ���� ���� ã�� �ش� Ŭ������ ĳ���� �ϴ� �Լ�
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Paramet get GetPawn must bo derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	// ���� �Լ��� �ѹ� �˻��� ���� �������� �Լ�
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	// ������Ʈ�� ���� ���� ��Ʈ�ѷ��� �������� �Լ�
	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Paramet get GetController must bo derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
