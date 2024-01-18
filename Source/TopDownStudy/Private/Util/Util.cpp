// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/Util.h"

FString UUtil::GetModifiedPath(const FString Path)
{
	FString Result;
	// /Game 이후 부분 추출
	if (Path.Split(GameFolder, nullptr, &Result))
	{
		if (Result[Result.Len() - 1] == SingleQuote)
		{
			// ' 따옴표 제거
			Result.RemoveAt(Result.Len() - 1, 1);
		}
		// 경로 병합 후 리턴
		return FPaths::Combine(GameFolder, Result);
	}
	UE_LOG(LogTemp, Warning, TEXT("Get Modified Path() -> Path split failed. It doesn't contain /Game. %s"), *Path);
	return Path;
}

FString UUtil::GetBlueprintPath(const FString Path)
{
	FString Result;
	// /Game 이후 부분 추출
	if (Path.Split(GameFolder, nullptr, &Result))
	{
		if (Result[Result.Len() - 1] == SingleQuote)
		{
			// ' 따옴표 제거
			Result.RemoveAt(Result.Len() - 1, 1);
			Result.Append(UnderBarC);
		}
		// 경로 병합 후 리턴
		return FPaths::Combine(GameFolder, Result);
	}
	UE_LOG(LogTemp, Warning, TEXT("Get Blueprint Path() -> Path split failed. It doesn't contain /Game. %s"), *Path);
	return Path;
}
