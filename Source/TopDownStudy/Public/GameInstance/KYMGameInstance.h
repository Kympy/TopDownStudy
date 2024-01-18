// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KYMGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSTUDY_API UKYMGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	virtual void Init() override;
	virtual void Shutdown() override;

	void ChangeLevel(const FString LevelName, const TSubclassOf<AGameModeBase> GameMode) const;
};
