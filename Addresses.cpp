#include "pch.h"
#include "mem.h"
#include "Offsets.h"
#include "Addresses.h"

#define localPlayer addr->localPlayer

void Addresses::Player::calcAddresses()
{
	pAddy->HP =			  (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->HP);
	pAddy->isInvincible = (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->isInvincible);
	pAddy->Ammo =		  (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->Ammo);
	pAddy->infiniteAmmo = (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->infiniteAmmo);
	pAddy->movementSpeed = (uintptr_t*)mem::FindDMAAddy(localPlayer, offsets->movementSpeed);
}

Addresses* addr = new Addresses();
Addresses::Player* pAddy = new Addresses::Player();
