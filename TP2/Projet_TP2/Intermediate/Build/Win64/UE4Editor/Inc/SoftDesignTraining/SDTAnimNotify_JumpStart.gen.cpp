// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTAnimNotify_JumpStart.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTAnimNotify_JumpStart() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void USDTAnimNotify_JumpStart::StaticRegisterNativesUSDTAnimNotify_JumpStart()
	{
	}
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart_NoRegister()
	{
		return USDTAnimNotify_JumpStart::StaticClass();
	}
	struct Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "SDTAnimNotify_JumpStart.h" },
		{ "ModuleRelativePath", "SDTAnimNotify_JumpStart.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USDTAnimNotify_JumpStart>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::ClassParams = {
		&USDTAnimNotify_JumpStart::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001120A0u,
		METADATA_PARAMS(Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USDTAnimNotify_JumpStart()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USDTAnimNotify_JumpStart_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USDTAnimNotify_JumpStart, 3282538013);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<USDTAnimNotify_JumpStart>()
	{
		return USDTAnimNotify_JumpStart::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USDTAnimNotify_JumpStart(Z_Construct_UClass_USDTAnimNotify_JumpStart, &USDTAnimNotify_JumpStart::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("USDTAnimNotify_JumpStart"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USDTAnimNotify_JumpStart);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
