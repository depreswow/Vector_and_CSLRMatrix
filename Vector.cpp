#include <iostream>
#include "Vector.h"


Vector::Vector() : vector_dimention(0), vector_values(nullptr) {};

Vector::Vector(int size) 
	: vector_dimention(size) {
	vector_values = new double[size];
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] = 0.;
}
Vector::Vector(int size, double value) 
	: vector_dimention(size) {
	vector_values = new double[size];
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] = value;
}
Vector::Vector(const Vector& vector_2) 
	: vector_dimention(vector_2.get_dimention()) {
	vector_values = new double[vector_dimention];
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] = vector_2[i];
}
Vector::Vector(Vector&& vector2) {
	vector_dimention = vector2.get_dimention();
	vector_values = vector2.vector_values;
	vector2.vector_values = nullptr;
	vector2.vector_dimention = 0;
}
Vector::~Vector() {
	delete[] vector_values;
	vector_values = nullptr;
	vector_dimention = 0;
}

int Vector::get_dimention() const {
	return vector_dimention;
}

double Vector::length() const {
	double sum = 0;
	for (int i = 0; i < vector_dimention; i++) 
		sum += (vector_values[i] * vector_values[i]);
	return sqrt(sum);
}

Vector& Vector::operator+() {
	return *this;
}

Vector Vector::operator+(const Vector& vector2) const {
	if (vector_dimention != vector2.vector_dimention)
		throw IncompatibleDimentionException(vector_dimention, vector2.vector_dimention);
	Vector buffer(*this);
	for (int i = 0; i < vector_dimention; i++)
		buffer.vector_values[i] += vector2.vector_values[i];
	return buffer;
}

Vector Vector::operator-() {
	Vector buffer(*this);
	for (int i = 0; i < vector_dimention; i++) 
		buffer.vector_values[i] = -buffer.vector_values[i];
	return buffer;
}

Vector Vector::operator-(const Vector& vector2) const {
	if (vector_dimention != vector2.vector_dimention)
		throw IncompatibleDimentionException(vector_dimention, vector2.vector_dimention);
	Vector buffer(*this);
	for (int i = 0; i < vector_dimention; i++) 
		buffer.vector_values[i] -= vector2.vector_values[i];
	return buffer;
}

Vector& Vector::operator=(const Vector& vector2) {
	if (this == &vector2)
		return *this;
	if (vector_dimention != vector2.vector_dimention) {
		vector_dimention = vector2.vector_dimention;
		delete[] vector_values;
		vector_values = new double[vector_dimention];
	}
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] = vector2.vector_values[i];
	return *this;
}

Vector& Vector::operator+=(const Vector& vector2) {
	if (vector_dimention != vector2.vector_dimention)
		throw IncompatibleDimentionException(vector_dimention, vector2.vector_dimention);
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] += vector2.vector_values[i];
	return *this;
}

Vector& Vector::operator-=(const Vector& vector2) {
	if (vector_dimention != vector2.vector_dimention)
		throw IncompatibleDimentionException(vector_dimention, vector2.vector_dimention);
	for (int i = 0; i < vector_dimention; i++) 
		vector_values[i] -= vector2.vector_values[i];
	return *this;
}

Vector Vector::operator*(double number) const {
	Vector buffer(*this);
	for (int i = 0; i < vector_dimention; i++) 
		buffer.vector_values[i] = buffer.vector_values[i] * number;
	return buffer;
}

double Vector::operator*(const Vector& vector2) const {
	if (vector_dimention != vector2.vector_dimention)
		throw IncompatibleDimentionException(vector_dimention, vector2.vector_dimention);
	double res=0;
	for (int i = 0; i < vector_dimention; i++) 
		res += (vector_values[i] * vector2.vector_values[i]);
	return res;
}

Vector operator*(double number, Vector& vector) { 
	return vector * number; 
}

double& Vector::operator[](int index) { 
	if (index >= vector_dimention || index < 0)
		throw OutOfRangeException(index, vector_dimention);
	return vector_values[index]; 
}

const double& Vector::operator[](int index) const {
	if (index >= vector_dimention || index < 0)
		throw OutOfRangeException(index, vector_dimention);
	return vector_values[index];
}

std::istream& operator>>(std::istream& p_in, Vector& vec) {
	for (int i = 0; i < vec.get_dimention(); i++) 
		p_in >> vec[i];
	return p_in;
}
std::ostream& operator<<(std::ostream& p_out, const Vector& vec) {
	for (int i = 0; i < vec.get_dimention(); i++) 
		p_out << vec[i] << " ";
	p_out << "\n";
	return p_out;
}

Vector::operator double () {
	return this->length();
}
