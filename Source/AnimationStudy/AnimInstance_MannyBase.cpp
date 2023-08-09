// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance_MannyBase.h"

#include "AnimationStudyCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UAnimInstance_MannyBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AAnimationStudyCharacter>(TryGetPawnOwner());
	MovementComponent = Character->GetCharacterMovement();
	CameraComponent = Character->GetFollowCamera();
}

void UAnimInstance_MannyBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Character) == false)
	{
		return;
	}

	Velocity = MovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();

	ShouldMove = MovementComponent->GetCurrentAcceleration() != FVector(0, 0, 0) && GroundSpeed > 3;

	IsFalling = MovementComponent->IsFalling();
}
