#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int main(int argc, char* argv) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(   
        L"M:\\MyFolder\\University\\OS\\Lab1\\Signal\\x64\\Debug\\Signal.exe",
        NULL,
        NULL,           
        NULL,           
        FALSE,          
        CREATE_NEW_CONSOLE,    // можно оставить 0 и будет 1 консоль
        NULL,           
        NULL,          
        &si,           
        &pi)           
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode = 1;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    std::cout << "Process ended with code: " << exitCode;

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}