#include "pch.h"
#include "console.h"

void Console::Init()
{
	AllocConsole();
	freopen_s(&cmd->f, "CONOUT$", "w", stdout);
	SetConsoleTitle(L"20MTD Cheats");
}

void Console::Stop()
{
	fclose(cmd->f);
	FreeConsole();
}

Console* cmd = new Console();