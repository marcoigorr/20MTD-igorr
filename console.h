#pragma once

class Console
{
public:
	FILE* f;

	static void Init();
	static void Stop();
};

extern Console* cmd;
