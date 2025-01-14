#define CURL_STATICLIB
#include <curl/curl.h>
#include "WorkerService.h"
#include <Windows.h>
#include <string>
#include <thread>
#include <functional>
#include <iostream>
#include <aixlog.hpp>

using namespace std;

thread workerThread;
PROCESS_INFORMATION wpi;

WorkerService::WorkerService(void) {
    AixLog::Log::init(
        {
            make_shared<AixLog::SinkCout>(AixLog::Severity::trace, "Pneumatica INFO: %Y-%m-%d %H-%M-%S.#ms [#severity] (#tag) #message"),
            make_shared<AixLog::SinkCerr>(AixLog::Severity::error, "Pneumatica ERROR: %Y-%m-%d %H-%M-%S.#ms [#severity] (#tag)")
        });
}

WorkerService::~WorkerService() {
    stop();
}

void WorkerService::run() {
    LOG(INFO) << "Running the worker service \n";
    string command = "./PneumoWorker.exe";
    workerThread = thread(&WorkerService::runService, this, wstring(command.begin(), command.end()).c_str());
}

void WorkerService::stop() {
    if (workerThread.joinable()) {
        if (wpi.hProcess) {
            TerminateProcess(wpi.hProcess, 0);
            CloseHandle(wpi.hProcess);
            CloseHandle(wpi.hThread);
        }
        LOG(INFO) << "Stopping the worker service \n";
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
        cerr << "CreateProcess failed with error code: " << error << endl;
    }
} 