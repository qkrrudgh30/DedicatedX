// DXGameModeBase.cpp


#include "DXGameModeBase.h"
#include "DedicatedX.h"

ADXGameModeBase::ADXGameModeBase()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId,
	FString& ErrorMessage)
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

APlayerController* ADXGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal,
	const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	APlayerController* LoginPC = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
	return LoginPC;
}

void ADXGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::PostLogin(NewPlayer);
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXGameModeBase::StartPlay()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::StartPlay();
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXGameModeBase::BeginPlay()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::BeginPlay();
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}
