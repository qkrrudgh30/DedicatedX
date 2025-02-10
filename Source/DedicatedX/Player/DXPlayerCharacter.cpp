﻿// DXPlayerCharacter.cpp


#include "DXPlayerCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "DedicatedX.h"

ADXPlayerCharacter::ADXPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ADXPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::HandleMoveInput);

	EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::HandleLookInput);
	
	EIC->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
}

// Called when the game starts or when spawned
void ADXPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority() == false && IsLocallyControlled() == true)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		DXCheckF(IsValid(PC) == true, TEXT("PlayerController is invalid."));
	
		UEnhancedInputLocalPlayerSubsystem* EILPS = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
		DXCheckF(IsValid(EILPS) == true, TEXT("EnhancedInputLocalPlayerSubsystem is invalid."));
	
		EILPS->AddMappingContext(InputMappingContext, 0);
	}	
}

void ADXPlayerCharacter::HandleMoveInput(const FInputActionValue& InValue)
{
	if (IsValid(Controller) == false)
	{
		UE_LOG(LogDX, Error, TEXT("Controller is invalid."));
		return;
	}
	
	const FVector2D InMovementVector = InValue.Get<FVector2D>();

	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator ControlYawRotation(0.0f, ControlRotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(ControlYawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(ControlYawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, InMovementVector.X);
	AddMovementInput(RightDirection, InMovementVector.Y);
}

void ADXPlayerCharacter::HandleLookInput(const FInputActionValue& InValue)
{
	if (IsValid(Controller) == false)
	{
		UE_LOG(LogDX, Error, TEXT("Controller is invalid."));
		return;
	}
	
	const FVector2D InLookVector = InValue.Get<FVector2D>();

	AddControllerYawInput(InLookVector.X);
	AddControllerPitchInput(InLookVector.Y);
}

