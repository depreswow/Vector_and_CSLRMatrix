#include "OutOfRangeException.h"

OutOfRangeException::OutOfRangeException(int index, int size) {
	message.assign("Array out of range.\nSize = " + std::to_string(size) + ", Index = " + std::to_string(index));
}

const char* OutOfRangeException::what() const {
	return message.c_str(); 
}