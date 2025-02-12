// DXPlayerController.cpp


#include "DXPlayerController.h"
#include "DedicatedX.h"

ADXPlayerController::ADXPlayerController()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXPlayerController::BeginPlay()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::BeginPlay();
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}
