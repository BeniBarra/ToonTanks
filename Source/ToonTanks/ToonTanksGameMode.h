// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
public:
	GENERATED_BODY()

	void ActorDied(AActor* DeadActor);

protected:

	virtual void BeginPlay() override;
	

private:

	class ATank* Tank;

};
