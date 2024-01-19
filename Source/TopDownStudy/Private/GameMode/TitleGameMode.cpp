// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/TitleGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerController/TitlePlayerController.h"
#include "UI/Title/UITitle.h"
#include "Util/Util.h"

ATitleGameMode::ATitleGameMode()
{
	// 여기서 로드
	const FString Path = UUtil::GetBlueprintPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/Title/WBP_UITitle.WBP_UITitle'"));
	static ConstructorHelpers::FClassFinder<UUITitle>UITitleFinder(*Path);
	if (UITitleFinder.Succeeded())
	{
		UITitleClass = UITitleFinder.Class;
	}
	PlayerControllerClass = ATitlePlayerController::StaticClass();
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

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
			
	}
}


