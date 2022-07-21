#pragma once

class Options
{
public:
	bool isEjecting = false;

	// cheat features
	bool bMenu = true;
	bool bHealth = false, bAmmo = false, bSpeedHack = false, bDoubleXP = false;

	bool features[5] = {
		bMenu,
		bHealth, bAmmo, bSpeedHack, bDoubleXP,
	};

	 static void SetAllFalse();
	 static void SetAllTrue();
};

extern Options* options;