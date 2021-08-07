#pragma once

#include "RuntimePropertyBase.h"
#include "RuntimeRotator.generated.h"

UCLASS(BlueprintType)
class URuntimeRotator : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FRotator GetValue() const;
	
	UFUNCTION(BlueprintCallable)
	void SetValue(const FRotator& Value);
};