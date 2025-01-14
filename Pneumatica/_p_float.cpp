#include "_p_float.h"
#include <cstdlib>
#include <functional>
#include <tuple>
#include <cmath>
#include <iostream>

const int offsetRange = 10000;

_p_float::_p_float(float value) {
	offset = rand() % offsetRange;
	this->value = value + offsetRange;
	std::cout << value << std::endl;
}

size_t _p_float::hash() const {
	return std::hash<float>()(value) ^
		(std::hash<float>()(offset) << 1);
}

void _p_float::reset() {
	offset = 0;
	value = 0.0f;
}

_p_float::operator float() const {
	return value - offset;
}

_p_float& _p_float::operator=(float value) {
	offset = rand() % offsetRange;
	this->value = value + offset;
	std::cout << value << std::endl;
	return *this;
}