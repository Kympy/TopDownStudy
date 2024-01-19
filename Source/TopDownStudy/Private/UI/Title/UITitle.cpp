// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Title/UITitle.h"

#include "Components/Image.h"
#include "UI/Base/TextColorButton.h"

UUITitle::UUITitle()
{
	// 생성자에서 로드
	static ConstructorHelpers::FObjectFinder<UTexture2D>BackgroundFinder(TEXT("/Script/Engine.Texture2D'/Game/Texture/BG/TestBG.TestBG'"));
	if (BackgroundFinder.Succeeded())
	{
		BackgroundImage = BackgroundFinder.Object;	
	}
}

void UUITitle::NativeConstruct()
{
	// 위젯 초기화 이후에 하위 속성 초기화
	Super::NativeConstruct();
	
	if (Background && BackgroundImage)
	{
		Background->SetBrushFromTexture(BackgroundImage);
	}
	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UUITitle::OnPlayButtonClicked);
		PlayButton->OnReleased.AddDynamic(this, &UUITitle::OnPlayButtonReleased);

		PlayButton->SetIsEnabled(true);
	}
}

void UUITitle::OnPlayButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Title UI : Play Button Clicked"));
	PlayButton->SetIsEnabled(false);
}

void UUITitle::OnPlayButtonReleased()
{
	UE_LOG(LogTemp, Log, TEXT("Title UI : Play Button Released"));
}
