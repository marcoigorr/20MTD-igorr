#include "pch.h"
#include "mem.h"
#include "Offsets.h"
#include "Addresses.h"

void Addresses::Player::calcAddresses()
{
	pAddy->HP = (uintptr_t*)mem::FindDMAAddy(addr->localPlayer, offsets->HP);
	pAddy->isInvincible = (uintptr_t*)mem::FindDMAAddy(addr->localPlayer, offsets->isInvincible);
	pAddy->Ammo = (uintptr_t*)mem::FindDMAAddy(addr->localPlayer, offsets->Ammo);
	pAddy->infiniteAmmo = (uintptr_t*)mem::FindDMAAddy(addr->localPlayer, offsets->infiniteAmmo);
}

Addresses* addr = new Addresses();
Addresses::Player* pAddy = new Addresses::Player();
