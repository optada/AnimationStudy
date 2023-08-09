// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance_MannyBase.generated.h"


class AAnimationStudyCharacter;
class UCameraComponent;
class UCharacterMovementComponent;


UCLASS(BlueprintType, Blueprintable)
class ANIMATIONSTUDY_API UAnimInstance_MannyBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UPROPERTY(BlueprintReadOnly, Category = Character, Meta = (AllowPrivateAccess = "true"))
	AAnimationStudyCharacter* Character = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAccess = "true"))
	UCharacterMovementComponent* MovementComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent = nullptr;


	UPROPERTY(BlueprintReadOnly, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	FVector Velocity = {};

	UPROPERTY(BlueprintReadOnly, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	float GroundSpeed = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	bool ShouldMove = false;

	UPROPERTY(BlueprintReadOnly, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	bool IsFalling = false;


	// UPROPERTY(BlueprintReadOnly, Category = AdditionalData, Meta = (AllowPrivateAccess = "true"))
	// FVector ViewTarget = {};
};
