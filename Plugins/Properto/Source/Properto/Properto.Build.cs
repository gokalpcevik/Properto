// Some copyright should be here...

using UnrealBuildTool;

public class Properto : ModuleRules
{
	public Properto(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		string privateIncludePath = System.IO.Path.Combine(ModuleDirectory, "Private");
        string publicIncludePath = System.IO.Path.Combine(ModuleDirectory, "Public");
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				publicIncludePath
			}
			);
				
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				privateIncludePath
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
