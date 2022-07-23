#pragma once

class Options
{
public:
	bool isEjecting = false;

	// cheat features
	bool bMenu = true;
	bool bHealth = false, bAmmo = false, bSpeedHack = false, bDoubleXP = false;

	bool* features[4] = {
		&bHealth, &bAmmo, &bSpeedHack, &bDoubleXP,
	};

	 static void SetAllFalse();
	 static void SetAllTrue();

	 class FeatureValues
	 {
	 public:
		 int vMovementSpeed = 3;
	 };
};

extern Options* options;
extern Options::FeatureValues* fValues;