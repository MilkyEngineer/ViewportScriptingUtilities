// Copyright Alex Stevens. All Rights Reserved.

#include "BPCursorInteractor.h"

#include "ViewportWorldInteraction.h"

class UWorld* UBPCursorInteractor::GetWorld() const
{
	return WorldInteraction ? WorldInteraction->GetWorld() : NULL;
}

void UBPCursorInteractor::BP_AddKeyAction(FKey Key, FName ActionName)
{
	AddKeyAction(Key, ActionName);
}

void UBPCursorInteractor::BP_RemoveKeyAction(FKey Key)
{
	RemoveKeyAction(Key);
}
