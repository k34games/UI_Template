// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Templates/SharedPointer.h"
#include "../InputInterpretor/CustomEventContainer.h"
#include "CustomInputSubsystem.generated.h"







UENUM()
enum ECustomInputType
{
	MnK,
	Gamepad,
	Touch
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputTypeChanged, ECustomInputType, newInput);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMousePressed, FPointerEvent, _mouseEvent);

/**
 * 
 */

class CustomInputInterpretor; 

UCLASS()
class UI_TEMPLATE_API UCustomInputSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess))	FOnInputTypeChanged onInputTypeChanged;
	 TSharedPtr<CustomInputInterpretor> interpretor;
	 UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess))	TEnumAsByte<ECustomInputType> currentInputType;


public:
	//UPROPERTY(BlueprintReadWrite) TMap<int, FCustomKeyEventWrapper> test;
	 UPROPERTY(BlueprintReadWrite) TMap<FKey, TObjectPtr<UCustomEventContainer>> keyDownBindings;
	 UPROPERTY(BlueprintReadWrite) TMap<FKey, TObjectPtr<UCustomEventContainer>> keyUpBindings;
	 UPROPERTY(BlueprintAssignable) FOnMousePressed mouseDownBindings;
	 UPROPERTY(BlueprintAssignable) FOnMousePressed mouseUpBindings;
	 UPROPERTY(BlueprintAssignable) FOnMousePressed mouseDoubleClickBindings;

	 //UFUNCTION(BlueprintCallable) FOnKeyPressed& GetEventFromKey(FKey _key);
	 UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Key")) UCustomEventContainer* GetCustomEventContainerForKeyUp(const FKey& Key);
	 //UFUNCTION(BlueprintCallable) TObjectPtr<UCustomEventContainer> GetCustomEventContainerForKeyDown(const FKey& _key);
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	void UpdateCurrentInputType(ECustomInputType _type);
	void UpdateLastDownPressedKey(FKey _key);
	void UpdateLastUpPressedKey(FKey _key);
	void UpdateMouseDown(const FPointerEvent& _event);
	void UpdateMouseUp(const FPointerEvent& _event);
	void UpdateMouseDoubleClick(const FPointerEvent& _event);
};
