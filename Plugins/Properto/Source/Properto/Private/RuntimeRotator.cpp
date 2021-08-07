#include "RuntimeRotator.h"

FRotator URuntimeRotator::GetValue() const
{
	FStructProperty* StructPropertyPtr = CastField<FStructProperty>(m_PropertyPtr);
	if (StructPropertyPtr && m_OwnerPtr)
	{
		FRotator* Rotator = StructPropertyPtr->ContainerPtrToValuePtr<FRotator>(m_OwnerPtr);
		return MoveTempIfPossible(*Rotator);
	}
	else return FRotator();
}

void URuntimeRotator::SetValue(const FRotator& Value)
{
	FStructProperty* StructPropertyPtr = CastField<FStructProperty>(m_PropertyPtr);
	if (StructPropertyPtr && m_OwnerPtr)
	{
		FRotator* Rotator = StructPropertyPtr->ContainerPtrToValuePtr<FRotator>(m_OwnerPtr);
		Rotator->Pitch = Value.Pitch;
		Rotator->Yaw   = Value.Yaw;
		Rotator->Roll  = Value.Roll;
	}
}
