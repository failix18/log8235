// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTProjectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTProjectile() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASDTProjectile::StaticRegisterNativesASDTProjectile()
	{
	}
	UClass* Z_Construct_UClass_ASDTProjectile_NoRegister()
	{
		return ASDTProjectile::StaticClass();
	}
	struct Z_Construct_UClass_ASDTProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_TimeToLive_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_TimeToLive;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTProjectile.h" },
		{ "ModuleRelativePath", "SDTProjectile.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData[] = {
		{ "Category", "SDTProjectile" },
		{ "ModuleRelativePath", "SDTProjectile.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive = { "m_TimeToLive", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectile, m_TimeToLive), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTProjectile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectile_Statics::NewProp_m_TimeToLive,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTProjectile>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASDTProjectile_Statics::ClassParams = {
		&ASDTProjectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTProjectile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTProjectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASDTProjectile_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASDTProjectile, 3275999761);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTProjectile>()
	{
		return ASDTProjectile::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASDTProjectile(Z_Construct_UClass_ASDTProjectile, &ASDTProjectile::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASDTProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTProjectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
