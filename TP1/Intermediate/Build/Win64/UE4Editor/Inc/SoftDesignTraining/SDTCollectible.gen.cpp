// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTCollectible.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTCollectible() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTCollectible_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTCollectible();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTCollectible::StaticRegisterNativesASDTCollectible()
	{
	}
	UClass* Z_Construct_UClass_ASDTCollectible_NoRegister()
	{
		return ASDTCollectible::StaticClass();
	}
	struct Z_Construct_UClass_ASDTCollectible_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMoveable_MetaData[];
#endif
		static void NewProp_isMoveable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMoveable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_CollectCooldownDuration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_CollectCooldownDuration;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTCollectible_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTCollectible.h" },
		{ "ModuleRelativePath", "SDTCollectible.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTCollectible.h" },
	};
#endif
	void Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable_SetBit(void* Obj)
	{
		((ASDTCollectible*)Obj)->isMoveable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable = { "isMoveable", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTCollectible), &Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTCollectible.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration = { "m_CollectCooldownDuration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTCollectible, m_CollectCooldownDuration), METADATA_PARAMS(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTCollectible_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTCollectible_Statics::NewProp_isMoveable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTCollectible_Statics::NewProp_m_CollectCooldownDuration,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTCollectible_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTCollectible>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASDTCollectible_Statics::ClassParams = {
		&ASDTCollectible::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTCollectible_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTCollectible_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTCollectible()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASDTCollectible_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASDTCollectible, 3519265737);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTCollectible>()
	{
		return ASDTCollectible::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASDTCollectible(Z_Construct_UClass_ASDTCollectible, &ASDTCollectible::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASDTCollectible"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTCollectible);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
