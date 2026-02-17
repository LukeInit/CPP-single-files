#include <windows.h>
#include <iostream>

const char* ApplicationName = "Calculator"; // must match window title exactly

void GetPid(HWND hWnd);

int main()
{
    HWND hWnd = FindWindowA(nullptr, ApplicationName);

    GetPid(hWnd);

    int menumain;
    std::cout << "1. Open Process Handle\n";
    std::cin >> menumain;

    if (menumain == 1 && hWnd != NULL)
    {
        DWORD pid;
        GetWindowThreadProcessId(hWnd, &pid);

        HANDLE handleToProcess = OpenProcess(PROCESS_ALL_ACCESS , FALSE, pid);

        if (handleToProcess)
            std::cout << "Process opened successfully\n";
        else
            std::cout << "Failed to open process\n";
    }

    std::cin.get();
    std::cin.get();
    return 0;
}

void GetPid(HWND hWnd)
{
    if (hWnd == NULL)
    {
        std::cout << "Can't find window\n";
    }
    else
    {
        DWORD pid;
        GetWindowThreadProcessId(hWnd, &pid);
        std::cout << "Window found. PID: " << pid << "\n";
    }
}
