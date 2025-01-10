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

_p_long::operator long() const {
	return value - offset;
}

_p_long& _p_long::operator=(long value) {
	offset = rand() % offsetRange;
	this->value = value + offset;
	return *this;
}
