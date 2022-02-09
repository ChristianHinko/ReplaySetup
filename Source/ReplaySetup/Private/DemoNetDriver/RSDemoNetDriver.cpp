// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoNetDriver/RSDemoNetDriver.h"



URSDemoNetDriver::URSDemoNetDriver(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


bool URSDemoNetDriver::InitConnect(FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error)
{
	bool RetVal = Super::InitConnect(InNotify, ConnectURL, Error);


	// NOTE: modifying UDemoNetDriver::InitConnectInternal() to not make a Pending Net Game achieves
	// the "ghost data" result that we are going for BUT it is not virtual so we can't override it. This
	// combined with using the option "SkipSpawnSpectatorController" gives a really cool effect.



	return RetVal;
}
