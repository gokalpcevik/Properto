#include "RuntimeBool.h"

bool URuntimeBool::GetValue() const
{
	FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(m_PropertyPtr);
	if (BoolPropertyPtr && m_OwnerPtr)
		return BoolPropertyPtr->GetPropertyValue(BoolPropertyPtr->ContainerPtrToValuePtr<bool>(m_OwnerPtr));
	else return false;
}

void URuntimeBool::SetValue(bool Value)
{
	FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(m_PropertyPtr);
	if (BoolPropertyPtr && m_OwnerPtr)
		BoolPropertyPtr->SetPropertyValue(BoolPropertyPtr->ContainerPtrToValuePtr<bool>(m_OwnerPtr), Value);
}
