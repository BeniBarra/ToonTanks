// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* tankSpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* tankCamera;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed = 600.f;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float TurnRate = 120.f;
	
	void Move(float value);

	void Turn(float value);

	UPROPERTY()
	APlayerController* PlayerControllerRef;

};
