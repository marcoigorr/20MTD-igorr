// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"
#include "console.h"
#include "Addresses.h"
#include "Offsets.h"

bool bHealth = false, bAmmo = false;

DWORD WINAPI MainThread(HMODULE hModule)
{
    // Create Console
    console::init();
    std::cout << "[+] Injection successful! Press END to eject dll...\n" << std::endl;
   
    // Module handle
    std::cout << "[+] Module base address: " << std::hex << std::uppercase << addr->moduleBase << std::endl;

    // UnityPlayer handle
    std::cout << "[+] UnityPlayer.dll base address: " << addr->unityPlayer << std::endl;

    // local player addr
    std::cout << "[+] local Player address: " << addr->localPlayer << std::endl;

    // Hack loop
    while (!GetAsyncKeyState(VK_END))
    {
        pAddy->calcAddresses();

        // -- HP
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            bHealth = !bHealth;
            std::cout << "[+] Changed God mode to: " << bHealth << std::endl; 

            if (!pAddy->HP) continue;
            if (bHealth)
            {
                *(int*)pAddy->HP = 4;
                *(int*)pAddy->isInvincible = 1;
            }
            else
            {
                *(int*)pAddy->isInvincible = 0;
            }
        } 
        // -- Ammo
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            bAmmo = !bAmmo;
            std::cout << "[+] Changed Unlimited ammo to: " << bAmmo << std::endl;

            if (!pAddy->Ammo) continue;
            if (bAmmo)
            {
                *(int*)pAddy->Ammo = 6;
                *(int*)pAddy->infiniteAmmo = 1;
            }
            else
            {
                *(int*)pAddy->infiniteAmmo = 0;
            }
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
