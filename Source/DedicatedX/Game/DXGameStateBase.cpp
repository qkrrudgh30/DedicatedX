// DXGameStateBase.cpp


#include "DXGameStateBase.h"
#include "DedicatedX.h"

ADXGameStateBase::ADXGameStateBase()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXGameStateBase::HandleBeginPlay()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::HandleBeginPlay();
		// 서버 로직. 여기서 월드의 모든 액터들에게 BeginPlay() 함수 호출 지시.
		// 이를 통해 ADXGameStateBase::OnRep_ReplicatedHasBegunPlay() 함수가 호출됨.
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}

void ADXGameStateBase::OnRep_ReplicatedHasBegunPlay()
{
	DX_LOG_NET(LogDXNet, Log, TEXT("Begin"));
	Super::OnRep_ReplicatedHasBegunPlay();
	DX_LOG_NET(LogDXNet, Log, TEXT("End"));
}
