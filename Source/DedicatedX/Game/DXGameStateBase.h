// DXGameStateBase.h

#pragma once

#include "GameFramework/GameStateBase.h"
#include "DXGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATEDX_API ADXGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	ADXGameStateBase();

	virtual void HandleBeginPlay() override;

	virtual void OnRep_ReplicatedHasBegunPlay() override;
	
};
