#pragma once

#include "RuntimePropertyBase.h"
#include "RuntimeVector.generated.h"

UCLASS(BlueprintType)
class URuntimeVector : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FVector GetValue() const;

	UFUNCTION(BlueprintCallable)
	void SetValue(const FVector& Value);
};
