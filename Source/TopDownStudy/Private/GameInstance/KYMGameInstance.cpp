// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/KYMGameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode/TitleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Util/Util.h"

void UKYMGameInstance::Init()
{
	Super::Init();
	const FString TitleLevelPath = UUtil::GetModifiedPath(TEXT("/Script/Engine.World'/Game/Level/Title.Title'"));
	ChangeLevel(*TitleLevelPath, ATitleGameMode::StaticClass());
}

void UKYMGameInstance::Shutdown()
{
	Super::Shutdown();
}

void UKYMGameInstance::ChangeLevel(const FString LevelName, const TSubclassOf<AGameModeBase> GameMode) const
{	
	const UWorld* World = GetWorld();
	check(World);
	if (GameMode)
	{
		FString Option = FString::Printf(TEXT("?game=%s"), *GameMode->GetPathName());		
		UGameplayStatics::OpenLevel(World, *LevelName, true, *Option);
		UE_LOG(LogTemp, Log, TEXT("%s Level is opened by option name '%s'"), *LevelName, *Option);
	}
	else
	{
		UGameplayStatics::OpenLevel(World, *LevelName);
	}
}

