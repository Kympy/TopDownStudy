// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/KYMGameModeBase.h"
#include "TitleGameMode.generated.h"

class UUITitle;
/**
 * 
 */
UCLASS()
class TOPDOWNSTUDY_API ATitleGameMode : public AKYMGameModeBase
{
	GENERATED_BODY()
	
public:
	ATitleGameMode();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<UUITitle> UITitle;
	TObjectPtr<UClass> UITitleClass;
};
