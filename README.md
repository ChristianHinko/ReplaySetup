# ReplaySetup
Unreal Engine plugin that extends the engine's replay system to support ghost data and more!


NOTE: actually im starting to realize that this may not be viable by subclassing the DemoNetDriver. Most of their stuff is private rather than protected and a lot of key functions that are protected are not virtual. I guess we should turn to forking the engine and pull requesting - if we do go this route then i want to make sure that they accept it (i don't to manage my own fork of the engine i just want to use their engine).



Key Goals:
1. Provide a method to play a replay on a particular set of Actors.
	- This is needed for a "ghost data" feature (e.g. Sonic Riders time attack).
	- Also need to make sure we can interact with these Actors so that the game can override a mesh's material to a ghost-like material and disable sound effects and such.

2. Make a way to play a replay on top of the current map (without loading a new map).
	- This is required for ghost data as well so that we can play a replay for ghost data while the Player is playing the game.
	- Also need a way to disable the replaying Actors from interacting with the world (so that you don't bump into your racing ghost and stuff - this may be something that the primary game module implements).

Extra Ideas:
1. It would be cool if the game could interact with the replay if they wanted to.
	- You could make cool abilities like rewinding an Actor and interacting with it.

2. Also we need a way to mix the ``FInMemoryNetworkReplayStreamer`` and the ``FLocalFileNetworkReplayStreamer`` together (or make our own custom ``INetworkReplayStreamer``).
	- This is needed for recording a replay in memory and then saving it to disk when desired.
	- E.g. After viewing an instant replay / kill cam, you can save it to disk because it was epic.
	- ACTUALLY: The engine already has this implemented in their ``FSaveGameNetworkReplayStreamer`` - look into this

3. Also make a fix for PlayReplay() so that the replay isn't playing while the Player is loading into the map

4. 




BASIC SUMMARY OF THE ENGINE'S REPLAY SYSTEM:


UGameInstance::StartRecordingReplay()
&emsp;UReplaySubsystem::RecordReplay()
&emsp;&emsp;UReplaySubsystem::StopExistingReplays()
&emsp;&emsp;UEngine::CreateNamedNetDriver()
&emsp;&emsp;UDemoNetDriver::InitListen()
&emsp;&emsp;&emsp;UDemoNetDriver::InitBase()
&emsp;&emsp;&emsp;&emsp;FReplayHelper::Init()
&emsp;&emsp;&emsp;UDemoNetConnection::InitConnection()
&emsp;&emsp;&emsp;UNetDriver::AddClientConnection()
&emsp;&emsp;&emsp;FReplayHelper::StartRecording()
&emsp;&emsp;&emsp;&emsp;INetworkReplayStreamer::StartStreaming()
&emsp;&emsp;&emsp;UDemoNetDriver::SpawnDemoRecSpectator()


UGameInstance::StopRecordingReplay()
&emsp;UReplaySubsystem::StopReplay()
&emsp;&emsp;UReplaySubsystem::StopExistingReplays()
&emsp;&emsp;&emsp;UWorld::DestroyDemoNetDriver()
&emsp;&emsp;&emsp;&emsp;UDemoNetDriver::StopDemo()
&emsp;&emsp;&emsp;&emsp;&emsp;FReplayHelper::StopReplay()
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;INetworkReplayStreamer::StopStreaming()
&emsp;&emsp;&emsp;&emsp;UEngine::DestroyNamedNetDriver()


UGameInstance::PlayReplay()
&emsp;UReplaySubsystem::PlayReplay()
&emsp;&emsp;UReplaySubsystem::StopExistingReplays()
&emsp;&emsp;UEngine::CreateNamedNetDriver()
&emsp;&emsp;UDemoNetDriver::InitConnect()
&emsp;&emsp;&emsp;UDemoNetDriver::InitBase()
&emsp;&emsp;&emsp;&emsp;FReplayHelper::Init()
&emsp;&emsp;&emsp;UNetConnection::InitConnection()
&emsp;&emsp;&emsp;INetworkReplayStreamer::StartStreaming()
&emsp;&emsp;&emsp;&emsp;UDemoNetDriver::ReplayStreamingReady()
&emsp;&emsp;&emsp;&emsp;&emsp;UDemoNetDriver::InitConnectInternal()
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;NewObject<UDemoPendingNetGame>()
UEngine::TickWorldTravel()
&emsp;UEngine::LoadMap()
