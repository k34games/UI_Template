// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomInputSubsystem.h"

#include "../InputInterpretor/CustomInputInterpretor.h"
//
//void UCustomInputSubsystem::AddKeyDownBinding(FKey _key, FOnKeyPressed _event)
//{
//	//keyDownBindings.Add(_key, _event);
//}

//
//FOnKeyPressed& UCustomInputSubsystem::GetEventFromKey(FKey _key)
//{
//	// TODO: insert return statement here
//}

UCustomEventContainer* UCustomInputSubsystem::GetCustomEventContainerForKeyUp(const FKey& Key)
{
	if (keyDownBindings.Contains(Key))
	{
		TObjectPtr<UCustomEventContainer> _customEvent = keyDownBindings[Key];
		if (!_customEvent)
		{
			_customEvent = NewObject<UCustomEventContainer>(this);
			keyDownBindings[Key] = _customEvent;
		}
		return _customEvent;
	}
	//else
	TObjectPtr<UCustomEventContainer> _customEvent = NewObject<UCustomEventContainer>(this);
	keyDownBindings.Add(Key, _customEvent);
	return _customEvent;

}
//TObjectPtr<UCustomEventContainer> UCustomInputSubsystem::GetCustomEventContainerForKeyDown(const FKey& _key)
//{
//	return TObjectPtr<UCustomEventContainer>();
//}

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
	if (keyDownBindings.Contains(_key))
	{
		UCustomEventContainer* _eventContainer = keyDownBindings[_key];
		if (!_eventContainer)
			return;
		_eventContainer->GetOnKeyPressed().Broadcast(_key);
	}
}

void UCustomInputSubsystem::UpdateLastUpPressedKey(FKey _key)
{
	if (keyUpBindings.Contains(_key))
	{
		UCustomEventContainer* _eventContainer = keyUpBindings[_key];
		if (!_eventContainer)
			return;
		_eventContainer->GetOnKeyPressed().Broadcast(_key);
	}
}

void UCustomInputSubsystem::UpdateMouseDown(const FPointerEvent& _event)
{
	mouseDownBindings.Broadcast(_event);
}

void UCustomInputSubsystem::UpdateMouseUp(const FPointerEvent& _event)
{
	mouseUpBindings.Broadcast(_event);
}

void UCustomInputSubsystem::UpdateMouseDoubleClick(const FPointerEvent& _event)
{
	mouseDoubleClickBindings.Broadcast(_event);
}
