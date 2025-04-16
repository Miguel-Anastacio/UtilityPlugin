// Copyright 2024 An@stacioDev All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "AssetCreatorFunctionLibrary.generated.h"

/**
 * Collection of functions to create assets through code, only available in c++
 */
class UObject;
UCLASS(DisplayName="Asset Creator Function Library")
class UTILITYMODULEEDITOR_API UAtkAssetCreatorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static UObject* CreateAssetInPackageWithUniqueName(const FString& PackagePath, UClass* AssetClass, const FString& BaseName ,UFactory* Factory = nullptr);
	
    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static UObject* CreateAsset(const FString& AssetPath, UClass* AssetClass, UFactory* Factory, bool& bOutSuccess, FString& OutInfoMessage);
	
    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static UTexture2D* CreateTextureAssetFromBuffer(const FString& AssetPath, const TArray<uint8>& Data, uint32 Width, uint32 Height,
											bool& bOutSuccess, FString& OutInfoMessage);
	
	static UTexture2D* CreateTextureAssetFromBuffer(const FString& AssetPath, uint8* Data, uint32 Width, uint32 Height,
											bool& bOutSuccess, FString& OutInfoMessage);

	static FString CreateUniqueAssetNameInPackage(const FString& PackagePath, const FString& BaseAssetName,UClass* AssetClass);

    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static UBlueprint* CreateBlueprintDerivedFromClass(const FString& PackagePath, UClass* Class,const FString& AssetName);

    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static bool SaveAsset(const FString& AssetPath, FString& OutInfoMessage);

    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static TArray<UObject*> GetModifiedAssets(bool& OutResult, FString& OutInfoMessage);

    UFUNCTION(BlueprintCallable, Category = "AssetCreator")
	static bool SaveModifiedAssets(bool bPrompt, FString& OutInfoMessage);
	
};
