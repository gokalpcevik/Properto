#pragma once
#include "RuntimePropertyBase.h"
#include "RuntimeFloat.h"
#include "RuntimeInt.h"
#include "RuntimeString.h"
#include "RuntimeVector.h"
#include "RuntimeRotator.h"
#include "RuntimeBool.h"
#include "RuntimeStruct.h"
#include "RuntimeObject.generated.h"

UCLASS(BlueprintType)
class URuntimeObject : public UObject
{
public:
	GENERATED_BODY()

	//Iterates over all the fields and inits m_RuntimeProperties.
	UFUNCTION(BlueprintCallable)
	void IterateFields(UObject* OwnerPtr);

	void AddProperty(FProperty* Property,UObject* OwnerPtr,ERuntimePropertyType Type);

	static ERuntimePropertyType GetType(FProperty* PropertyPtr);
	
	UPROPERTY(BlueprintReadOnly,meta = (DisplayName = "Property Array"))
	TArray<URuntimePropertyBase*> m_RuntimeProperties;
};