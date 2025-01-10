#pragma once
#include <Windows.h>
#include "pneumatica.h"

class PNEUMO_API WorkerService
{
public:
	WorkerService(void) {}

	void run();
	void stop();
private:
	void runService(LPCWSTR runCommand);
};

