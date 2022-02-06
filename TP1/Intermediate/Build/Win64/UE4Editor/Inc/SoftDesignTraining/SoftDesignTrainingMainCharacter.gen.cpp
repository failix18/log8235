// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SoftDesignTrainingMainCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftDesignTrainingMainCharacter() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASoftDesignTrainingCharacter();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void ASoftDesignTrainingMainCharacter::StaticRegisterNativesASoftDesignTrainingMainCharacter()
	{
	}
	UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter_NoRegister()
	{
		return ASoftDesignTrainingMainCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PoweredUpMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_PoweredUpMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PowerUpDuration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_PowerUpDuration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_TopDownCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_TopDownCameraComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASoftDesignTrainingCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SoftDesignTrainingMainCharacter.h" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial = { "m_PoweredUpMaterial", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_PoweredUpMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration = { "m_PowerUpDuration", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_PowerUpDuration), METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom = { "m_CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SoftDesignTrainingMainCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent = { "m_TopDownCameraComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftDesignTrainingMainCharacter, m_TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PoweredUpMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_PowerUpDuration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::NewProp_m_TopDownCameraComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftDesignTrainingMainCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::ClassParams = {
		&ASoftDesignTrainingMainCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftDesignTrainingMainCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASoftDesignTrainingMainCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASoftDesignTrainingMainCharacter, 2289198475);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASoftDesignTrainingMainCharacter>()
	{
		return ASoftDesignTrainingMainCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASoftDesignTrainingMainCharacter(Z_Construct_UClass_ASoftDesignTrainingMainCharacter, &ASoftDesignTrainingMainCharacter::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASoftDesignTrainingMainCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftDesignTrainingMainCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
