// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DemoNetDriver.h"

#include "RSDemoNetDriver.generated.h"



/**
 * Base Demo Net Driver. (currently adds nothing)
 * 
 * Key Goals:
 *		1) Provide a method to play a replay on a particular set of Actors.
 *			- This is needed for a "ghost data" feature (e.g. Sonic Riders time attack).
 *			- Also need to make sure we can interact with these Actors so that the game can override
 *				a mesh's material to a ghost-like material and disable sound effects and such.
 *		
 *		2) Make a way to play a replay without spectating it (play replay during gameplay).
 *			- This is required for ghost data as well so that we can play a Replay for
 *				ghost data while the Player is playing the game.
 *			- Also need a way to disable the replaying Actors from interacting with the world (so that you
 *				don't bump into your racing ghost and stuff - this may be something that the primary game
 *				module implements).
 *		
 * 
 * NOTE: subclassing this may not even be necessary for what we want to achieve. Making a
 * custom INetworkReplayStreamer or something else may be helpful as well.
 * 
 * Extra Ideas:
 *		1) It would be cool if the game could interact with the replay if they wanted to.
 *			- You could make cool abilities like replaying an Actor and interacting with it.
 *		2) Also we need a way to mix the FInMemoryNetworkReplayStreamer and the FLocalFileNetworkReplayStreamer together (or
 *		   make our own custom INetworkReplayStreamer).
 *			- This is needed for recording a replay in memory and then saving it to disk when desired.
 *			- E.g. After viewing an instant replay / kill cam, you can save it to disk because it was epic.
 * 
 */
UCLASS()
class REPLAYSETUP_API URSDemoNetDriver : public UDemoNetDriver
{
	GENERATED_BODY()

public:
	URSDemoNetDriver(const FObjectInitializer& ObjectInitializer);

protected:

};