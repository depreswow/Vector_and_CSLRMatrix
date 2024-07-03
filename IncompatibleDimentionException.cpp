#include "IncompatibleDimentionException.h"

IncompatibleDimentionException::IncompatibleDimentionException(int size1, int size2) {
	message.assign("Dimentions do not match.\nSize1 = " + std::to_string(size1) + ", Size2 = " + std::to_string(size2));
}

const char* IncompatibleDimentionException::what() const {
	return message.c_str();
}