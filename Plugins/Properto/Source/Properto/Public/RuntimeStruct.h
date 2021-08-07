#pragma once

#include "RuntimePropertyBase.h"
#include "RuntimeStruct.generated.h"

UCLASS(BlueprintType)
class URuntimeStruct : public URuntimePropertyBase
{
public:
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly,meta=(DisplayName="Properties"))
	TArray<URuntimePropertyBase*> m_Properties;

private:
	TArray<FProperty*> m_UeProperties;
	UScriptStruct* m_ScriptStructPtr = nullptr;
};