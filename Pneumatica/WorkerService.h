#pragma once
#include <Windows.h>
#include "pneumatica.h"


/*!
* \brief a class for working with the anti-cheat service
*/
class PNEUMO_API WorkerService
{
public:
	WorkerService(void);
	~WorkerService();
	void run();
	void stop();
private:
	void runService(LPCWSTR runCommand);
};

