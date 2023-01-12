// Copyright Alex Stevens. All Rights Reserved.

#include "ViewportScriptingUtilitiesLibrary.h"

#include "LevelEditor.h"
#include "SLevelViewport.h"
#include "Editor.h"
#include "EditorWorldExtension.h"
#include "ViewportWorldInteraction.h"

UViewportWorldInteraction* UViewportScriptingUtilitiesLibrary::AddViewportWorldInteraction(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	UEditorWorldExtensionCollection* ExtensionCollection = GEditor->GetEditorWorldExtensionsManager()->GetEditorWorldExtensions(World);
	check(ExtensionCollection != nullptr);

	UViewportWorldInteraction* ViewportWorldInteraction = CastChecked<UViewportWorldInteraction>(ExtensionCollection->AddExtension(UViewportWorldInteraction::StaticClass()));
	check(ViewportWorldInteraction != nullptr);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	const TSharedRef<ILevelEditor>& LevelEditor = LevelEditorModule.GetFirstLevelEditor().ToSharedRef();

	if (TSharedPtr<IAssetViewport> ActiveLevelViewport = LevelEditor->GetActiveViewportInterface())
	{
		ViewportWorldInteraction->SetDefaultOptionalViewportClient(StaticCastSharedRef<SLevelViewport>(ActiveLevelViewport->AsWidget())->GetViewportClient());
	}

	return ViewportWorldInteraction;
}

UViewportWorldInteraction* UViewportScriptingUtilitiesLibrary::FindViewportWorldInteraction(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	UEditorWorldExtensionCollection* ExtensionCollection = GEditor->GetEditorWorldExtensionsManager()->GetEditorWorldExtensions(World);
	check(ExtensionCollection != nullptr);

	return Cast<UViewportWorldInteraction>(ExtensionCollection->FindExtension(UViewportWorldInteraction::StaticClass()));
}

void UViewportScriptingUtilitiesLibrary::RemoveViewportWorldInteraction(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	UEditorWorldExtensionCollection* ExtensionCollection = GEditor->GetEditorWorldExtensionsManager()->GetEditorWorldExtensions(World);
	check(ExtensionCollection != nullptr);

	if (UEditorWorldExtension* WorldExtension = ExtensionCollection->FindExtension(UViewportWorldInteraction::StaticClass()))
	{
		ExtensionCollection->RemoveExtension(WorldExtension);
	}
}

void UViewportScriptingUtilitiesLibrary::SetTransformGizmoVisible(UObject* WorldContextObject, const bool bShouldBeVisible)
{
	if (UViewportWorldInteraction* ViewportWorldInteraction = FindViewportWorldInteraction(WorldContextObject))
	{
		ViewportWorldInteraction->SetTransformGizmoVisible(bShouldBeVisible);
	}
}
