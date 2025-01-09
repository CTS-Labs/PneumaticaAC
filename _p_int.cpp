#include "_p_int.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>

int offsetRange = 10000;

_p_int::_p_int(int value) {
	offset = rand() % offsetRange;
	this->value = value + offset;
}

size_t _p_int::hash() const {
	return std::hash<int>()(value) ^
		(std::hash<int>()(offset) << 1);
}

void _p_int::reset() {
	offset = 0;
	value = 0;
}

#pragma region Operators

_p_int::operator int() const {
	return value - offset;
}

_p_int& _p_int::operator=(int value) {
	if (value == NULL) {
		reset();
		return *this;
	}
	else if (value == 0) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->offset = offset;
		this->value = value + offset;
		return *this;
	}
}

_p_int& _p_int::operator=(_p_int value) {
	if (value == NULL) {
		reset();
		return *this;
	}
	else if((int)value == 0) {
		reset();
		return *this;
	}
	else {
		offset = rand() % offsetRange;
		this->offset = offset;
		this->value = (int)value + offset;
		return *this;
	}
}

_p_int& _p_int::operator+(_p_int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this + (int)other + offset;
	return *this;
}

_p_int& _p_int::operator+(int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this + other + offset;
	return *this;
}

_p_int& _p_int::operator++(int) {
	offset = rand() % offsetRange;
	this->offset = offset;
	int val = (int)this;
	this->value = (val++) + offset;
	return *this;
}

_p_int& _p_int::operator-(_p_int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this - (int)other + offset;
	return *this;
}

_p_int& _p_int::operator-(int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this - other + offset;
	return *this;
}

_p_int& _p_int::operator--(int) {
	offset = rand() % offsetRange;
	this->offset = offset;
	int val = (int)this;
	this->value = (val--) + offset;
	return *this;
}

_p_int& _p_int::operator/(_p_int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this / (int)other + offset;
	return *this;
}

_p_int& _p_int::operator/(int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this / other + offset;
	return *this;
}

_p_int& _p_int::operator*(_p_int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this * (int)other + offset;
	return *this;
}

_p_int& _p_int::operator*(int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this * other + offset;
	return *this;
}

_p_int& _p_int::operator%(_p_int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this % (int)other + offset;
	return *this;
}

_p_int& _p_int::operator%(int other) {
	offset = rand() % offsetRange;
	this->offset = offset;
	this->value = (int)this % other + offset;
	return *this;
}

bool _p_int::operator==(_p_int other) {
	return (int)this == (int)other;
}

bool _p_int::operator==(int other) {
	return (int)this == other;
}

bool _p_int::operator!=(_p_int other) {
	return (int)this != (int)other;
}

bool _p_int::operator!=(int other) {
	return (int)this != other;
}

bool _p_int::operator>(_p_int other) {
	return (int)this > (int)other;
}

bool _p_int::operator>(int other) {
	return (int)this > other;
}

bool _p_int::operator<(_p_int other) {
	return (int)this < (int)other;
}

bool _p_int::operator<(int other) {
	return (int)this < other;
}

bool _p_int::operator<=(_p_int other) {
	return (int)this <= (int)other;
}

bool _p_int::operator<=(int other) {
	return (int)this <= other;
}

bool _p_int::operator>=(_p_int other) {
	return (int)this >= (int)other;
}

bool _p_int::operator>=(int other) {
	return (int)this >= other;
}

#pragma endregion Operators