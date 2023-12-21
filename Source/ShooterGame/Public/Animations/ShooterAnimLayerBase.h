// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/ShooterAnimInstance.h"
#include "Animation/AnimSequence.h"
#include "ShooterAnimLayerBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterAnimLayerBase : public UShooterAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Cycle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Stop;
};
