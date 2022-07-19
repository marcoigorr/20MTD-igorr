#pragma once

class Addresses
{
public:
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"MinutesTillDawn.exe");
	uintptr_t unityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
	uintptr_t localPlayer = unityPlayer + 0x017FE578;

	class Player
	{
	public:	
		uintptr_t* HP;
		uintptr_t* isInvincible;
		uintptr_t* Ammo;
		uintptr_t* infiniteAmmo;
		uintptr_t* movementSpeed;

		static void calcAddresses();
	};
};

extern Addresses* addr;
extern Addresses::Player* pAddy;
