#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());

	if (OwnerCharacter)
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter || !OwnerMovementComponent)
		return;

	GroundSpeed = OwnerCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
