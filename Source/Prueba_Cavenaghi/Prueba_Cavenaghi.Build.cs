// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Prueba_Cavenaghi : ModuleRules
{
	public Prueba_Cavenaghi(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"AIModule",
			"GameplayTasks",
			"NavigationSystem"
		});
	}
}
