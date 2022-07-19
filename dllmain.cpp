// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"
#include "console.h"

#include "Addresses.h"
#include "Offsets.h"

#include "Options.hpp"
using namespace Options;


DWORD WINAPI MainThread(HMODULE hModule)
{
    // Create Console
    console::init();
    std::cout << "[+] Injection successful! (\"END\" to eject dll)\n" << std::endl;
    std::cout << "[+] F1 -> Invincibility\n[+] F2 -> Unlimited Ammo\n[+] F3 -> Speed Hack\n" << std::endl;

    // Hack loop
    while (!isEjecting)
    {
        isEjecting = ((GetAsyncKeyState(VK_END) & 1) ? true : false);

        // Calculte game addresses each cycle
        pAddy->calcAddresses();

        // -- HP
        if (GetAsyncKeyState(VK_F1) & 1 || isEjecting)
        {
            bHealth = (!isEjecting) ? !bHealth : false;
            std::cout << "[+] Changed Invincibility to: " << bHealth << std::endl; 

            if (!pAddy->HP) continue;
            if (bHealth) 
            {                
                *(int*)pAddy->isInvincible = 1;
            }
            else 
            {
                *(int*)pAddy->isInvincible = 0;
            }
        } 
        if (bHealth) *(int*)pAddy->HP = 6;

        // -- Ammo
        if (GetAsyncKeyState(VK_F2) & 1 || isEjecting)
        {
            bAmmo = (!isEjecting) ? !bAmmo : false;
            std::cout << "[+] Changed Unlimited Ammo to: " << bAmmo << std::endl;

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

        // -- Speed
        if (GetAsyncKeyState(VK_F3) & 1 || isEjecting)
        {
            bSpeed = (!isEjecting) ? !bSpeed : false;
            std::cout << "[+] Changed Speed Hack to: " << bSpeed << std::endl;

            if (!pAddy->movementSpeed) continue;
            if (bSpeed) 
            {
                *(float*)pAddy->movementSpeed = 6; 
            }
            else 
            { 
                *(float*)pAddy->movementSpeed = 3;
            }               
        }
        Sleep(50);
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
