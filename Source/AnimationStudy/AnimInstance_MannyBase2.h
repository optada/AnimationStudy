// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance_MannyBase2.generated.h"


class UCapsuleComponent;
class AAnimationStudyCharacter;
class UCameraComponent;
class UCharacterMovementComponent;


UCLASS(BlueprintType, Blueprintable)
class ANIMATIONSTUDY_API UAnimInstance_MannyBase2 : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UPROPERTY(BlueprintReadWrite, Category = Character, Meta = (AllowPrivateAccess = "true"))
	AAnimationStudyCharacter* Character = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = Movement, Meta = (AllowPrivateAccess = "true"))
	UCharacterMovementComponent* MovementComponent = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent = nullptr;
	
	
	UPROPERTY(BlueprintReadWrite, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	FVector Velocity = {};
	
	UPROPERTY(BlueprintReadWrite, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	float GroundSpeed = 0.f;
	
	UPROPERTY(BlueprintReadWrite, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	bool ShouldMove = false;
	
	UPROPERTY(BlueprintReadWrite, Category = MovementParameters, Meta = (AllowPrivateAccess = "true"))
	bool IsFalling = false;


	UPROPERTY(BlueprintReadWrite, Category = AdditionalData, Meta = (AllowPrivateAccess = "true"))
	FVector ViewTargetPosition = {};

	UPROPERTY(BlueprintReadWrite, Category = AdditionalData, Meta = (AllowPrivateAccess = "true"))
	FVector ForwardVector = {};

	UPROPERTY(BlueprintReadWrite, Category = AdditionalData, Meta = (AllowPrivateAccess = "true"))
	FVector CharacterPosition = {};
};
