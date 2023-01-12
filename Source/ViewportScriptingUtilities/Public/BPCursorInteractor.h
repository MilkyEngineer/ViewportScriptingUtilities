// Copyright Alex Stevens. All Rights Reserved.

#pragma once

#include "InputCoreTypes.h"

#include "MouseCursorInteractor.h"
#include "BPCursorInteractor.generated.h"

/**
 * Exposes viewport cursor functionality to Editor Utility Blueprints via Viewport World Interaction class
 */
UCLASS(MinimalAPI, abstract, Blueprintable, BlueprintType, meta = (DisplayName = "Cursor Interactor"))
class UBPCursorInteractor : public UMouseCursorInteractor
{
	GENERATED_BODY()
	
public:
	virtual UWorld* GetWorld() const override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = CursorInteractor)
	void Initialise();

	UFUNCTION(BlueprintCallable, Category = CursorInteractor, meta = (DisplayName = "Add Key Action"))
	void BP_AddKeyAction(FKey Key, FName ActionName);

	UFUNCTION(BlueprintCallable, Category = CursorInteractor, meta = (DisplayName = "Remove Key Action"))
	void BP_RemoveKeyAction(FKey Key);
};
