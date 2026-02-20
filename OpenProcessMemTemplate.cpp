#include <iostream>
#include <conio.h>
#include <windows.h>
#include <tlhelp32.h>

// =============================
// Changeable (CONFIG)
// =============================

bool logging = true;

constexpr const char* WinName = ""; //the window name

// =============================
// GLOBAL VARS
// =============================


uintptr_t address = ; // a cheat engine pointer similar to this



// leave below alone
float cashval;   // int normally but some games do float
DWORD procid = 0;
HANDLE handle = nullptr;
DWORD BaseAddress;

// =============================
// Function Declarations
// =============================
void AddCash();



// leave below alone
void GetReqs();


// =============================
// main
// =============================

int main()
{
    GetReqs();
    

    int menu;
    std::cout << " enter 1 to add cash\n ";
    std::cin >> menu;

    for(int i; i != 1;){
        system("cls");
        if (menu == 1){AddCash();} 

        std::cout << " 1. Exit\n 2. Add more \n ";
        std::cin >> i;

    }

    CloseHandle(handle);

    return 0;
}


// =============================
// FUNCTIONS
// place custom functions below
// =============================

        //example read and write

void AddCash()
{
    ReadProcessMemory(handle, reinterpret_cast<LPCVOID>(address),&cashval, sizeof(float), nullptr);
    float CashAdd;
    std::cout << " you have: " << cashval <<  " Input How cash to add\n ";
    std::cin >> CashAdd;

    float newcash = cashval + CashAdd;
    WriteProcessMemory(handle,reinterpret_cast<LPVOID>(address),&newcash,sizeof(float), nullptr);

    std::cout << "\n Cash added if its not changed interact with it\n\n";

}



// =============================
// DO NOT EDIT BELOW 
// All the import stuff below
// Add new stuff above
// =============================

void GetReqs() 
{
    
    HWND hwnd = FindWindowA(NULL, WinName);
    if (hwnd){std::cout << " Window found: " << hwnd << "\n";}    
  
    GetWindowThreadProcessId(hwnd, &procid);
    if (procid){std::cout << " Process found: " << procid <<"\n";}
    
    handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procid);
    if (handle){std::cout << " handle: " << handle << "\n";}

    
    ReadProcessMemory(handle, reinterpret_cast<LPCVOID>(address),&cashval, sizeof(float), nullptr);
    if (cashval){std::cout << " found: " << address << "\n Value : " << cashval << "\n";}
    if(!logging){
        system("cls");
    }


    if ((!hwnd || !procid || !handle || !cashval) && logging){ // cashval checks if its 0 turn of loggin if starting with 0
        system("cls");
        std::cout << " issue found \n"<<
        " Handle: " << hwnd 
        << "\n Proc id: " << procid 
        << "\n Handle: " << handle
        << "\n Pointer: " <<  procid
        << "\n Pointer val: " << cashval 
        << "\n";
 
    return;
    }

    
}




