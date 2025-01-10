#include "WorkerService.h"
#include <Windows.h>
#include <string>
#include <thread>
#include <functional>
#include <iostream>

std::thread workerThread;
PROCESS_INFORMATION wpi;

void WorkerService::run() {
    std::string command = "./PneumoWorker.exe";
    workerThread = std::thread(&WorkerService::runService, this, std::wstring(command.begin(), command.end()).c_str());
}

void WorkerService::stop() {
    if (workerThread.joinable()) {
        if (wpi.hProcess) {
            TerminateProcess(wpi.hProcess, 0);
            CloseHandle(wpi.hProcess);
            CloseHandle(wpi.hThread);
        }
        workerThread.join();
    }
}

void WorkerService::runService(LPCWSTR runCommand) {
    ZeroMemory(&wpi, sizeof(wpi));

    STARTUPINFO wsi;
    ZeroMemory(&wsi, sizeof(wsi));
    wsi.cb = sizeof(wsi);

    if (CreateProcessW(NULL, const_cast<LPWSTR>(runCommand), NULL, NULL, FALSE, 0, NULL, NULL, &wsi, &wpi)) {
        WaitForSingleObject(wpi.hProcess, INFINITE);
        CloseHandle(wpi.hProcess);
        CloseHandle(wpi.hThread);
    }
    else {
        DWORD error = GetLastError();
        std::cerr << "CreateProcess failed with error code: " << error << std::endl;
    }
} 