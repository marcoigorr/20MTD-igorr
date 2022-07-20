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
    std::cout << "  [+] Injection successful!\n" << std::endl;   

    // Calculate game memory addresses
    addr->calcAddresses();

    // Check status of the addresses
    info::checkStatus();

    // print hack features
    info::printFeatures();

    auto t = std::chrono::system_clock::now();

    // Hack loop
    while (!isEjecting)
    {
        isEjecting = ((GetAsyncKeyState(VK_END) & 1) ? true : false);        

        auto end = std::chrono::system_clock::now();

        // if more than 2s passed, update console
        if (((std::chrono::duration<double>)(end - t)).count() > 2.0)
        {
            addr->calcAddresses();

            info::checkStatus();

            info::printFeatures();

            // reset timer
            t = std::chrono::system_clock::now();
        }        

        // -- HP
        if (GetAsyncKeyState(VK_F1) & 1 || isEjecting)
        {
            bHealth = (!isEjecting) ? !bHealth : false;

            if (!cHealth->HP) continue;
            if (bHealth) 
            {      
                if (bHealth) *(int*)cHealth->HP = 6;
                *(int*)cHealth->isInvincible = 1;
            }
            else 
            {
                *(int*)cHealth->isInvincible = 0;
            }
        }        

        // -- Ammo
        if (GetAsyncKeyState(VK_F2) & 1 || isEjecting)
        {
            bAmmo = (!isEjecting) ? !bAmmo : false;

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

        // -- double XP
        if (GetAsyncKeyState(VK_F4) & 1 || isEjecting)
        {
            bDoubleXP = (!isEjecting) ? !bDoubleXP : false;

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
    std::cout << "\n  [+] Ejecting...";
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
