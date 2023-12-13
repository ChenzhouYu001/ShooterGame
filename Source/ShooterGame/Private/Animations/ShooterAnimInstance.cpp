// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimInstance.h"
#include "ShooterCharacter.h"

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
}
