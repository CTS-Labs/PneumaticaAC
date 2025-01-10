#include "_p_int.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>

const int offsetRange = 10000;

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

_p_int::operator int() const {
	return value - offset;
}

_p_int& _p_int::operator=(int value) {
	offset = rand() % offsetRange;
	this->value = value + offset;
	return *this;
}