// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomInputInterpretor.h"
#include "../Subsystem/CustomInputSubsystem.h"
CustomInputInterpretor::CustomInputInterpretor( UCustomInputSubsystem& _localPlayerSub) : localSub(_localPlayerSub)
{ 
}

bool CustomInputInterpretor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	localSub.UpdateLastDownPressedKey(InKeyEvent.GetKey());
	return false;
}

bool CustomInputInterpretor::HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	localSub.UpdateLastUpPressedKey(InKeyEvent.GetKey());
	return false;
}

bool CustomInputInterpretor::HandleAnalogInputEvent(FSlateApplication& SlateApp, const FAnalogInputEvent& InAnalogInputEvent)
{
	return false;
}

//bool CustomInputInterpretor::HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
//{
//	return false;
//}

bool CustomInputInterpretor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	localSub.UpdateMouseDown(MouseEvent);

	return false;
}

bool CustomInputInterpretor::HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	localSub.UpdateMouseUp(MouseEvent);
	return false;
}

bool CustomInputInterpretor::HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	localSub.UpdateMouseDoubleClick(MouseEvent);
	return false;
}

void CustomInputInterpretor::Tick(const float _deltaTime, FSlateApplication& _slateApp, TSharedRef<ICursor> _cursor)
{
}
