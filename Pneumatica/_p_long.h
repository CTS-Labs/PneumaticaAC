#pragma once
#include "pneumatica.h"

struct PNEUMO_API _p_long
{
public:
	_p_long(long value = 0);
	~_p_long();

	size_t hash() const;

	void reset();

	operator long() const;

	_p_long& operator=(long value);

private:
	long offset;
	long value;
};