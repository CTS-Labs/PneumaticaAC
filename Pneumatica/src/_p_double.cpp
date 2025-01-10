#include "_p_double.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>

const int offsetRange = 10000;

_p_double::_p_double(double value) {
	offset = rand() % offsetRange;
	this->value = value + offsetRange;
}

size_t _p_double::hash() const {
	return std::hash<double>()(value) ^
		(std::hash<double>()(offset) << 1);
}

void _p_double::reset() {
	offset = 0;
	value = .0f;
}

#pragma region Operators

_p_double::operator double() const {
	return value - offset;
}

_p_double& _p_double::operator=(double value) {
	if (value == 0.0f) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->value = value + offset;
		return *this;
	}
}

_p_double& _p_double::operator=(_p_double value) {
	if ((double)value == 0.0f) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->value = (double)value + offset;
		return *this;
	}
}

_p_double& _p_double::operator+(_p_double other) {
	offset = rand() % offsetRange;
	value = (double)*this + (double)other + offset;
	return *this;
}

_p_double& _p_double::operator+(double other) {
	offset = rand() % offsetRange;
	value = (double)*this + other + offset;
	return *this;
}

_p_double& _p_double::operator++() {
	offset = rand() % offsetRange;
	double val = (double)*this;
	value = (val++) + offset;
	return *this;
}

_p_double& _p_double::operator-(_p_double other) {
	offset = rand() % offsetRange;
	value = (double)*this - (double)other + offset;
	return *this;
}

_p_double& _p_double::operator-(double other) {
	offset = rand() % offsetRange;
	value = (double)*this - other + offset;
	return *this;
}

_p_double& _p_double::operator--() {
	offset = rand() % offsetRange;
	double val = (double)*this;
	value = (val--) + offset;
	return *this;
}

_p_double& _p_double::operator/(_p_double other) {
	offset = rand() % offsetRange;
	value = (double)*this / (double)other + offset;
	return *this;
}

_p_double& _p_double::operator/(double other) {
	offset = rand() % offsetRange;
	value = (double)*this / other + offset;
	return *this;
}

_p_double& _p_double::operator*(_p_double other) {
	offset = rand() % offsetRange;
	value = (double)*this * (double)other + offset;
	return *this;
}

_p_double& _p_double::operator*(double other) {
	offset = rand() % offsetRange;
	value = (double)*this * other + offset;
	return *this;
}


bool _p_double::operator==(_p_double other) {
	return (double)*this == (double)other;
}

bool _p_double::operator==(double other) {
	return (double)*this == other;
}

bool _p_double::operator!=(_p_double other) {
	return (double)*this != (double)other;
}

bool _p_double::operator!=(double other) {
	return (double)*this != (double)other;
}

bool _p_double::operator>(_p_double other) {
	return (double)*this > (double)other;
}

bool _p_double::operator>(double other) {
	return (double)*this > other;
}

bool _p_double::operator<(_p_double other) {
	return (double)*this < (double)other;
}

bool _p_double::operator<(double other) {
	return (double)*this < other;
}

bool _p_double::operator>=(_p_double other) {
	return (double)*this >= (double)other;
}

bool _p_double::operator>=(double other) {
	return (double)*this >= other;
}

bool _p_double::operator<=(_p_double other) {
	return (double)*this <= (double)other;
}

bool _p_double::operator<=(double other) {
	return (double)*this <= other;
}

#pragma endregion