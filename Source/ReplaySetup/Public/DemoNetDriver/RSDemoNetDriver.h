// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DemoNetDriver.h"

#include "RSDemoNetDriver.generated.h"



/**
 * Base Demo Net Driver. (currently adds nothing)
 * 
 * NOTE: actually im starting to realize that this may not be viable by
 * subclassing the DemoNetDriver. Most of their stuff is private rather than protected and
 * a lot of key functions that are protected are not virtual. I guess we should
 * turn to forking the engine and pull requesting - if we do go this route then i want to
 * make sure that they accept it (i don't to manage my own fork of the engine i just want to use their engine).
 * 
 * 
 * 
 * Key Goals:
 *		1) Provide a method to play a replay on a particular set of Actors.
 *			- This is needed for a "ghost data" feature (e.g. Sonic Riders time attack).
 *			- Also need to make sure we can interact with these Actors so that the game can override
 *				a mesh's material to a ghost-like material and disable sound effects and such.
 *		
 *		2) Make a way to play a replay on top of the current map (without loading a new map).
 *			- This is required for ghost data as well so that we can play a replay for
 *				ghost data while the Player is playing the game.
 *			- Also need a way to disable the replaying Actors from interacting with the world (so that you
 *				don't bump into your racing ghost and stuff - this may be something that the primary game
 *				module implements).
 *		
 * 
 * Extra Ideas:
 *		1) It would be cool if the game could interact with the replay if they wanted to.
 *			- You could make cool abilities like rewinding an Actor and interacting with it.
 *		
 *		2) Also we need a way to mix the ``FInMemoryNetworkReplayStreamer`` and the ``FLocalFileNetworkReplayStreamer`` together (or
 *		   make our own custom ``INetworkReplayStreamer``).
 *			- This is needed for recording a replay in memory and then saving it to disk when desired.
 *			- E.g. After viewing an instant replay / kill cam, you can save it to disk because it was epic.
 *			- ACTUALLY: The engine already has this implemented in their ``FSaveGameNetworkReplayStreamer`` - look into this
 *		
 *		3) Also make a fix for PlayReplay() so that the replay isn't playing while the Player is loading into the map
 *		
 *		4) 
 *		
 * 
 * 
 * 
 * BASIC SUMMARY OF THE ENGINE'S REPLAY SYSTEM:
 * 
 * 
 *	UGameInstance::StartRecordingReplay()
 * 		UReplaySubsystem::RecordReplay()
 * 			UReplaySubsystem::StopExistingReplays()
 * 			UEngine::CreateNamedNetDriver()
 * 			UDemoNetDriver::InitListen()
 *				UDemoNetDriver::InitBase()
 * 					FReplayHelper::Init()
 *				UDemoNetConnection::InitConnection()
 *				UNetDriver::AddClientConnection()
 * 				FReplayHelper::StartRecording()
 * 					INetworkReplayStreamer::StartStreaming()
 * 				UDemoNetDriver::SpawnDemoRecSpectator()
 * 
 * 
 *	UGameInstance::StopRecordingReplay()
 * 		UReplaySubsystem::StopReplay()
 * 			UReplaySubsystem::StopExistingReplays()
 * 				UWorld::DestroyDemoNetDriver()
 * 					UDemoNetDriver::StopDemo()
 * 						FReplayHelper::StopReplay()
 * 							INetworkReplayStreamer::StopStreaming()
 * 					UEngine::DestroyNamedNetDriver()
 * 
 * 
 *	UGameInstance::PlayReplay()
 * 		UReplaySubsystem::PlayReplay()
 * 			UReplaySubsystem::StopExistingReplays()
 * 			UEngine::CreateNamedNetDriver()
 * 			UDemoNetDriver::InitConnect()
 *				UDemoNetDriver::InitBase()
 * 					FReplayHelper::Init()
 *				UNetConnection::InitConnection()
 * 				INetworkReplayStreamer::StartStreaming()
 * 					UDemoNetDriver::ReplayStreamingReady()
 * 						UDemoNetDriver::InitConnectInternal()
 * 							NewObject<UDemoPendingNetGame>()
 *	UEngine::TickWorldTravel()
 * 		UEngine::LoadMap()
 * 
 * 
 * 
 */
UCLASS()
class REPLAYSETUP_API URSDemoNetDriver : public UDemoNetDriver
{
	GENERATED_BODY()

public:
	URSDemoNetDriver(const FObjectInitializer& ObjectInitializer);


	virtual bool InitConnect(class FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error) override;

protected:

};
