#pragma once

#include "RuntimePropertyBase.h"
#include "RuntimeBool.generated.h"

UCLASS(BlueprintType)
class URuntimeBool : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	bool GetValue() const;

	UFUNCTION(BlueprintCallable)
	void SetValue(bool Value);
};