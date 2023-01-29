// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Element.generated.h"

// Makeshift Class for error avoidance
class USpringArmComponent;
class UCameraComponent;
class UMaterial;

UCLASS()
class COMPULSORY1_API AElement : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AElement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Global Verriables for this pawn
	int numberOfspheres{ 9 };
	int turn{ 0 };

	// Arrays for konstants
	TArray<int> buttonPressed;
	TArray<int> isRed;
	TArray<float> isBlue;

	// Gameplay Components
	UPROPERTY(EditAnywhere, Category = "Spheres")
		TArray<UStaticMeshComponent*> Sphere;

	UPROPERTY(EditAnywhere);
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere);
	UCameraComponent* Camera;

	// Material Components
	UPROPERTY(EditAnywhere);
	UMaterial* Red;
	UPROPERTY(EditAnywhere);
	UMaterial* Blue;
	UPROPERTY(EditAnywhere);
	UMaterial* White;

	// Game Functions
	void oneP();
	void twoP();
	void threeP();
	void fourP();
	void fiveP();
	void sixP();
	void sevenP();
	void eightP();
	void nineP();

	void winCondition();
	void reset();
};
