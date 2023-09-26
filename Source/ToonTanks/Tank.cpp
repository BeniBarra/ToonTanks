// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
    tankSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
    tankSpringArm->SetupAttachment(RootComponent);

    tankCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
    tankCamera->SetupAttachment(tankSpringArm);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);

}

void ATank::Move(float Value)
{
    FVector DeltaLocation(0.f);

    // X = Value * DeltaTime * Speed
    DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    UE_LOG(LogTemp, Warning, TEXT("%f"), Value);

    AddActorLocalOffset(DeltaLocation);
}