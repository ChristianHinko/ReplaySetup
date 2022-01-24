// Fill out your copyright notice in the Description page of Project Settings.

#include "ReplaySetup.h"

#include "Modules/ModuleManager.h"



#define LOCTEXT_NAMESPACE "FReplaySetupModule"

void FReplaySetupModule::StartupModule()
{
	IModuleInterface::StartupModule();


}

void FReplaySetupModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();


}

#undef LOCTEXT_NAMESPACE


IMPLEMENT_MODULE(FReplaySetupModule, ReplaySetup);
