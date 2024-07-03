#pragma once
#pragma once
#include <iostream>
#include <string>

class IncompatibleDimentionException : public std::exception {

	std::string message;

public:

	IncompatibleDimentionException(int index, int size);
	const char* what() const override;

};