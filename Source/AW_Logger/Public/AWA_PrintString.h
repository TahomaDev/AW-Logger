// (c)2022 AWAIKO. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AWA_PrintString.generated.h"

enum AWA_E_TypeMsg
{
	Debug,
	Info,
	Warning,
	Error,
};

UCLASS()
class AW_LOGGER_API UAWA_PrintString : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	/** Main print log function */
	static void AWA_PrintString(const UObject* WorldContextObject, const FString& InString, bool bPrintToScreen,
								bool bPrintToLog, AWA_E_TypeMsg TypeMesssage, float Duration,
								const FLinearColor MsgColor,
								const FString& Importance, const FString& Prefix);

public:

	/**
	 * Child functions
	 **/

	/** Print Debug */
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext, Keywords = "print debug log", AdvancedDisplay = "2", DevelopmentOnly), Category="AWAIKO|Logger|DebugPrints")
	static void PrintString_Debug(const UObject* WorldContextObject,
		const FString& Message = FString("Hello"), const FString& Prefix = FString(""),
		float Duration = -1);

	/** Print Error */
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext, Keywords = "print error log", AdvancedDisplay = "2"), Category="AWAIKO|Logger|DebugPrints")
	static void PrintString_Error(const UObject* WorldContextObject,
		const FString& Message = FString("Hello"), const FString& Prefix = FString(""),
		float Duration = -1);

	/** Print Info */
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext, Keywords = "print info log", AdvancedDisplay = "2", DevelopmentOnly), Category="AWAIKO|Logger|DebugPrints")
	static void PrintString_Info(const UObject* WorldContextObject,
		const FString& Message = FString("Hello"), const FString& Prefix = FString(""),
		float Duration = -1);

	/** Print Warning */
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext, Keywords = "print warning log", AdvancedDisplay = "2"), Category="AWAIKO|Logger|DebugPrints")
	static void PrintString_Warning(const UObject* WorldContextObject,
		const FString& Message = FString("Hello"), const FString& Prefix = FString(""),
		float Duration = -1);

};
