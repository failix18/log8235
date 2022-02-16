// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SoftDesignTraining/SDTAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSDTAIController() {}
// Cross Module References
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTAIController_NoRegister();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTAIController();
	SOFTDESIGNTRAINING_API UClass* Z_Construct_UClass_ASDTBaseAIController();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	void ASDTAIController::StaticRegisterNativesASDTAIController()
	{
	}
	UClass* Z_Construct_UClass_ASDTAIController_NoRegister()
	{
		return ASDTAIController::StaticClass();
	}
	struct Z_Construct_UClass_ASDTAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Landing_MetaData[];
#endif
		static void NewProp_Landing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Landing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InAir_MetaData[];
#endif
		static void NewProp_InAir_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_InAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AtJumpSegment_MetaData[];
#endif
		static void NewProp_AtJumpSegment_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AtJumpSegment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpApexHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpApexHeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpCurve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_JumpCurve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleForwardStartingOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_DetectionCapsuleHalfLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_DetectionCapsuleHalfLength;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASDTBaseAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "AI" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SDTAIController.h" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->Landing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing = { "Landing", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->InAir = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir = { "InAir", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->AtJumpSegment = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment = { "AtJumpSegment", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed = { "JumpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpSpeed), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight = { "JumpApexHeight", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpApexHeight), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve = { "JumpCurve", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, JumpCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset = { "m_DetectionCapsuleForwardStartingOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleForwardStartingOffset), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius = { "m_DetectionCapsuleRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleRadius), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength = { "m_DetectionCapsuleHalfLength", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, m_DetectionCapsuleHalfLength), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTAIController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_Landing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_InAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_AtJumpSegment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpApexHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_JumpCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleForwardStartingOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_m_DetectionCapsuleHalfLength,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASDTAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASDTAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASDTAIController_Statics::ClassParams = {
		&ASDTAIController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASDTAIController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASDTAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASDTAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASDTAIController, 2965554639);
	template<> SOFTDESIGNTRAINING_API UClass* StaticClass<ASDTAIController>()
	{
		return ASDTAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASDTAIController(Z_Construct_UClass_ASDTAIController, &ASDTAIController::StaticClass, TEXT("/Script/SoftDesignTraining"), TEXT("ASDTAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASDTAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
