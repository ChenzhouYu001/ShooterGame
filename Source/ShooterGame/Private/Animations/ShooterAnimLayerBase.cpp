// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/ShooterAnimLayerBase.h"

void UShooterAnimLayerBase::UpdateProperty(float DeltaSeconds)
{
	Super::UpdateProperty(DeltaSeconds);
	if (ShooterCharacter)
	{
		SetFrameSpeedandDisplacement(DeltaSeconds);
	}
}

void UShooterAnimLayerBase::SetFrameSpeedandDisplacement(float DeltaTime)
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
