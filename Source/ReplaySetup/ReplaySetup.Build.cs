// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ReplaySetup : ModuleRules
{
	public ReplaySetup(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		//PrivatePCHHeaderFile = "Private/ReplaySetupPCH.h";

		PublicDependencyModuleNames.AddRange(new string[] { "Core" });
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"CoreUObject",
				"Engine"
			}
		);
	}
}
