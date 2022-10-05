// (c)2022 AWAIKO. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AWA_Settings.generated.h"

UCLASS(config = Editor, defaultconfig, meta = (DisplayName = "AWAIKO"))
class AW_LOGGER_API UAWA_Settings : public UDeveloperSettings
{
	GENERATED_BODY()
public:	

	// Global settings

	UPROPERTY(config, EditAnywhere, Category="Logger|Globals")
	bool ShowImportance = true;
	UPROPERTY(config, EditAnywhere, Category="Logger|Globals")
	bool ShowSource = true;

	
	// Color settings
	UPROPERTY(config, EditAnywhere, Category="Logger|Colors|Info")
	FLinearColor Info = FLinearColor(128, 128, 128);
	UPROPERTY(config, EditAnywhere, DisplayName="Duration", Category="Logger|Colors|Info")
	float InfoShowDuration = 20.f;
	
	UPROPERTY(config, EditAnywhere, Category="Logger|Colors|Error")
	FLinearColor Error = FLinearColor(255, 0, 0);
	UPROPERTY(config, EditAnywhere, DisplayName="Duration", Category="Logger|Colors|Error")
	float ErrorShowDuration = 50.f;
	
	UPROPERTY(config, EditAnywhere, Category="Logger|Colors|Warning")
	FLinearColor Warning = FLinearColor(255, 255, 0);
	UPROPERTY(config, EditAnywhere, DisplayName="Duration", Category="Logger|Colors|Warning")
	float WarningShowDuration = 50.f;
	
	UPROPERTY(config, EditAnywhere, Category="Logger|Colors|Debug")
	FLinearColor Debug = FLinearColor(255, 0, 255);
	UPROPERTY(config, EditAnywhere, DisplayName="Duration", Category="Logger|Colors|Debug")
	float DebugShowDuration = 50.f;

};
