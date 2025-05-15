// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomEventContainer.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyPressed, FKey, _onKeyPressed);


/**
 * 
 */
UCLASS()
class UI_TEMPLATE_API UCustomEventContainer : public UObject
{
	GENERATED_BODY()
	UPROPERTY(BlueprintAssignable, meta = (AllowPrivateAccess))FOnKeyPressed onKeyPressed;
public:	
	FORCEINLINE FOnKeyPressed& GetOnKeyPressed() { return onKeyPressed; }
};
