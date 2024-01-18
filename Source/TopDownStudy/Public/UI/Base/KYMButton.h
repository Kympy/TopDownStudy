// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "KYMButton.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FOnUnhoveredDelegateSignature, FLinearColor)

UCLASS()
class TOPDOWNSTUDY_API UKYMButton : public UButton
{
	GENERATED_BODY()

public:

	UKYMButton();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor NormalTextColor;
	FOnUnhoveredDelegateSignature OnUnhoveredDelegate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor HoveredTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor PressedTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor DisabledTextColor;

	UFUNCTION()
	void SetNormalTextColor();
};
