#include "pch.h"
#include "console.h"

static console c;

void console::init()
{
	AllocConsole();
	freopen_s(&c.f, "CONOUT$", "w", stdout);
}

void console::stop()
{
	fclose(c.f);
	FreeConsole();
}
