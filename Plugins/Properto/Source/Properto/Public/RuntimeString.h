#pragma once

#include "RuntimePropertyBase.h"
#include "RuntimeString.generated.h"

UCLASS(BlueprintType)
class URuntimeString : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FString GetValue() const;
	
	UFUNCTION(BlueprintCallable)
	void SetValue(const FString& Value);
};