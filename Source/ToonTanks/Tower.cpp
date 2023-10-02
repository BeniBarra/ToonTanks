// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find distance to tank
    if(Tank)
    {
        FVector TankLocation = Tank->GetActorLocation();
        float Distance = FVector::Dist(GetActorLocation(), TankLocation);
        
        // Check if tank is in range
        if(Distance <= FireRange)
        {
            // If in range, rotate turrent toward tank
            RotateTurret(TankLocation);
        }
    }

    
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}