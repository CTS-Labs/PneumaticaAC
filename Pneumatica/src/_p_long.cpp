#include "_p_long.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>

const long offsetRange = 10000;

_p_long::_p_long(long value) {
	offset = rand() % offsetRange;
	this->value = value + offset;
}

size_t _p_long::hash() const {
	return std::hash<long>()(value) ^
		(std::hash<long>()(offset) << 1);
}

void _p_long::reset() {
	offset = 0;
	value = 0;
}

#pragma region Operators

_p_long::operator long() const {
	return value - offset;
}

_p_long& _p_long::operator=(long value) {
	if (value == 0) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->value = value + offset;
		return *this;
	}
}

_p_long& _p_long::operator=(_p_long value) {
	if((long)value == 0) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->value = (long)value + offset;
		return *this;
	}
}

_p_long& _p_long::operator+(_p_long other) {
	offset = rand() % offsetRange;
	value = (long)*this + (long)other + offset;
	return *this;
}

_p_long& _p_long::operator+(long other) {
	offset = rand() % offsetRange;
	value = (long)*this + other + offset;
	return *this;
}

_p_long& _p_long::operator++() {
	offset = rand() % offsetRange;
	long val = (long)*this;
	value = (val++) + offset;
	return *this;
}

_p_long& _p_long::operator-(_p_long other) {
	offset = rand() % offsetRange;
	value = (long)*this - (long)other + offset;
	return *this;
}

_p_long& _p_long::operator-(long other) {
	offset = rand() % offsetRange;
	value = (long)*this - other + offset;
	return *this;
}

_p_long& _p_long::operator--() {
	offset = rand() % offsetRange;
	long val = (long)*this;
	value = (val--) + offset;
	return *this;
}

_p_long& _p_long::operator/(_p_long other) {
	offset = rand() % offsetRange;
	value = (long)*this / (long)other + offset;
	return *this;
}

_p_long& _p_long::operator/(long other) {
	offset = rand() % offsetRange;
	value = (long)*this / other + offset;
	return *this;
}

_p_long& _p_long::operator*(_p_long other) {
	offset = rand() % offsetRange;
	value = (long)*this * (long)other + offset;
	return *this;
}

_p_long& _p_long::operator*(long other) {
	offset = rand() % offsetRange;
	value = (long)*this * other + offset;
	return *this;
}

_p_long& _p_long::operator%(_p_long other) {
	offset = rand() % offsetRange;
	value = (long)*this % (long)other + offset;
	return *this;
}

_p_long& _p_long::operator%(long other) {
	offset = rand() % offsetRange;
	value = (long)*this % other + offset;
	return *this;
}

bool _p_long::operator==(_p_long other) {
	return (long)*this == (long)other;
}

bool _p_long::operator==(long other) {
	return (long)*this == other;
}

bool _p_long::operator!=(_p_long other) {
	return (long)*this != (long)other;
}

bool _p_long::operator!=(long other) {
	return (long)*this != other;
}

bool _p_long::operator>(_p_long other) {
	return (long)*this > (long)other;
}

bool _p_long::operator>(long other) {
	return (long)*this > other;
}

bool _p_long::operator<(_p_long other) {
	return (long)*this < (long)other;
}

bool _p_long::operator<(long other) {
	return (long)*this < other;
}

bool _p_long::operator<=(_p_long other) {
	return (long)*this <= (long)other;
}

bool _p_long::operator<=(long other) {
	return (long)*this <= other;
}

bool _p_long::operator>=(_p_long other) {
	return (long)*this >= (long)other;
}

bool _p_long::operator>=(long other) {
	return (long)*this >= other;
}

#pragma endregion