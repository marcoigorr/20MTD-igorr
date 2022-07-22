// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"

#include "Addresses.h"
#include "Offsets.h"

#include "Options.h"

#include "DX11.h"
using namespace d3d11Menu;

#include "info.h"
#include "console.h"

#define isEjecting options->isEjecting

DWORD WINAPI MainThread(HMODULE hModule)
{
    // Create Console
    cmd->Init();
    std::cout << "[+] Dll Injection succeeded!" << std::endl;  
    Sleep(500);

    std::cout << "[+] Initializing Cheat Menu... ";
    Sleep(500);
    // Hook d3d11, render ImGUI
    if (!InitMenu())
    {
        std::cout << "FAILED" <<  std::endl;
        std::cout << "[+] Hook failed. Ejecting dll... ";
        isEjecting = true;
        Sleep(1500);
    }
    else
    {
        std::cout << "OK" << std::endl;
        std::cout << "[+] Success! Initializing cheats... ";   
    }
    Sleep(500);

    // Close console
    cmd->Stop();

    // Hack loop
    while (!isEjecting)
    {
        // Press END to eject dll
        isEjecting = ((GetAsyncKeyState(VK_END)) ? true : false);

        // Calculate game memory addresses
        if (!isEjecting) addr->calcAddresses();

        if (isEjecting)
        {
            options->SetAllFalse();
        }       

        // -- Menu
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            options->bMenu = !options->bMenu;
        }

        // check if the address is valid
        info::checkBadPointers();

        // -- HP
        if (cHealth->isInvincible) // need this for extra security
        {
            if (options->bHealth)
            {
                *(int*)cHealth->isInvincible = 1;
            }
            else
            {
                *(int*)cHealth->isInvincible = 0;
            }
        }

        // -- Ammo
        if (cAmmo->infiniteAmmo)
        {
            if (options->bAmmo)
            {
                *(int*)cAmmo->infiniteAmmo = 1;
            }
            else
            {
                *(int*)cAmmo->infiniteAmmo = 0;
            }
        }

        // -- Speed
        if (cPlayerController->movementSpeed)
        {
            // reset movementSpeed
            if (!options->bSpeedHack)
            {
                *(float*)cPlayerController->movementSpeed = 3;
            }
        }

        // -- XP
        if (cStatMod->multiplierBonus)
        {
            // reset xp multiplier
            if (!options->bDoubleXP)
            {
                *(float*)cStatMod->multiplierBonus = 0;
            }
        }   

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            options->SetAllFalse();
        }
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            options->SetAllTrue();
        }
    }

    // Cleanup/Eject    
    if (!StopMenu()) {
        return 1;
    }
    FreeLibraryAndExitThread(hModule, 0);
    
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}



/*
 auto end = std::chrono::system_clock::now();
        if (((std::chrono::duration<double>)(end - t)).count() > 0.5 && !isEjecting)
        {


            // reset timer
            t = std::chrono::system_clock::now();
        }  

        auto t = std::chrono::system_clock::now();
*/