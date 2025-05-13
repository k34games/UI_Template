// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Styling/StarshipCoreStyle.h"
#include "UISubsystem.generated.h"

//FSlateBrush OverridenFocusBrush;
//static FSlateBrush OverridenFocusBrush;

/**
 * 
 */
UCLASS()
class UI_TEMPLATE_API UUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:

	//virtual void Initialize(FSubsystemCollectionBase& Collection) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateBrush OverridenFocusBrush;
	UFUNCTION(BlueprintCallable) void SetFocusBrush(FSlateBrush _brush);

	UFUNCTION(BlueprintCallable) void SetFocusBrushTutorial(FSlateBrush InBrush)
	{
		OverridenFocusBrush = InBrush;
		FStarshipCoreStyle::SetFocusBrush(&OverridenFocusBrush);
	}

};
