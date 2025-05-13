// Fill out your copyright notice in the Description page of Project Settings.


#include "UISubsystem.h"
//void UUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
//{
//	Super::Initialize(Collection);
	//FSlateBrush _brush;
	//_brush.
	//FStarshipCoreStyle::SetFocusBrush(&OverridenFocusBrush);
	//a regarder pour le coup
	//FStarshipCoreStyle::SetPressedSelectionColor(FLinearColor::Red);
//}

void UUISubsystem::SetFocusBrush(FSlateBrush _brush)
{

	OverridenFocusBrush = _brush;
	FStarshipCoreStyle::SetFocusBrush(&OverridenFocusBrush);
}
