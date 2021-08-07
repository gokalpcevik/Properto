#include "RuntimePropertyBase.h"

void URuntimePropertyBase::Init(UObject* OwnerPtr, FProperty* PropertyPtr)
{
	m_OwnerPtr = OwnerPtr;
	m_PropertyPtr = PropertyPtr;
}

FString URuntimePropertyBase::GetPropertyName() const
{
	return m_PropertyPtr->GetName();
}

FString URuntimePropertyBase::GetPropertyNameCpp() const
{
	return m_PropertyPtr->GetNameCPP();
}

FString URuntimePropertyBase::GetCPPType() const
{
	return m_PropertyPtr->GetCPPType();
}

bool URuntimePropertyBase::IsReadOnly() const
{
	return (m_PropertyPtr->GetPropertyFlags() & EPropertyFlags::CPF_BlueprintReadOnly) == 1;
}
