#pragma once
#include "pneumatica.h"

struct PNEUMO_API _p_long
{
public:
	_p_long(long value = 0);

	size_t hash() const;

	void reset();

	operator long() const;

	_p_long& operator=(long value);

	_p_long& operator=(_p_long value);

	_p_long& operator+(_p_long other);

	_p_long& operator+(long other);

	_p_long& operator++();

	_p_long& operator-(_p_long other);

	_p_long& operator-(long other);

	_p_long& operator--();

	_p_long& operator/(_p_long other);

	_p_long& operator/(long other);

	_p_long& operator*(_p_long other);

	_p_long& operator*(long other);

	_p_long& operator%(_p_long other);
		
	_p_long& operator%(long other);

	bool operator==(_p_long other);

	bool operator==(long other);

	bool operator!=(_p_long other);

	bool operator!=(long other);

	bool operator>(_p_long other);

	bool operator>(long other);

	bool operator<(_p_long other);

	bool operator<(long other);

	bool operator>=(_p_long other);

	bool operator>=(long other);

	bool operator<=(_p_long other);

	bool operator<=(long other);

private:
	long offset;
	long value;
};