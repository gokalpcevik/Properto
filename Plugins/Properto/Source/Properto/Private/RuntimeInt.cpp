#include "RuntimeInt.h"

int32 URuntimeInt::GetValue() const
{
	FIntProperty* IntPropertyPtr = CastField<FIntProperty>(m_PropertyPtr);
	if (IntPropertyPtr && m_OwnerPtr)
		return IntPropertyPtr->GetPropertyValue(IntPropertyPtr->ContainerPtrToValuePtr<int32>(m_OwnerPtr));
	else return 0;
}

void URuntimeInt::SetValue(int32 Value)
{
	FIntProperty* IntPropertyPtr = CastField<FIntProperty>(m_PropertyPtr);
	if(IntPropertyPtr && m_OwnerPtr) 
		IntPropertyPtr->SetPropertyValue(IntPropertyPtr->ContainerPtrToValuePtr<int32>(m_OwnerPtr),Value);
}

bool URuntimeInt::HasClampMin() const
{
	return m_PropertyPtr->HasMetaData(TEXT("ClampMin"));
}

bool URuntimeInt::HasClampMax() const
{
	return m_PropertyPtr->HasMetaData(TEXT("ClampMax"));
}

int32 URuntimeInt::GetClampMin() const
{
	return m_PropertyPtr->GetIntMetaData(TEXT("ClampMin"));
}

int32 URuntimeInt::GetClampMax() const
{
	return m_PropertyPtr->GetIntMetaData(TEXT("ClampMax"));
}

