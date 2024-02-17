// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimInstance.h"
#include "ShooterCharacter.h"
#include "Engine/Engine.h"
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
}

void UShooterAnimInstance::UpdateProperty(float DeltaSeconds)
{
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	if (ShooterCharacter)
	{
		// Velocity	
		const FVector& WorldVelocity = ShooterCharacter->GetVelocity();
		const FVector& WorldVelocity2D = WorldVelocity * FVector(1.0f, 1.0f, 0.0f);
		const FRotator& BaseRotation = ShooterCharacter->GetActorRotation();
		const FRotationMatrix& RotationMatrix(BaseRotation);
		const FVector& LocalVelocity2D = RotationMatrix.TransformVector(WorldVelocity2D);
		if (LocalVelocity2D.Size() > 0)
		{
			HasVelocity = true;
		}
		else
		{
			HasVelocity = false;
		}
		// Acceleration
		UCharacterMovementComponent* CharacterMovement = ShooterCharacter->GetCharacterMovement();
		if (CharacterMovement != nullptr)
		{
			const FVector& WorldAcceleration = CharacterMovement->GetCurrentAcceleration();
			const FVector& WorldAcceleration2D = WorldAcceleration * FVector(1.0f, 1.0f, 0.0f);
			const FVector& LocalAcceleration2D = RotationMatrix.TransformVector(WorldAcceleration2D);
			if (LocalAcceleration2D.Size() > 0)
			{
				HasAcceleration = true;
			}
			else
			{
				HasAcceleration = false;
			}
		}
		// MovementDirection
		float ForwardDeltaDegree = CalculateDirection(WorldVelocity2D, BaseRotation);
		if (ForwardDeltaDegree >= -45.0f && ForwardDeltaDegree < 45.0f)
		{
			MovingDirection = EMovingDirection::ForwardDirection;
		}
		if (ForwardDeltaDegree >= 45.0f && ForwardDeltaDegree < 135.0f)
		{
			MovingDirection = EMovingDirection::RightDirection;
		}
		if (ForwardDeltaDegree >= 135.0f || ForwardDeltaDegree <= -135.0f)
		{
			MovingDirection = EMovingDirection::BackwardDirection;
		}
		if (ForwardDeltaDegree <= -45.0f && ForwardDeltaDegree > -135.0f)
		{
			MovingDirection = EMovingDirection::LeftDirection;
		}
	}
}
