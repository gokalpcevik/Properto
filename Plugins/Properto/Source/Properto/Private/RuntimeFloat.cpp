#include "RuntimeFloat.h"

float URuntimeFloat::GetValue() const
{
	FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(m_PropertyPtr);
	if (FloatPropertyPtr && m_OwnerPtr)
		return FloatPropertyPtr->GetPropertyValue(FloatPropertyPtr->ContainerPtrToValuePtr<float>(m_OwnerPtr));
	else return 0.0f;
}	

void URuntimeFloat::SetValue(float Value)
{
	FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(m_PropertyPtr);
	if(FloatPropertyPtr && m_OwnerPtr)
		FloatPropertyPtr->SetPropertyValue(FloatPropertyPtr->ContainerPtrToValuePtr<float>(m_OwnerPtr), Value);
}

bool URuntimeFloat::HasClampMin() const
{
	return m_PropertyPtr->HasMetaData(TEXT("ClampMin"));
}

bool URuntimeFloat::HasClampMax() const
{
	return m_PropertyPtr->HasMetaData(TEXT("ClampMax"));
}

float URuntimeFloat::GetClampMin() const
{
	return m_PropertyPtr->GetIntMetaData(TEXT("ClampMin"));
}

float URuntimeFloat::GetClampMax() const
{
	return m_PropertyPtr->GetIntMetaData(TEXT("ClampMax"));
}

