// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SoftDesignTrainingGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftDesignTrainingGameMode() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
// End Cross Module References
	void ASoftDesignTrainingGameMode::StaticRegisterNativesASoftDesignTrainingGameMode()
	{
	}
	UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode_NoRegister()
	{
		return ASoftDesignTrainingGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SoftDesignTrainingGameMode.h" },
		{ "ModuleRelativePath", "SoftDesignTrainingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftDesignTrainingGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::ClassParams = {
		&ASoftDesignTrainingGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftDesignTrainingGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASoftDesignTrainingGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASoftDesignTrainingGameMode, 4035504184);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASoftDesignTrainingGameMode>()
	{
		return ASoftDesignTrainingGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASoftDesignTrainingGameMode(Z_Construct_UClass_ASoftDesignTrainingGameMode, &ASoftDesignTrainingGameMode::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASoftDesignTrainingGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftDesignTrainingGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
