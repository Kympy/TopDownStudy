// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/TitleGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Title/UITitle.h"
#include "Util/Util.h"

ATitleGameMode::ATitleGameMode()
{
	// 여기서 로드
	const FString Path = UUtil::GetBlueprintPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Title/BP_UITitle.BP_UITitle'"));
	static ConstructorHelpers::FClassFinder<UUITitle>UITitleFinder(*Path);
	if (UITitleFinder.Succeeded())
	{
		UITitleClass = UITitleFinder.Class;
	}
}

void ATitleGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	// 여기서 위젯 생성
	if (UITitleClass)
	{
		UITitle = CreateWidget<UUITitle>(GetWorld(), UITitleClass);
		if (UITitle)
			UITitle->AddToViewport();
	}
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 여기서 커서 보이게 -> InitGame 에서는 PC 가 초기화 이전임.
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
		PC->bShowMouseCursor = true;
}


