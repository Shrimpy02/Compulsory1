// Fill out your copyright notice in the Description page of Project Settings.

//Include Library
#include "Element.h"
#include "Components/staticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Containers/Array.h"
#include "Components/SphereComponent.h"

AElement::AElement()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initializes Arrays
	Sphere.Init(NULL, numberOfspheres);
	buttonPressed.Init(0, numberOfspheres);
	isRed.Init(0, numberOfspheres);
	isBlue.Init(0.f, numberOfspheres);

	// Creat sphere meshes
	for (int i = 0; i < numberOfspheres; i++) {
		Sphere[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Sphere_") + FString::FromInt(i)), false);
	}

	// Sets the Root Component
	SetRootComponent(Sphere[4]);

	// Sets mesh attatchemtn to root component for location
	for (int i = 0; i < numberOfspheres; i++)
		if (i != 4)
			Sphere[i]->SetupAttachment(GetRootComponent());

	// Relative Sphere location too root
	Sphere[0]->SetRelativeLocation(FVector(400.f, -400.f, 0.f));
	Sphere[1]->SetRelativeLocation(FVector(400.f, 0.f, 0.f));
	Sphere[2]->SetRelativeLocation(FVector(400.f, 400.f, 0.f));
	Sphere[3]->SetRelativeLocation(FVector(0.f, -400.f, 0.f));
	Sphere[4]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Sphere[5]->SetRelativeLocation(FVector(0.f, 400.f, 0.f));
	Sphere[6]->SetRelativeLocation(FVector(-400.f, -400.f, 0.f));
	Sphere[7]->SetRelativeLocation(FVector(-400.f, 0.f, 0.f));
	Sphere[8]->SetRelativeLocation(FVector(-400.f, 400.f, 0.f));

	//Create and attach Spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-75.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 1500.f;

	//Create and attach Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	//Set Materials
	Red = CreateDefaultSubobject<UMaterial>(TEXT("Red"));
	Blue = CreateDefaultSubobject<UMaterial>(TEXT("Blue"));
	White = CreateDefaultSubobject<UMaterial>(TEXT("White"));

	//Allowes player to posses the pawn
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AElement::BeginPlay()
{
	Super::BeginPlay();
	// Colors spheres for game start
	for (int i = 0; i < numberOfspheres; i++)
		Sphere[i]->SetMaterial(0, White);

	// Sets turn to red for game start
	turn = 0;

	// Notifies of game start
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Black, "Game Start");
}

// Called every frame
void AElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Checks for win condition every Tick
	winCondition();
}

// Called to bind functionality to input
void AElement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Butten pressed condition and what functon that runs as a result
	PlayerInputComponent->BindAction("1", IE_Pressed, this, &AElement::oneP);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &AElement::twoP);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &AElement::threeP);
	PlayerInputComponent->BindAction("4", IE_Pressed, this, &AElement::fourP);
	PlayerInputComponent->BindAction("5", IE_Pressed, this, &AElement::fiveP);
	PlayerInputComponent->BindAction("6", IE_Pressed, this, &AElement::sixP);
	PlayerInputComponent->BindAction("7", IE_Pressed, this, &AElement::sevenP);
	PlayerInputComponent->BindAction("8", IE_Pressed, this, &AElement::eightP);
	PlayerInputComponent->BindAction("9", IE_Pressed, this, &AElement::nineP);
	PlayerInputComponent->BindAction("tab", IE_Pressed, this, &AElement::reset);
}

void AElement::oneP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[0] == 0) {
		Sphere[0]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[0] = 1;
		isRed[0] = 1;
	}

	else if (turn == 1 && buttonPressed[0] == 0) {
		Sphere[0]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[0] = 1;
		isBlue[0] = 1;
	}
}

void AElement::twoP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[1] == 0) {
		Sphere[1]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[1] = 1;
		isRed[1] = 1;
	}

	else if (turn == 1 && buttonPressed[1] == 0) {
		Sphere[1]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[1] = 1;
		isBlue[1] = 1;
	}
}

void AElement::threeP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[2] == 0) {
		Sphere[2]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[2] = 1;
		isRed[2] = 1;
	}

	else if (turn == 1 && buttonPressed[2] == 0) {
		Sphere[2]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[2] = 1;
		isBlue[2] = 1;
	}
}

void AElement::fourP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[3] == 0) {
		Sphere[3]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[3] = 1;
		isRed[3] = 1;
	}

	else if (turn == 1 && buttonPressed[3] == 0) {
		Sphere[3]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[3] = 1;
		isBlue[3] = 1;
	}
}

void AElement::fiveP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[4] == 0) {
		Sphere[4]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[4] = 1;
		isRed[4] = 1;
	}

	else if (turn == 1 && buttonPressed[4] == 0) {
		Sphere[4]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[4] = 1;
		isBlue[4] = 1;
	}
}

void AElement::sixP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[5] == 0) {
		Sphere[5]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[5] = 1;
		isRed[5] = 1;
	}

	else if (turn == 1 && buttonPressed[5] == 0) {
		Sphere[5]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[5] = 1;
		isBlue[5] = 1;
	}
}

void AElement::sevenP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[6] == 0) {
		Sphere[6]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[6] = 1;
		isRed[6] = 1;
	}

	else if (turn == 1 && buttonPressed[6] == 0) {
		Sphere[6]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[6] = 1;
		isBlue[6] = 1;
	}
}

void AElement::eightP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[7] == 0) {
		Sphere[7]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[7] = 1;
		isRed[7] = 1;
	}

	else if (turn == 1 && buttonPressed[7] == 0) {
		Sphere[7]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[7] = 1;
		isBlue[7] = 1;
	}
}

void AElement::nineP()
{
	//Conditions for wich collor the ball gets once pressed.
	if (turn == 0 && buttonPressed[8] == 0) {
		Sphere[8]->SetMaterial(0, Red);
		turn = 1;
		buttonPressed[8] = 1;
		isRed[8] = 1;
	}

	else if (turn == 1 && buttonPressed[8] == 0) {
		Sphere[8]->SetMaterial(0, Blue);
		turn = 0;
		buttonPressed[8] = 1;
		isBlue[8] = 1;
	}
}

void AElement::winCondition()
{
	// All 8 Win Conditions for Red
	if (isRed[0] == 1 && isRed[1] == 1 && isRed[2] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[3] == 1 && isRed[4] == 1 && isRed[5] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[6] == 1 && isRed[7] == 1 && isRed[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[0] == 1 && isRed[3] == 1 && isRed[6] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[1] == 1 && isRed[4] == 1 && isRed[7] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[2] == 1 && isRed[5] == 1 && isRed[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[0] == 1 && isRed[4] == 1 && isRed[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	else if (isRed[2] == 1 && isRed[4] == 1 && isRed[6] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "Red Wins!");

	// All 8 Win Conditions for Blue
	if (isBlue[0] == 1 && isBlue[1] == 1 && isBlue[2] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[3] == 1 && isBlue[4] == 1 && isBlue[5] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[6] == 1 && isBlue[7] == 1 && isBlue[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[0] == 1 && isBlue[3] == 1 && isBlue[6] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[1] == 1 && isBlue[4] == 1 && isBlue[7] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[2] == 1 && isBlue[5] == 1 && isBlue[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[0] == 1 && isBlue[4] == 1 && isBlue[8] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");

	else if (isBlue[2] == 1 && isBlue[4] == 1 && isBlue[6] == 1)
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Blue, "Blue Wins!");
}

void AElement::reset()
{
	// Resets materials
	for (int i = 0; i < numberOfspheres; i++)
		Sphere[i]->SetMaterial(0, White);
	
	// Resets constents
	for (int i = 0; i < numberOfspheres; i++) {
		isRed[i] = 0;
		isBlue[i] = 0;
		buttonPressed[i] = 0;
	}
	turn = 0;
	
	// Notifies of game start
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Black, "Game Re-started");
	
}
