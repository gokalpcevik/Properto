#pragma once

#include "RuntimePropertyBase.generated.h"

UENUM(Blueprintable)
enum class ERuntimePropertyType : uint8
{
	Unsupported,
	Int,
	Float,
	Bool,
	String,
	Vector,
	Rotator,
	Struct
};

UCLASS(BlueprintType)
class URuntimePropertyBase : public UObject
{
public:
	GENERATED_BODY()

	// The parameters should not ever be null.
	virtual void Init(UObject* OwnerPtr, FProperty* PropertyPtr);

	UFUNCTION(BlueprintCallable)
	FString GetPropertyName() const;
	UFUNCTION(BlueprintCallable)
	FString GetPropertyNameCpp() const;
	UFUNCTION(BlueprintCallable)
	FString GetCPPType() const;
	UFUNCTION(BlueprintCallable)
	bool IsReadOnly() const;
	
public:
	UPROPERTY(BlueprintReadOnly,meta=(DisplayName = "Property Type"))
	ERuntimePropertyType m_Type = ERuntimePropertyType::Unsupported;

protected:
	FProperty* m_PropertyPtr = nullptr;
	UObject* m_OwnerPtr = nullptr;
};
