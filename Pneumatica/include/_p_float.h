#pragma once
#include "pneumatica.h"

struct PNEUMO_API _p_float
{
public:
	_p_float(float value = 0.0f);

	size_t hash() const;

	void reset();

	operator float() const;

	_p_float& operator=(float value);

	_p_float& operator=(_p_float value);

	_p_float& operator+(_p_float other);

	_p_float& operator+(float other);

	_p_float& operator++();

	_p_float& operator-(_p_float other);

	_p_float& operator-(float other);

	_p_float& operator--();

	_p_float& operator/(_p_float other);

	_p_float& operator/(float other);

	_p_float& operator*(_p_float other);

	_p_float& operator*(float other);

	bool operator==(_p_float other);

	bool operator==(float other);

	bool operator!=(_p_float other);

	bool operator!=(float other);

	bool operator>(_p_float other);

	bool operator>(float other);

	bool operator<(_p_float other);

	bool operator<(float other);

	bool operator>=(_p_float other);

	bool operator>=(float other);

	bool operator<=(_p_float other);

	bool operator<=(float other);

private:
	int offset;
	float value;
};