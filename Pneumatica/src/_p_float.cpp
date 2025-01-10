#include "_p_float.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>

const int offsetRange = 10000;

_p_float::_p_float(float value) {
	offset = rand() % offsetRange;
	this->value = value + offsetRange;
}

size_t _p_float::hash() const {
	return std::hash<float>()(value) ^
		(std::hash<float>()(offset) << 1);
}

void _p_float::reset() {
	offset = 0;
	value = .0f;
}

#pragma region Operators

_p_float::operator float() const {
	return value - offset;
}

_p_float& _p_float::operator=(float value) {
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

_p_float& _p_float::operator=(_p_float value) {
	if ((float)value == 0.0f) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->value = (float)value + offset;
		return *this;
	}
}

_p_float& _p_float::operator+(_p_float other) {
	offset = rand() % offsetRange;
	value = (float)*this + (float)other + offset;
	return *this;
}

_p_float& _p_float::operator+(float other) {
	offset = rand() % offsetRange;
	value = (float)*this + other + offset;
	return *this;
}

_p_float& _p_float::operator++() {
	offset = rand() % offsetRange;
	float val = (float)*this;
	value = (val++) + offset;
	return *this;
}

_p_float& _p_float::operator-(_p_float other) {
	offset = rand() % offsetRange;
	value = (float)*this - (float)other + offset;
	return *this;
}

_p_float& _p_float::operator-(float other) {
	offset = rand() % offsetRange;
	value = (float)*this - other + offset;
	return *this;
}

_p_float& _p_float::operator--() {
	offset = rand() % offsetRange;
	float val = (float)*this;
	value = (val--) + offset;
	return *this;
}

_p_float& _p_float::operator/(_p_float other) {
	offset = rand() % offsetRange;
	value = (float)*this / (float)other + offset;
	return *this;
}

_p_float& _p_float::operator/(float other) {
	offset = rand() % offsetRange;
	value = (float)*this / other + offset;
	return *this;
}

_p_float& _p_float::operator*(_p_float other) {
	offset = rand() % offsetRange;
	value = (float)*this * (float)other + offset;
	return *this;
}

_p_float& _p_float::operator*(float other) {
	offset = rand() % offsetRange;
	value = (float)*this * other + offset;
	return *this;
}


bool _p_float::operator==(_p_float other) {
	return (float)*this == (float)other;
}

bool _p_float::operator==(float other) {
	return (float)*this == other;
}

bool _p_float::operator!=(_p_float other) {
	return (float)*this != (float)other;
}

bool _p_float::operator!=(float other) {
	return (float)*this != (float)other;
}

bool _p_float::operator>(_p_float other) {
	return (float)*this > (float)other;
}

bool _p_float::operator>(float other) {
	return (float)*this > other;
}

bool _p_float::operator<(_p_float other) {
	return (float)*this < (float)other;
}

bool _p_float::operator<(float other) {
	return (float)*this < other;
}

bool _p_float::operator>=(_p_float other) {
	return (float)*this >= (float)other;
}

bool _p_float::operator>=(float other) {
	return (float)*this >= other;
}

bool _p_float::operator<=(_p_float other) {
	return (float)*this <= (float)other;
}

bool _p_float::operator<=(float other) {
	return (float)*this <= other;
}

#pragma endregion