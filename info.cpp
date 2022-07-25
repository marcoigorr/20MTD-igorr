#include "pch.h"
#include "info.h"

#include "Addresses.h"

constexpr auto AVAIL = true;
constexpr auto UNAVAIL = false;
 
bool info::sHealth = UNAVAIL;
bool info::sAmmo = UNAVAIL;
bool info::sSpeedHack = UNAVAIL;
bool info::sDoubleXP = UNAVAIL;
bool info::sTimer = UNAVAIL;

void info::checkBadPointers()
{
	if (!cHealth->isInvincible) 
		info::sHealth = UNAVAIL;
	else
		info::sHealth = AVAIL;

	if (!cAmmo->infiniteAmmo) 
		info::sAmmo = UNAVAIL;
	else 
		info::sAmmo = AVAIL;

	if (!cPlayerController->movementSpeed) 
		info::sSpeedHack = UNAVAIL;
	else 
		info::sSpeedHack = AVAIL;

	if (!cStatMod->multiplierBonus) 
		info::sDoubleXP = UNAVAIL;
	else 
		info::sDoubleXP = AVAIL;

	if (!cGameTimer->timer)
		info::sTimer = UNAVAIL;
	else
		info::sTimer = AVAIL;
}


