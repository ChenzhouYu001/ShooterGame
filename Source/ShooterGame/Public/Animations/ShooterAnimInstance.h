// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
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
	UPROPERTY()
	class AShooterCharacter* ShooterCharacter;


};
