// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EMovingDirection : uint8
{
	None = 0,
	ForwardDirection = 10 UMETA(DisplayName = "ForwardDirection"),
	BackwardDirection = 20 UMETA(DisplayName = "BackwardDirection"),
	LeftDirection = 30 UMETA(DisplayName = "LeftDirection"),
	RightDirection = 40 UMETA(DisplayName = "RightDirection"),
};

UCLASS()
class SHOOTERGAME_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	// initialize
	virtual void NativeInitializeAnimation() override;
	// update
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
	virtual void UpdateProperty(float DeltaSeconds);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class AShooterCharacter* ShooterCharacter;
	/** Movement */
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool HasVelocity;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool HasAcceleration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	EMovingDirection MovingDirection = EMovingDirection::None;
};
