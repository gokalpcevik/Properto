#pragma once
#include "RuntimePropertyBase.h"
#include "RuntimeFloat.generated.h"


UCLASS(BlueprintType)
class URuntimeFloat : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	float GetValue() const;
	
	UFUNCTION(BlueprintCallable)
	void SetValue(float Value);

	UFUNCTION(BlueprintCallable)
	bool HasClampMin() const;

	UFUNCTION(BlueprintCallable)
	bool HasClampMax() const;

	UFUNCTION(BlueprintCallable)
	float GetClampMin() const;
	
	UFUNCTION(BlueprintCallable)
	float GetClampMax() const;
};
