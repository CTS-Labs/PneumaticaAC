#pragma once
#include "pneumatica.h"

struct PNEUMO_API _p_double
{
public:
	_p_double(double value = 0.0f);

	size_t hash() const;

	void reset();

	operator double() const;

	_p_double& operator=(double value);

	_p_double& operator=(_p_double value);

	_p_double& operator+(_p_double other);

	_p_double& operator+(double other);

	_p_double& operator++();

	_p_double& operator-(_p_double other);

	_p_double& operator-(double other);

	_p_double& operator--();

	_p_double& operator/(_p_double other);

	_p_double& operator/(double other);

	_p_double& operator*(_p_double other);

	_p_double& operator*(double other);

	bool operator==(_p_double other);

	bool operator==(double other);

	bool operator!=(_p_double other);

	bool operator!=(double other);

	bool operator>(_p_double other);

	bool operator>(double other);

	bool operator<(_p_double other);

	bool operator<(double other);

	bool operator>=(_p_double other);

	bool operator>=(double other);

	bool operator<=(_p_double other);

	bool operator<=(double other);

private:
	int offset;
	double value;
};