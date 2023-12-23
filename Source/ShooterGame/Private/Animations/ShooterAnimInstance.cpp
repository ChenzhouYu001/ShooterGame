// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimInstance.h"

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	UpdateProperty(DeltaSeconds);
}

void UShooterAnimInstance::UpdateProperty(float DeltaSeconds)
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
}
