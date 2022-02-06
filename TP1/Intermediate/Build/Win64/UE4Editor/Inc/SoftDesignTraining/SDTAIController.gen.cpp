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
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_SoftDesignTraining();
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_drawDebug_MetaData[];
#endif
		static void NewProp_drawDebug_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_drawDebug;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_radiusDetection_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_radiusDetection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_visionDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_visionDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_hitDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_accY_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_accY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_accX_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_accX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_maxSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_maxSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASDTAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_SoftDesignTraining,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "AI" },
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SDTAIController.h" },
		{ "ModuleRelativePath", "SDTAIController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "// Radius of the sphere cast sent\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Radius of the sphere cast sent" },
	};
#endif
	void Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug_SetBit(void* Obj)
	{
		((ASDTAIController*)Obj)->drawDebug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug = { "drawDebug", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASDTAIController), &Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_radiusDetection_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "10.0" },
		{ "Comment", "// Radius of the sphere cast sent\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Radius of the sphere cast sent" },
		{ "UIMax", "10000.0" },
		{ "UIMin", "10.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_radiusDetection = { "radiusDetection", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, radiusDetection), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_radiusDetection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_radiusDetection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_visionDistance_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "10000.0" },
		{ "ClampMin", "10.0" },
		{ "Comment", "// Distance where the pawn sees\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Distance where the pawn sees" },
		{ "UIMax", "10000.0" },
		{ "UIMin", "10.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_visionDistance = { "visionDistance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, visionDistance), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_visionDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_visionDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_hitDistance_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "1000.0" },
		{ "ClampMin", "10.0" },
		{ "Comment", "// Distance where the wall is detected\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Distance where the wall is detected" },
		{ "UIMax", "1000.0" },
		{ "UIMin", "10.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_hitDistance = { "hitDistance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, hitDistance), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_hitDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_hitDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_accY_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Pawn's acceleration along Y axis\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Pawn's acceleration along Y axis" },
		{ "UIMax", "100.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_accY = { "accY", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, accY), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_accY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_accY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_accX_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Pawn's acceleration along X axis\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Pawn's acceleration along X axis" },
		{ "UIMax", "100.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_accX = { "accX", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, accX), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_accX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_accX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASDTAIController_Statics::NewProp_maxSpeed_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMax", "100.0" },
		{ "ClampMin", "10.0" },
		{ "Comment", "// Pawn's max speed\n" },
		{ "ModuleRelativePath", "SDTAIController.h" },
		{ "ToolTip", "Pawn's max speed" },
		{ "UIMax", "100.0" },
		{ "UIMin", "10.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASDTAIController_Statics::NewProp_maxSpeed = { "maxSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASDTAIController, maxSpeed), METADATA_PARAMS(Z_Construct_UClass_ASDTAIController_Statics::NewProp_maxSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASDTAIController_Statics::NewProp_maxSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASDTAIController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_drawDebug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_radiusDetection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_visionDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_hitDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_accY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_accX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASDTAIController_Statics::NewProp_maxSpeed,
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
	IMPLEMENT_CLASS(ASDTAIController, 3519878312);
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
