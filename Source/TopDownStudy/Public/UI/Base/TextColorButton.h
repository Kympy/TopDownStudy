// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TextColorButton.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSTUDY_API UTextColorButton : public UButton
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button Text Color")
	FLinearColor NormalTextColor = FLinearColor::White;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button Text Color")
	FLinearColor HoveredTextColor = FLinearColor::White;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button Text Color")
	FLinearColor PressedTextColor = FLinearColor::White;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button Text Color")
	FLinearColor DisabledTextColor = FLinearColor::White;

	UTextColorButton();

protected:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

private:
	UFUNCTION()
	void SetNormalTextColor();
	
	UFUNCTION()
	void SetHoveredTextColor();

	UFUNCTION()
	void SetPressedTextColor();

	UFUNCTION()
	void SetDisabledTextColor();
};
