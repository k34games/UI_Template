// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Subsystem/CustomInputSubsystem.h"
#include "Framework/Application/IInputProcessor.h"
/**
 * 
 */
class UI_TEMPLATE_API CustomInputInterpretor : public IInputProcessor
{
protected:
	UPROPERTY()
	UCustomInputSubsystem& localSub;
public:

	CustomInputInterpretor(UCustomInputSubsystem& _localPlayerSub);
	/** Key down input */
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

	/** Key up input */
	virtual bool HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

	/** Analog axis input */
	virtual bool HandleAnalogInputEvent(FSlateApplication& SlateApp, const FAnalogInputEvent& InAnalogInputEvent) override;

	///** Mouse movement input */
	//virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;

	/** Mouse button press */
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;

	/** Mouse button release */
	virtual bool HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)  override;

	/** Mouse button double clicked. */
	virtual bool HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)  override;

	virtual void Tick(const float _deltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> cursor) override;
};
