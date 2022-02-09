// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

//#include "ReplaySetup.generated.h" // uncomment if we ever need reflection



/**
 * 
 */
class FReplaySetupModule : public IModuleInterface
{
public:
	//virtual bool IsGameModule() const override
	//{
	//	return true;
	//}

	static inline FReplaySetupModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FReplaySetupModule>(FName(TEXT("ReplaySetup")));
	}
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded(FName(TEXT("ReplaySetup")));
	}

protected:
	//BEGIN IModuleInterface Interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//END IModuleInterface Interface

};
