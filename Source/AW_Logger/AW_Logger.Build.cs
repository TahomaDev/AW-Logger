// (c)2022 AWAIKO. All Rights Reserved.

using UnrealBuildTool;

public class AW_Logger : ModuleRules
{
	public AW_Logger(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
/*		
		PublicIncludePaths.AddRange(
			new string[] {
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
			}
			);*/
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"DeveloperSettings",
			}
			);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore"
			}
			);
		
/*		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);*/
	}
}
