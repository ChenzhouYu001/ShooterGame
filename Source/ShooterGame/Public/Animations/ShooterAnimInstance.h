// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterCharacter.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	// initialize
	virtual void NativeInitializeAnimation() override;
	// update
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
private:
	void UpdateProperty(float DeltaSeconds);
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class AShooterCharacter* ShooterCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	EForwardIntension ForwardIntension;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	ERightIntension RightIntension;


private:
	void GetTheAnimationCharacterSpeed();
	void SetTheMovementComponentSpeed();
};
