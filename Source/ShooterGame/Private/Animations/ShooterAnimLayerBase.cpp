// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimLayerBase.h"
#include "GameFramework/CharacterMovementComponent.h"
void UShooterAnimLayerBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	DistanceCurveName = "Distance";
}

void UShooterAnimLayerBase::UpdateProperty(float DeltaSeconds)
{
	Super::UpdateProperty(DeltaSeconds);
	SetFrameSpeedandDisplacement(DeltaSeconds);
	UpdateCharacterMovementComponent();
}

void UShooterAnimLayerBase::SetFrameSpeedandDisplacement(float DeltaTime)
{
	if (ShooterCharacter)
	{
		if (!IsFirstUpdate)
		{
			const FVector DisplacementEachFrameVector = ShooterCharacter -> GetActorLocation() - LastUpdateLocation;
			DisplacementEachFrame = DisplacementEachFrameVector.Size();
			if (DeltaTime > 0)
			{
				SpeedEachFrame = DisplacementEachFrame / DeltaTime;
			}
			else
			{
				SpeedEachFrame = 0.0f;
			}
		}
		LastUpdateLocation = ShooterCharacter -> GetActorLocation();
		IsFirstUpdate = false;	
	}
}

void UShooterAnimLayerBase::UpdateCharacterMovementComponent()
{
	if (ShooterCharacter)
	{
		CharacterMovementComponent = ShooterCharacter->GetCharacterMovement();
	}
}
