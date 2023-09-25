// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ATank::ATank()
{
    tankSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Tank Spring Arm"));
    tankSpringArm->SetupAttachment(RootComponent);

    tankCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Tank Camera"));
    tankCamera->SetupAttachment(tankSpringArm);
}