#include "pch.h"
#include "mem.h"
#include "Offsets.h"
#include "Addresses.h"

#define localPlayer addr->localPlayer

void Addresses::calcAddresses()
{
	// flanne.Health
	cHealth->maxHP =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->maxHP);
	cHealth->HP =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->HP);
	cHealth->isInvincible =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->isInvincible);
	// flanne.Ammo
	cAmmo->Ammo =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->Ammo);
	cAmmo->infiniteAmmo =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->infiniteAmmo);
	// flanne.PlayerController
	cPlayerController->movementSpeed =  (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->movementSpeed);
	// flanne.Player.PlayerXP
	cPlayerXP->level =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->level);
	cPlayerXP->xp =						(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->xp);
	// flanne.StatMod
	cStatMod->flatBonus =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->flatBonus);
	cStatMod->multiplierBonus =			(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->multiplierBonus);
	cStatMod->multiplierReduction =		(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->multiplierReduction);
	// flanne.GunData
	cGunData->damage =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->damage);
	cGunData->shootCooldown =			(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->shootCooldown);
	cGunData->maxAmmo =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->maxAmmo);
	cGunData->reloadDuration =			(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->reloadDuration);
	cGunData->numOfProjectiles =		(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->numOfProjectiles);
	cGunData->spread =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->spread);
	cGunData->knockback =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->knokback);
	cGunData->projectileSpeed =			(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->projectileSpeed);
	cGunData->bounce =					(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->bounce);
	cGunData->piercing =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->piercing);
	cGunData->burnChance =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->burnChance);
	cGunData->inaccuracy =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->inaccuracy);
	cGunData->isSummonGun =				(uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->isSummonGun);
	// flanne.GameTimer
	cGameTimer->timer = (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->timer);
}

Addresses* addr = new Addresses;
flanne::Health* cHealth = new flanne::Health();
flanne::Ammo* cAmmo = new flanne::Ammo();
flanne::PlayerController* cPlayerController = new flanne::PlayerController();
flanne::Player::PlayerXP* cPlayerXP = new flanne::Player::PlayerXP();
flanne::StatMod* cStatMod = new flanne::StatMod();
flanne::GunData* cGunData = new flanne::GunData();
flanne::GameTimer* cGameTimer = new flanne::GameTimer();

