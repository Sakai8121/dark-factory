#include "MyUnrealEdEngine.h"
#include "ISourceControlModule.h"

void UMyUnrealEdEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);

	const ISourceControlModule& SourceControlModule = ISourceControlModule::Get();
	{
		ISourceControlProvider& SourceControlProvider = SourceControlModule.GetProvider();

		const TArray<FString> Branches{ "origin/main", "origin/develop", "origin/dev_Sato", "origin/dev_Sakai" };

		SourceControlProvider.RegisterStateBranches(Branches, TEXT("Content"));
	}
}
