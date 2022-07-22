#pragma once

class Addresses
{
public:
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"MinutesTillDawn.exe");
	uintptr_t unityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
	uintptr_t localPlayer = unityPlayer + 0x017FE578;

	static void calcAddresses();
};
namespace flanne
{
	class Health
	{
	public:
		uintptr_t* maxHP;
		uintptr_t* HP;
		uintptr_t* isInvincible;
	};

	class Ammo
	{
	public:
		uintptr_t* maxAmmo;
		uintptr_t* Ammo;
		uintptr_t* infiniteAmmo;
	};

	class PlayerController
	{
	public:
		uintptr_t* movementSpeed;
	};

	class Player
	{
	public:
		class PlayerXP
		{
		public:
			uintptr_t* level;
			uintptr_t* xp;
		};		
	};

	class StatMod
	{
	public:
		uintptr_t* flatBonus;
		uintptr_t* multiplierBonus;
		uintptr_t* multiplierReduction;
	};
}

extern Addresses* addr;
extern flanne::Health* cHealth;
extern flanne::Ammo* cAmmo;
extern flanne::PlayerController* cPlayerController;
extern flanne::Player::PlayerXP* cPlayerXP;
extern flanne::StatMod* cStatMod;
