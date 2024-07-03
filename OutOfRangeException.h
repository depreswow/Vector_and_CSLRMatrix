#pragma once
#include <iostream>
#include <string>

class OutOfRangeException : public std::exception {
	
	std::string message;

public:

	OutOfRangeException(int index, int size);
	const char* what() const override;

};