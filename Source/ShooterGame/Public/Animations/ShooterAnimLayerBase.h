// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/ShooterAnimInstance.h"
#include "Animation/AnimSequence.h"
#include "ShooterAnimLayerBase.generated.h"

USTRUCT(BlueprintType)
struct FShooterAnimations
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* BackWard;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Left;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Right;
};

UCLASS()
class SHOOTERGAME_API UShooterAnimLayerBase : public UShooterAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void UpdateProperty(float DeltaSeconds) override;
	/** Animation */
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	UAnimSequence* Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	FShooterAnimations Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	FShooterAnimations Cycle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimationSequence, meta = (AllowPrivateAccess = "true"))
	FShooterAnimations Stop;

	/** Movement */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float SpeedEachFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float DisplacementEachFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	FString DistanceCurveName;
private:
	bool IsFirstUpdate;
	FVector LastUpdateLocation;
private:
	void SetFrameSpeedandDisplacement(float DeltaTime);
public:
	FORCEINLINE float GetFrameDisplacement() const { return DisplacementEachFrame; }
	FORCEINLINE float GetFrameSpeed() const { return SpeedEachFrame; }

	/** MovementComponent */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UCharacterMovementComponent* CharacterMovementComponent;
private:
	void UpdateCharacterMovementComponent();
};
