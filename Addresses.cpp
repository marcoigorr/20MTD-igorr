#include "pch.h"
#include "mem.h"
#include "Offsets.h"
#include "Addresses.h"

#define localPlayer addr->localPlayer

void Addresses::calcAddresses()
{
	cHealth->maxHP =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->maxHP);
	cHealth->HP =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->HP);
	cHealth->isInvincible =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->isInvincible);
	cAmmo->Ammo =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->Ammo);
	cAmmo->infiniteAmmo =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->infiniteAmmo);
	cPlayerController->movementSpeed =  (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->movementSpeed);
	cPlayerXP->level =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->level);
	cPlayerXP->xp =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->xp);
	cStatMod->flatBonus =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->flatBonus);
	cStatMod->multiplierBonus =			(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->multiplierBonus);
	cStatMod->multiplierReduction =		(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->multiplierReduction);
	//cAmmo->maxAmmo =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->damage);
}

extern Addresses* addr = new Addresses;
extern flanne::Health* cHealth = new flanne::Health();
extern flanne::Ammo* cAmmo = new flanne::Ammo();
extern flanne::PlayerController* cPlayerController = new flanne::PlayerController();
extern flanne::Player::PlayerXP* cPlayerXP = new flanne::Player::PlayerXP();
extern flanne::StatMod* cStatMod = new flanne::StatMod();

