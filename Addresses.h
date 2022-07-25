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

	class GunData
	{
	public:
		uintptr_t* damage;
		uintptr_t* shootCooldown;
		uintptr_t* maxAmmo;
		uintptr_t* reloadDuration;
		uintptr_t* numOfProjectiles;
		uintptr_t* spread;
		uintptr_t* knockback;
		uintptr_t* projectileSpeed;
		uintptr_t* bounce;
		uintptr_t* piercing;
		uintptr_t* burnChance;
		uintptr_t* inaccuracy;
		uintptr_t* isSummonGun;
	};
	class GameTimer
	{
	public:
		uintptr_t* timer;
	};
}

extern Addresses* addr;
extern flanne::Health* cHealth;
extern flanne::Ammo* cAmmo;
extern flanne::PlayerController* cPlayerController;
extern flanne::Player::PlayerXP* cPlayerXP;
extern flanne::StatMod* cStatMod;
extern flanne::GunData* cGunData;
extern flanne::GameTimer* cGameTimer;
