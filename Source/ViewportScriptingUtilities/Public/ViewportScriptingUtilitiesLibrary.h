// Copyright Alex Stevens. All Rights Reserved.

#pragma once

class UViewportWorldInteraction;

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViewportScriptingUtilitiesLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VIEWPORTSCRIPTINGUTILITIES_API UViewportScriptingUtilitiesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = ViewportScriptingUtilities, meta = (WorldContext = "WorldContextObject"))
	static UViewportWorldInteraction* AddViewportWorldInteraction(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = ViewportScriptingUtilities, meta = (WorldContext = "WorldContextObject"))
	static UViewportWorldInteraction* FindViewportWorldInteraction(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = ViewportScriptingUtilities, meta = (WorldContext = "WorldContextObject"))
	static void RemoveViewportWorldInteraction(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = ViewportScriptingUtilities, meta = (WorldContext = "WorldContextObject"))
	static void SetTransformGizmoVisible(UObject* WorldContextObject, const bool bShouldBeVisible);
};
