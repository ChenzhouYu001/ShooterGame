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
	virtual void UpdateProperty(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Cycle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Stop;
	/** Movement */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float SpeedEachFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float DisplacementEachFrame;
private:
	bool IsFirstUpdate;
	FVector LastUpdateLocation;
private:
	void SetFrameSpeedandDisplacement(float DeltaTime);
public:
	FORCEINLINE float GetFrameDisplacement() const { return DisplacementEachFrame; }
	FORCEINLINE float GetFrameSpeed() const { return SpeedEachFrame; }
};
