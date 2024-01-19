// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Base/TextColorButton.h"
#include "Components/TextBlock.h"

UTextColorButton::UTextColorButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

// 초기화 및 설정 단계 이후에 호출
void UTextColorButton::PostLoad()
{
	Super::PostLoad();
	
	this->OnUnhovered.RemoveDynamic(this, &UTextColorButton::SetNormalTextColor);
	this->OnHovered.RemoveDynamic(this, &UTextColorButton::SetHoveredTextColor);
	this->OnPressed.RemoveDynamic(this, &UTextColorButton::SetPressedTextColor);
	//this->OnReleased.RemoveDynamic(this, &UTextColorButton::SetReleasedTextColor);
	this->OnClicked.RemoveDynamic(this, &UTextColorButton::SetReleasedTextColor);

	this->OnUnhovered.AddDynamic(this, &UTextColorButton::SetNormalTextColor);
	this->OnHovered.AddDynamic(this, &UTextColorButton::SetHoveredTextColor);
	this->OnPressed.AddDynamic(this, &UTextColorButton::SetPressedTextColor);
	this->OnClicked.AddDynamic(this, &UTextColorButton::SetReleasedTextColor);
	//this->OnReleased.AddDynamic(this, &UTextColorButton::SetReleasedTextColor);

	InitButtonMethod();
	
	// const FOnWidgetStateBroadcast::FDelegate OnEnableChanged = FOnWidgetStateBroadcast::FDelegate::CreateLambda([this](UWidget* Widget, const FWidgetStateBitfield& StateBitfield)
	// {
	// 	if (Widget->GetIsEnabled())
	// 	{
	// 		UE_LOG(LogTemp, Log, TEXT("Enabled"));
	// 	}
	// 	else
	// 	{
	// 		UE_LOG(LogTemp, Log, TEXT("Disabled"));
	// 	}
	// });
	// PostWidgetStateChanged.Add(OnEnableChanged);
	
	SetNormalState();
}

void UTextColorButton::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	const FString ChangedPropertyName = PropertyChangedEvent.GetPropertyName().ToString();
	if (ChangedPropertyName == TEXT("NormalTextColor"))
	{	
		SetNormalTextColor();
	}
	else if (ChangedPropertyName == TEXT("HoveredTextColor"))
	{
		SetHoveredTextColor();
	}
	else if (ChangedPropertyName == TEXT("PressedTextColor"))
	{
		SetPressedTextColor();
	}
	else if (ChangedPropertyName == TEXT("DisabledTextColor"))
	{
		SetDisabledTextColor();
	}
}

// 이렇게 해야 의도된 대로 색상이 동작함 : Released 때문에.
void UTextColorButton::InitButtonMethod()
{
	// DownAndUp 이 노말한 방식.
	this->SetClickMethod(EButtonClickMethod::DownAndUp);
	this->SetTouchMethod(EButtonTouchMethod::DownAndUp);
	this->SetPressMethod(EButtonPressMethod::DownAndUp);
}

void UTextColorButton::SetIsEnabled(bool bInIsEnabled)
{
	Super::SetIsEnabled(bInIsEnabled);
	
	if (bInIsEnabled)
	{
		this->SetColorAndOpacity(NormalTextColor);
		UE_LOG(LogTemp, Log, TEXT("%s Button Enabled."), *this->GetName());
	}
	else
	{
		this->SetColorAndOpacity(DisabledTextColor);
		UE_LOG(LogTemp, Log, TEXT("%s Button Disabled."), *this->GetName());
	}
}

// TSharedRef<SWidget> UTextColorButton::RebuildWidget()
// {
// 	PRAGMA_DISABLE_DEPRECATION_WARNINGS
// 	MyButton = SNew(SButton)
// 		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
// 		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
// 		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
// 		.OnHovered_UObject( this, &ThisClass::SlateHandleHovered )
// 		.OnUnhovered_UObject( this, &ThisClass::SlateHandleUnhovered )
// 		.ButtonStyle(&WidgetStyle)
// 		.ClickMethod(ClickMethod)
// 		.TouchMethod(TouchMethod)
// 		.PressMethod(PressMethod)
// 		.IsFocusable(IsFocusable)
// 		;
// 	// TextBlock = SNew(STextBlock)
// 	// 	.SimpleTextMode(true);
// 	PRAGMA_ENABLE_DEPRECATION_WARNINGS
// 		if ( GetChildrenCount() > 0 )
// 		{
// 			Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());
// 		}
// 	
// 	return MyButton.ToSharedRef();
// }

void UTextColorButton::SetNormalTextColor()
{
	this->SetColorAndOpacity(NormalTextColor);
	//UE_LOG(LogTemp, Log, TEXT("Normal"));
}

void UTextColorButton::SetHoveredTextColor()
{
	this->SetColorAndOpacity(HoveredTextColor);
	//UE_LOG(LogTemp, Log, TEXT("Hovered"));	
}

void UTextColorButton::SetPressedTextColor()
{
	this->SetColorAndOpacity(PressedTextColor);
	//UE_LOG(LogTemp, Log, TEXT("Pressed"));
}

void UTextColorButton::SetDisabledTextColor()
{
	this->SetColorAndOpacity(DisabledTextColor);
	//UE_LOG(LogTemp, Log, TEXT("Disabled"));
}

void UTextColorButton::SetReleasedTextColor()
{
	if (this->IsHovered())
		this->SetColorAndOpacity(HoveredTextColor);
	else
	{
		this->SetColorAndOpacity(NormalTextColor);
	}
	//UE_LOG(LogTemp, Log, TEXT("Clicked"));
}

