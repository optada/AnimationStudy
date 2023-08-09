// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance_MannyBase2.h"

#include "AnimationStudyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UAnimInstance_MannyBase2::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AAnimationStudyCharacter>(TryGetPawnOwner());

	if (Character)
	{
		MovementComponent = Character->GetCharacterMovement();
		CameraComponent = Character->GetFollowCamera();
		CapsuleComponent = Character->GetCapsuleComponent();
	}
}

void UAnimInstance_MannyBase2::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Character) == false)
	{
		return;
	}

	if (MovementComponent)
	{
		Velocity = MovementComponent->Velocity;
		GroundSpeed = Velocity.Size2D();
		
		ShouldMove = MovementComponent->GetCurrentAcceleration() != FVector(0, 0, 0) && GroundSpeed > 3;
	
		IsFalling = MovementComponent->IsFalling();
	}
	else
	{
		Velocity = {};
		GroundSpeed = 0;
		
		ShouldMove = false;
		
		IsFalling = false;		
	}

	if (CameraComponent && CapsuleComponent)
	{
		ForwardVector = CapsuleComponent->GetForwardVector();
		CharacterPosition = CapsuleComponent->GetComponentLocation();

		const FVector WorldLookAtLocation = CameraComponent->GetForwardVector() * 500;
		const FVector MiddleOfCapsulePosition = CharacterPosition + FVector(0, 0, CapsuleComponent->GetScaledCapsuleHalfHeight());
		
		ViewTargetPosition = WorldLookAtLocation + MiddleOfCapsulePosition;
	}
	else
	{
		ForwardVector = {0, 1, 0};
		CharacterPosition = {};

		ViewTargetPosition = {};
	}
}
