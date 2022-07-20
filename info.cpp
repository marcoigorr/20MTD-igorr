#include "pch.h"
#include "info.h"

#include "Addresses.h"

constexpr auto AVAIL = "AVAILABLE";
constexpr auto UNAVAIL = "UNAVAILABLE";
 
const char* sHealth;
const char* sAmmo;
const char* sSpeedHack;
const char* sDoubleXP;

void info::checkStatus()
{
	if (!cHealth->isInvincible) 
		sHealth = UNAVAIL;
	else
		sHealth = AVAIL;

	if (!cAmmo->infiniteAmmo) 
		sAmmo = UNAVAIL;
	else 
		sAmmo = AVAIL;

	if (!cPlayerController->movementSpeed) 
		sSpeedHack = UNAVAIL;	
	else 
		sSpeedHack = AVAIL;

	if (!cStatMod->multiplierBonus) 
		sDoubleXP = UNAVAIL;	
	else 
		sDoubleXP = AVAIL;
}

void info::printFeatures()
{
	// Clear console
	system("cls");

	std::cout << " 20 Minutes Till Dawn Cheats v1.1.2 - by marcoigorr\n" << std::endl;
	std::cout << "  [+] F1 - Invincibility " << "  ( " << sHealth << " )" << std::endl;
	std::cout << "  [+] F2 - Unlimited Ammo " << " ( " << sAmmo << " )" << std::endl;
	std::cout << "  [+] F3 - Speed Hack " << "     ( " << sSpeedHack << " )" << std::endl;
	std::cout << "  [+] F4 - Double XP " << "      ( " << sDoubleXP << " )" << std::endl;

	std::cout << "\n  [+] END -> Eject DLL\n" << std::endl;	
}

