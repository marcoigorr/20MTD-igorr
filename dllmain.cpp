// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"
#include "console.h"

#include "Addresses.h"
#include "Offsets.h"

#include "Options.hpp"
using namespace Options;

#include "info.h"


DWORD WINAPI MainThread(HMODULE hModule)
{
    // Create Console
    console::init();
    std::cout << "[+] Injection successful!\n" << std::endl; 

    printManual(); // print hack features

    // Hack loop
    while (!isEjecting)
    {
        isEjecting = ((GetAsyncKeyState(VK_END) & 1) ? true : false);

        // Calculte game addresses each cycle
        addr->calcAddresses();

        // -- HP
        if (GetAsyncKeyState(VK_F1) & 1 || isEjecting)
        {
            bHealth = (!isEjecting) ? !bHealth : false;
            std::cout << "[+] Changed Invincibility to: " << bHealth << std::endl; 

            if (!cHealth->HP) continue;
            if (bHealth) 
            {                
                *(int*)cHealth->isInvincible = 1;
            }
            else 
            {
                *(int*)cHealth->isInvincible = 0;
            }
        } 
        if (bHealth) *(int*)cHealth->HP = 6;

        // -- Ammo
        if (GetAsyncKeyState(VK_F2) & 1 || isEjecting)
        {
            bAmmo = (!isEjecting) ? !bAmmo : false;
            std::cout << "[+] Changed Unlimited Ammo to: " << bAmmo << std::endl;

            if (!cAmmo->Ammo) continue;
            if (bAmmo) 
            { 
                *(int*)cAmmo->Ammo = 6; 
                *(int*)cAmmo->infiniteAmmo = 1;
            }
            else 
            { 
                *(int*)cAmmo->infiniteAmmo = 0; 
            }                
        }  

        // -- Speed
        if (GetAsyncKeyState(VK_F3) & 1 || isEjecting)
        {
            bSpeed = (!isEjecting) ? !bSpeed : false;
            std::cout << "[+] Changed Speed Hack to: " << bSpeed << std::endl;

            if (!cPlayerController->movementSpeed) continue;
            if (bSpeed) 
            {
                *(float*)cPlayerController->movementSpeed = 8; 
            }
            else 
            { 
                *(float*)cPlayerController->movementSpeed = 3;
            }               
        }
        Sleep(50);

        // -- double XP
        if (GetAsyncKeyState(VK_F4) & 1 || isEjecting)
        {
            bDoubleXP = (!isEjecting) ? !bDoubleXP : false;
            std::cout << "[+] Changed double XP to: " << bDoubleXP << std::endl;

            if (!cStatMod->multiplierBonus) continue;
            if (bDoubleXP)
            {
                *(float*)cStatMod->multiplierBonus = 1; // 1 additional xp
            }
            else
            {
                *(float*)cStatMod->multiplierBonus = 0;
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
