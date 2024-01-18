// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Base/TextColorButton.h"

UTextColorButton::UTextColorButton()
{
	this->OnUnhovered.AddDynamic(this, &UTextColorButton::SetNormalTextColor);
	this->OnHovered.AddDynamic(this, &UTextColorButton::SetHoveredTextColor);
	this->OnClicked.AddDynamic(this, &UTextColorButton::SetPressedTextColor);
	this->OnPressed.AddDynamic(this, &UTextColorButton::SetPressedTextColor);

	SetNormalTextColor();
}

void UTextColorButton::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	FString ChangedPropertyName = PropertyChangedEvent.GetPropertyName().ToString();
	if (ChangedPropertyName == TEXT("NormalTextColor"))
	{	
		SetNormalTextColor();
	}
	else if (ChangedPropertyName == TEXT("HoveredTextColor"))
	{
		SetHoveredTextColor();
	}
	else if (ChangedPropertyName == TEXT("PressedTextColor"))
	{
		SetPressedTextColor();
	}
	else if (ChangedPropertyName == TEXT("DisabledTextColor"))
	{
		SetDisabledTextColor();
	}
}

void UTextColorButton::SetNormalTextColor()
{
	this->SetColorAndOpacity(NormalTextColor);
}

void UTextColorButton::SetHoveredTextColor()
{
	this->SetColorAndOpacity(HoveredTextColor);	
}

void UTextColorButton::SetPressedTextColor()
{
	this->SetColorAndOpacity(PressedTextColor);
}

void UTextColorButton::SetDisabledTextColor()
{
	this->SetColorAndOpacity(DisabledTextColor);
}

