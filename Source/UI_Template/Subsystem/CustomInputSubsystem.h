// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Templates/SharedPointer.h"

#include "CustomInputSubsystem.generated.h"

UENUM()
enum ECustomInputType
{
	MnK,
	Gamepad,
	Touch
};

/**
 * 
 */

class CustomInputInterpretor; 

UCLASS()
class UI_TEMPLATE_API UCustomInputSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputTypeChanged, ECustomInputType, newInput);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyPressed, FKey, _onKeyPressed);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMousePressed, FPointerEvent, _mouseEvent);
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess))	FOnInputTypeChanged onInputTypeChanged;
	 TSharedPtr<CustomInputInterpretor> interpretor;
	 UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess))	TEnumAsByte<ECustomInputType> currentInputType;


public:
	 UPROPERTY() TMap<FKey, FOnKeyPressed> keyDownBindings;
	 UPROPERTY() TMap<FKey, FOnKeyPressed> keyUpBindings;
	 UPROPERTY() TArray<FOnMousePressed> mouseDownBindings;
	 UPROPERTY() TArray<FOnMousePressed> mouseUpBindings;
	 UPROPERTY() TArray<FOnMousePressed> mouseDoubleClickBindings;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	void UpdateCurrentInputType(ECustomInputType _type);
	void UpdateLastDownPressedKey(FKey _key);
	void UpdateLastUpPressedKey(FKey _key);
	void UpdateMouseDown(const FPointerEvent& _event);
	void UpdateMouseUp(const FPointerEvent& _event);
	void UpdateMouseDoubleClick(const FPointerEvent& _event);
};
