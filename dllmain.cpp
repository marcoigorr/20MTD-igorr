// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"
#include "console.h"

bool bHealth = false, bAmmo = false;
// flanne.Health:HPChange+a3

DWORD WINAPI MainThread(HMODULE hModule)
{
    // Create Console
    console::init();
    std::cout << "[+] Injection succeeded! Press END to eject dll...\n" << std::endl;

    // Get Module handle
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"MinutesTillDawn.exe");
    std::cout << "[+] Module base address: " << std::hex << std::uppercase << moduleBase << std::endl;

    uintptr_t unityPlayerDllBase = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
    std::cout << "[+] UnityPlayer.dll base address: " << unityPlayerDllBase << std::endl;

    // Get local player addr
    uintptr_t localPlayer = unityPlayerDllBase + 0x017FE578;
    std::cout << "[+] local Player address: " << localPlayer << std::endl;

    // Hack loop
    while (!GetAsyncKeyState(VK_END))
    {
        uintptr_t* ptrHp = (uintptr_t*)mem::FindDMAAddy(localPlayer, { 0xD38,0x6C8,0x60,0x30,0x28, 0xE8, 0x54 });
        uintptr_t* ptrAmmo = (uintptr_t*)mem::FindDMAAddy(localPlayer, { 0x178,0x40,0x70,0x0,0xD0, 0x60, 0x40 });

        // -- HP
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            bHealth = !bHealth;
            std::cout << "[+] Changed God mode to: " << bHealth << std::endl;            
        } 
        if (bHealth)
        {
            *(int*)ptrHp = 5;
        }
        // -- Ammo
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            bAmmo = !bAmmo;
            std::cout << "[+] Changed Unlimited ammo to: " << bAmmo << std::endl;
        }
        if (bAmmo)
        {
            *(int*)ptrAmmo = 9;
        }
    }

    // Cleanup/Eject
    std::cout << "[+] Ejecting...";
    console::stop();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

