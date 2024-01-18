// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Base/KYMButton.h"

UKYMButton::UKYMButton()
{
	this->OnUnhovered.AddDynamic(this, &UKYMButton::SetNormalTextColor);
}

void UKYMButton::SetNormalTextColor()
{
			
}

