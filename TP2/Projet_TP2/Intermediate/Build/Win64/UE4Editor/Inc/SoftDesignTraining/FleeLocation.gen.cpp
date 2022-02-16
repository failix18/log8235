// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/FleeLocation.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFleeLocation() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_AFleeLocation_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_AFleeLocation();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void AFleeLocation::StaticRegisterNativesAFleeLocation()
	{
	}
	UClass* Z_Construct_UClass_AFleeLocation_NoRegister()
	{
		return AFleeLocation::StaticClass();
	}
	struct Z_Construct_UClass_AFleeLocation_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFleeLocation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FleeLocation.h" },
		{ "ModuleRelativePath", "FleeLocation.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFleeLocation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFleeLocation>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFleeLocation_Statics::ClassParams = {
		&AFleeLocation::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFleeLocation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFleeLocation()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFleeLocation_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFleeLocation, 2800186420);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<AFleeLocation>()
	{
		return AFleeLocation::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFleeLocation(Z_Construct_UClass_AFleeLocation, &AFleeLocation::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("AFleeLocation"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFleeLocation);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
