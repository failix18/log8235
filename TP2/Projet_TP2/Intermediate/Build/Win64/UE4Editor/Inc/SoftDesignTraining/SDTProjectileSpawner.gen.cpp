// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTProjectileSpawner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTProjectileSpawner() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectileSpawner_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectileSpawner();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTProjectile_NoRegister();
// End Cross Module References
	void ASDTProjectileSpawner::StaticRegisterNativesASDTProjectileSpawner()
	{
	}
	UClass* Z_Construct_UClass_ASDTProjectileSpawner_NoRegister()
	{
		return ASDTProjectileSpawner::StaticClass();
	}
	struct Z_Construct_UClass_ASDTProjectileSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_MaxSimultaneousProjectiles_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_MaxSimultaneousProjectiles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ShotSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_ShotSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ShotDirection_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_ShotDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_TimeToShoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_TimeToShoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SDTProjectileBP_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_m_SDTProjectileBP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTProjectileSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "SDTProjectileSpawner.h" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles = { "m_MaxSimultaneousProjectiles", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_MaxSimultaneousProjectiles), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed = { "m_ShotSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_ShotSpeed), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection = { "m_ShotDirection", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_ShotDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData[] = {
		{ "Category", "SDTProjectileSpawner" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot = { "m_TimeToShoot", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_TimeToShoot), METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData[] = {
		{ "Category", "ActorSpawning" },
		{ "ModuleRelativePath", "SDTProjectileSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP = { "m_SDTProjectileBP", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTProjectileSpawner, m_SDTProjectileBP), Z_Construct_UClass_ASDTProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_MaxSimultaneousProjectiles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_ShotDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_TimeToShoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTProjectileSpawner_Statics::NewProp_m_SDTProjectileBP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTProjectileSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTProjectileSpawner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASDTProjectileSpawner_Statics::ClassParams = {
		&ASDTProjectileSpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTProjectileSpawner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTProjectileSpawner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASDTProjectileSpawner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASDTProjectileSpawner, 1719764729);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTProjectileSpawner>()
	{
		return ASDTProjectileSpawner::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASDTProjectileSpawner(Z_Construct_UClass_ASDTProjectileSpawner, &ASDTProjectileSpawner::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASDTProjectileSpawner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTProjectileSpawner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
