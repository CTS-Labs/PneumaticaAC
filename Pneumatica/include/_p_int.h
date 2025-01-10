#pragma once
#include "pneumatica.h"

struct PNEUMO_API _p_int
{
public:
	_p_int(int value = 0);

	size_t hash() const;

	void reset();

	operator int() const;

	_p_int& operator=(int value);

private:
	int offset;
	int value;
};