// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/KYMUserWidgetBase.h"
#include "UITitle.generated.h"

class UTextColorButton;
class UImage;
/**
 * 
 */
UCLASS()
class TOPDOWNSTUDY_API UUITitle : public UKYMUserWidgetBase
{
	GENERATED_BODY()

public:
	UUITitle();

protected:
	virtual void NativeConstruct() override;
	
private:
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess, BindWidget))
	TObjectPtr<UImage> Background;
	UPROPERTY()
	TObjectPtr<UTexture2D> BackgroundImage;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess="true", BindWidget))
	TObjectPtr<UTextColorButton> PlayButton;

	UFUNCTION()
	void OnPlayButtonClicked();

	UFUNCTION()
	void OnPlayButtonReleased();
};
