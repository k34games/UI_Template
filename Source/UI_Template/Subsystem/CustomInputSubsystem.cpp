// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomInputSubsystem.h"

#include "../InputInterpretor/CustomInputInterpretor.h"

void UCustomInputSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	interpretor = MakeShared<CustomInputInterpretor>(*this); 
	FSlateApplication::Get().RegisterInputPreProcessor(interpretor);
}

void UCustomInputSubsystem::Deinitialize()
{
	Super::Deinitialize();
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(interpretor);
	}
	interpretor.Reset();
}

void UCustomInputSubsystem::UpdateCurrentInputType(ECustomInputType _type)
{
	if (currentInputType != _type)
	{
		currentInputType = _type;
		onInputTypeChanged.Broadcast(_type);
	}
}

void UCustomInputSubsystem::UpdateLastDownPressedKey(FKey _key)
{
}

void UCustomInputSubsystem::UpdateLastUpPressedKey(FKey _key)
{
}

void UCustomInputSubsystem::UpdateMouseDown(const FPointerEvent& _event)
{
	UE_LOG(LogTemp, Warning, TEXT("MOUSE DOWN"));
}

void UCustomInputSubsystem::UpdateMouseUp(const FPointerEvent& _event)
{
}

void UCustomInputSubsystem::UpdateMouseDoubleClick(const FPointerEvent& _event)
{
}
