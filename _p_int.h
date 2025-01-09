#pragma once
#include "pneumatica.h"

using namespace std;

struct PNEUMO_API _p_int
{
public:
	_p_int(int value = 0);

	size_t hash() const;

	void reset();

	operator int() const;

	_p_int& operator=(int value);

	_p_int& operator=(_p_int value);

	_p_int& operator+(_p_int other);

	_p_int& operator+(int other);

	_p_int& operator++(int);

	_p_int& operator-(_p_int other);

	_p_int& operator-(int other);

	_p_int& operator--(int);

	_p_int& operator/(_p_int other);

	_p_int& operator/(int other);

	_p_int& operator*(_p_int other);

	_p_int& operator*(int other);

	_p_int& operator%(_p_int other);
		
	_p_int& operator%(int other);

	bool operator==(_p_int other);

	bool operator==(int other);

	bool operator!=(_p_int other);

	bool operator!=(int other);

	bool operator>(_p_int other);

	bool operator>(int other);

	bool operator<(_p_int other);

	bool operator<(int other);

	bool operator>=(_p_int other);

	bool operator>=(int other);

	bool operator<=(_p_int other);

	bool operator<=(int other);

private:
	int offset;
	int value;
};