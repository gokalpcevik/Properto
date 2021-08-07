#include "RuntimeVector.h"

FVector URuntimeVector::GetValue() const
{
	FStructProperty* StructPropertyPtr = CastField<FStructProperty>(m_PropertyPtr);
	if (StructPropertyPtr && m_OwnerPtr)
	{
		auto* Vector = StructPropertyPtr->ContainerPtrToValuePtr<FVector>(m_OwnerPtr);
		return MoveTempIfPossible(*Vector);
	}
	else return FVector();
}

void URuntimeVector::SetValue(const FVector& Value)
{
	FStructProperty* StructPropertyPtr = CastField<FStructProperty>(m_PropertyPtr);
	if(StructPropertyPtr && m_OwnerPtr)
	{
		FVector* Vector = StructPropertyPtr->ContainerPtrToValuePtr<FVector>(m_OwnerPtr);
		Vector->X = Value.X;
		Vector->Y = Value.Y;
		Vector->Z = Value.Z;
	}
}
