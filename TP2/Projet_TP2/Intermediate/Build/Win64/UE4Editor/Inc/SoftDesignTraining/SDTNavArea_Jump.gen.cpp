// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTNavArea_Jump.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTNavArea_Jump() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTNavArea_Jump_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_USDTNavArea_Jump();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavArea();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void USDTNavArea_Jump::StaticRegisterNativesUSDTNavArea_Jump()
	{
	}
	UClass* Z_Construct_UClass_USDTNavArea_Jump_NoRegister()
	{
		return USDTNavArea_Jump::StaticClass();
	}
	struct Z_Construct_UClass_USDTNavArea_Jump_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USDTNavArea_Jump_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UNavArea,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SDTNavArea_Jump.h" },
		{ "ModuleRelativePath", "SDTNavArea_Jump.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USDTNavArea_Jump_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USDTNavArea_Jump>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USDTNavArea_Jump_Statics::ClassParams = {
		&USDTNavArea_Jump::StaticClass,
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
		0x003000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USDTNavArea_Jump_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USDTNavArea_Jump()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USDTNavArea_Jump_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USDTNavArea_Jump, 2588472625);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<USDTNavArea_Jump>()
	{
		return USDTNavArea_Jump::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USDTNavArea_Jump(Z_Construct_UClass_USDTNavArea_Jump, &USDTNavArea_Jump::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("USDTNavArea_Jump"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USDTNavArea_Jump);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
