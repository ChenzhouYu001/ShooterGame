// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/ShooterAnimInstance.h"
#include "ShooterAnimLogicBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API UShooterAnimLogicBase : public UShooterAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void UpdateProperty(float DeltaSeconds) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	EForwardIntension ForwardIntension;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	ERightIntension RightIntension;
};
