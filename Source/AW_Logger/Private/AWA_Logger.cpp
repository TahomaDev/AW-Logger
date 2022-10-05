// (c)2022 AWAIKO. All Rights Reserved.

#include "AWA_Logger.h"

#define LOCTEXT_NAMESPACE "FAW_LoggerModule"

void FAWA_LoggerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FAWA_LoggerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAWA_LoggerModule, AW_Logger)