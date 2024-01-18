// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Util.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSTUDY_API UUtil : public UObject
{
	GENERATED_BODY()
	
public:
	static FString GetModifiedPath(const FString Path);
	static FString GetBlueprintPath(const FString Path);

private:
	inline static FString GameFolder = "/Game";
	inline static FString UnderBarC = "_C";
	inline static char SingleQuote = '\'';
};
