// Copyright Epic Games, Inc. All Rights Reserved.

#include "DedicatedX.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, DedicatedX, "DedicatedX" );

DEFINE_LOG_CATEGORY(LogDX);
DEFINE_LOG_CATEGORY(LogDXNet);

TAutoConsoleVariable<bool> CVarDebugGeneral(TEXT("DX.Debug.General"), false, TEXT("일반적인 디버깅 정보를 띄우고자 할 때 사용합니다.\n"), ECVF_Cheat);
