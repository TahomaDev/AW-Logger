// (c)2022 AWAIKO. All Rights Reserved.


#include "AWA_PrintString.h"

#include "AWA_Settings.h"
#include "GameFramework/GameUserSettings.h"
#include "Logging/LogVerbosity.h"
#include "Kismet/GameplayStatics.h"

void UAWA_PrintString::AWA_PrintString(const UObject* WorldContextObject, const FString& InString, bool bPrintToScreen,
                                       bool bPrintToLog, AWA_E_TypeMsg TypeMsg, float Duration, const FString& Prefix = "")
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST) // Do not Print in Shipping or Test
	
	FString Importance = "";
	FLinearColor MsgColor = FLinearColor::Blue;
	ELogVerbosity::Type ConsoleLogType = ELogVerbosity::Log;
	
	switch (TypeMsg)
	{
	case Debug:
		MsgColor = GetDefault<UAWA_Settings>()->Debug;
		Importance = "Debug";
		ConsoleLogType = ELogVerbosity::All;
		break;
		
	case Info:
		MsgColor = GetDefault<UAWA_Settings>()->Info;
		Importance = "Info";
		ConsoleLogType = ELogVerbosity::Display;
		break;
		
	case Warning:
		MsgColor = GetDefault<UAWA_Settings>()->Warning;
		Importance = "Warning";
		ConsoleLogType = ELogVerbosity::Warning;
		break;
		
	case Error:
		MsgColor = GetDefault<UAWA_Settings>()->Error;
		Importance = "Error";
		ConsoleLogType = ELogVerbosity::Error;
		break;
	default: ;
	}
	
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	FString Pfx = "";
	if (World)
	{
		if (World->WorldType == EWorldType::PIE)
		{
			switch(World->GetNetMode())
			{
			case NM_Client:
				Pfx = FString::Printf(TEXT("Client %d: "), GPlayInEditorID);
				break;
				
			case NM_DedicatedServer:
			case NM_ListenServer:
				Pfx = FString::Printf(TEXT("Server: "));
				break;
				
			case NM_Standalone:
				break;
			}
		}
	}

	FString CurrentPrefix = (Prefix.IsEmpty()) ? "" : "["+Prefix+"] ";

	FString CurrentImportance = (GetDefault<UAWA_Settings>()->ShowImportance && !Importance.IsEmpty())
								? FString::Printf(TEXT("[%s] "), *Importance)
								: "";

	FString FinalLogString = FString::Printf(TEXT("%s%s%s"), *CurrentImportance,  *CurrentPrefix, *InString);

	static const FBoolConfigValueHelper DisplayPrintStringSource(TEXT("Kismet"), TEXT("bLogPrintStringSource"), GEngineIni);
	if (GetDefault<UAWA_Settings>()->ShowSource && DisplayPrintStringSource)
	{
		const FString SourceObjectPrefix = FString::Printf(TEXT("[%s] "), *GetNameSafe(WorldContextObject));
		FinalLogString = Pfx + SourceObjectPrefix + FinalLogString;
	}
	else
	{
		FinalLogString = Pfx + FinalLogString;
	}

	if (bPrintToLog)
	{
		switch (TypeMsg)
		{
		case Debug:
			UE_LOG(LogBlueprintUserMessages, Log, TEXT("%s"), *FinalLogString);
			break;
			
		case Info:
			UE_LOG(LogBlueprintUserMessages, Display, TEXT("%s"), *FinalLogString);
			break;
			
		case Warning:
			UE_LOG(LogBlueprintUserMessages, Warning, TEXT("%s"), *FinalLogString);
			break;
			
		case Error:
			UE_LOG(LogBlueprintUserMessages, Error, TEXT("%s"), *FinalLogString);
			break;
		};
	}
	else
	{
		UE_LOG(LogBlueprintUserMessages, Verbose, TEXT("%s"), *FinalLogString);
	}

	// Also output to the screen, if possible
	if (bPrintToScreen)
	{
		if (GAreScreenMessagesEnabled)
		{
			if (GConfig && Duration < 0)
			{
				GConfig->GetFloat( TEXT("AWA_PrintString"), TEXT("PrintStringDuration < 0"), Duration, GEngineIni );
			}
			GEngine->AddOnScreenDebugMessage((uint64)-1, Duration, MsgColor.ToFColor(true), FinalLogString);
		}
		else
		{
			UE_LOG(LogBlueprint, VeryVerbose, TEXT("Screen messages disabled (!GAreScreenMessagesEnabled).  Cannot print to screen."));
		}
	}
#endif
}

void UAWA_PrintString::PrintString_Debug(const UObject* WorldContextObject, const FString& Message, const FString& Prefix)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	
	AWA_PrintString(WorldContextObject, Message, true, true, AWA_E_TypeMsg::Debug,
		GetDefault<UAWA_Settings>()->DebugShowDuration, Prefix);

#endif	
}

void UAWA_PrintString::PrintString_Error(const UObject* WorldContextObject, const FString& Message, const FString& Prefix)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	
	AWA_PrintString(WorldContextObject, Message, true, true, AWA_E_TypeMsg::Error,
		GetDefault<UAWA_Settings>()->ErrorShowDuration, Prefix);

#endif
}

void UAWA_PrintString::PrintString_Info(const UObject* WorldContextObject, const FString& Message, const FString& Prefix)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	
	AWA_PrintString(WorldContextObject, Message, true, true, AWA_E_TypeMsg::Info,
		GetDefault<UAWA_Settings>()->InfoShowDuration, Prefix);

#endif
}

void UAWA_PrintString::PrintString_Warning(const UObject* WorldContextObject, const FString& Message, const FString& Prefix)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	
	AWA_PrintString(WorldContextObject, Message, true, true, AWA_E_TypeMsg::Warning,
		GetDefault<UAWA_Settings>()->WarningShowDuration, Prefix);

#endif
}
