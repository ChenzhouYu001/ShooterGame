// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	HasVelocity = false;
	HasAcceleration = false;
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	UpdateProperty(DeltaSeconds);
	UpdateVelocityandAcceleration();
}

void UShooterAnimInstance::UpdateProperty(float DeltaSeconds)
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
}

void UShooterAnimInstance::UpdateVelocityandAcceleration()
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	// Velocity
	if (ShooterCharacter)
	{
		const FVector WorldVelocity = ShooterCharacter->GetVelocity();
		const FVector WorldVelocity2D = WorldVelocity * FVector(1.0f, 1.0f, 0.0f);
		const FRotationMatrix RotationMatrix(ShooterCharacter->GetActorRotation());
		const FVector LocalVelocity2D = RotationMatrix.TransformVector(WorldVelocity2D);
		if (LocalVelocity2D.Size() > 0)
		{
			HasVelocity = true;
		}
		else
		{
			HasVelocity = false;
		}
	}
	// Acceleration
	if (ShooterCharacter)
	{
		UCharacterMovementComponent* CharacterMovement = ShooterCharacter->GetCharacterMovement();
		if (CharacterMovement != nullptr)
		{
			const FVector WorldAcceleration = CharacterMovement->GetCurrentAcceleration();
			const FVector WorldAcceleration2D = WorldAcceleration * FVector(1.0f, 1.0f, 0.0f);
			const FRotationMatrix RotationMatrix(ShooterCharacter->GetActorRotation());
			const FVector LocalAcceleration2D = RotationMatrix.TransformVector(WorldAcceleration2D);
			if (LocalAcceleration2D.Size() > 0)
			{
				HasAcceleration = true;
			}
			else
			{
				HasAcceleration = false;
			}
		}
	}
}
