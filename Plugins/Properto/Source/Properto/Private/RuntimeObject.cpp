#include "RuntimeObject.h"

void URuntimeObject::IterateFields(UObject* OwnerPtr)
{
	UClass* ClassPtr = OwnerPtr->GetClass();

	for(FProperty* Property : TFieldRange<FProperty>(ClassPtr,EFieldIteratorFlags::IncludeSuper))
	{
		ERuntimePropertyType const Type = URuntimeObject::GetType(Property);
		this->AddProperty(Property,OwnerPtr,Type);
	}
}

void URuntimeObject::AddProperty(FProperty* Property,UObject* OwnerPtr, ERuntimePropertyType Type)
{
	switch (Type)
	{
	case ERuntimePropertyType::Unsupported:
	{
		break;
	}
	case ERuntimePropertyType::Int:
	{
		URuntimeInt* RuntimeIntPtr = NewObject<URuntimeInt>();
		RuntimeIntPtr->Init(OwnerPtr, Property);
		RuntimeIntPtr->m_Type = ERuntimePropertyType::Int;
		m_RuntimeProperties.Add(RuntimeIntPtr);
		break;
	}
	case ERuntimePropertyType::Float:
	{
		URuntimeFloat* RuntimeFloatPtr = NewObject<URuntimeFloat>();
		RuntimeFloatPtr->Init(OwnerPtr, Property);
		RuntimeFloatPtr->m_Type = ERuntimePropertyType::Float;
		m_RuntimeProperties.Add(RuntimeFloatPtr);
		break;
	}
	case ERuntimePropertyType::Bool:
	{
		URuntimeBool* RuntimeBoolPtr = NewObject<URuntimeBool>();
		RuntimeBoolPtr->Init(OwnerPtr, Property);
		RuntimeBoolPtr->m_Type = ERuntimePropertyType::Bool;
		m_RuntimeProperties.Add(RuntimeBoolPtr);
		break;
	}
	case ERuntimePropertyType::String:
	{
		URuntimeString* RuntimeStrPtr = NewObject<URuntimeString>();
		RuntimeStrPtr->Init(OwnerPtr, Property);
		RuntimeStrPtr->m_Type = ERuntimePropertyType::String;
		m_RuntimeProperties.Add(RuntimeStrPtr);
		break;
	}
	case ERuntimePropertyType::Vector:
	{
		URuntimeVector* RuntimeVectorPtr = NewObject<URuntimeVector>();
		RuntimeVectorPtr->Init(OwnerPtr, Property);
		RuntimeVectorPtr->m_Type = ERuntimePropertyType::Vector;
		m_RuntimeProperties.Add(RuntimeVectorPtr);
		break;
	}
	case ERuntimePropertyType::Rotator:
	{
		URuntimeRotator* RuntimeRotatorPtr = NewObject<URuntimeRotator>();
		RuntimeRotatorPtr->Init(OwnerPtr, Property);
		RuntimeRotatorPtr->m_Type = ERuntimePropertyType::Rotator;
		m_RuntimeProperties.Add(RuntimeRotatorPtr);
		break;
	}
	case ERuntimePropertyType::Struct:
	{
		
		break;
	}

	default: break;
	}
}

ERuntimePropertyType URuntimeObject::GetType(FProperty* PropertyPtr)
{
	FBoolProperty* BoolPropertyPtr = CastField<FBoolProperty>(PropertyPtr);
	if (BoolPropertyPtr)
		return ERuntimePropertyType::Bool;
	
	FIntProperty* IntPropertyPtr = CastField<FIntProperty>(PropertyPtr);
	if (IntPropertyPtr)
		return ERuntimePropertyType::Int;

	FFloatProperty* FloatPropertyPtr = CastField<FFloatProperty>(PropertyPtr);
	if (FloatPropertyPtr)
		return ERuntimePropertyType::Float;

	FStrProperty* StrPropertyPtr = CastField<FStrProperty>(PropertyPtr);
	if(StrPropertyPtr)
		return ERuntimePropertyType::String;
	FStructProperty* StructPropertyPtr = CastField<FStructProperty>(PropertyPtr);
	if(StructPropertyPtr)
	{
		if (StructPropertyPtr->Struct == TBaseStructure<FVector>::Get())
		{
			return ERuntimePropertyType::Vector;
		}
		else if (StructPropertyPtr->Struct == TBaseStructure<FRotator>::Get())
		{
			return ERuntimePropertyType::Rotator;
		}
		else return ERuntimePropertyType::Struct;
	}
	
	return ERuntimePropertyType::Unsupported;
}
