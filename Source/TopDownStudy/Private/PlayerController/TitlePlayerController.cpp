// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/TitlePlayerController.h"

ATitlePlayerController::ATitlePlayerController()
{
	this->bShowMouseCursor = true;
	this->bEnableClickEvents = true;
	
// 이거는 생성자말고 이후에 호출하기
	// FInputModeUIOnly InputModeData;
	// InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// FInputModeGameAndUI InputModeData;
	// InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// InputModeData.SetHideCursorDuringCapture(false);
	//SetInputMode(InputModeData);
}
