#include "RuntimeString.h"

FString URuntimeString::GetValue() const
{
	FStrProperty* StrPropertyPtr = CastField<FStrProperty>(m_PropertyPtr);
	if (StrPropertyPtr && m_OwnerPtr)
		return StrPropertyPtr->GetPropertyValue(StrPropertyPtr->ContainerPtrToValuePtr<void>(m_OwnerPtr));
	else return FString();
}

void URuntimeString::SetValue(const FString& Value)
{
	FStrProperty* StrPropertyPtr = CastField<FStrProperty>(m_PropertyPtr);
	if(StrPropertyPtr && m_OwnerPtr)
		StrPropertyPtr->SetPropertyValue(StrPropertyPtr->ContainerPtrToValuePtr<void>(m_OwnerPtr), Value);
}
