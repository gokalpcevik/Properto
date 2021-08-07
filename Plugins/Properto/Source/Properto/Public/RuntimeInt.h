#pragma once
#include "RuntimePropertyBase.h"
#include "RuntimeInt.generated.h"


UCLASS(BlueprintType)
class URuntimeInt : public URuntimePropertyBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	int32 GetValue() const;

	UFUNCTION(BlueprintCallable)
	void SetValue(int32 Value);

	UFUNCTION(BlueprintCallable)
	bool HasClampMin() const;

	UFUNCTION(BlueprintCallable)
	bool HasClampMax() const;
	
	UFUNCTION(BlueprintCallable)
	int32 GetClampMin() const;

	UFUNCTION(BlueprintCallable)
	int32 GetClampMax() const;
};
