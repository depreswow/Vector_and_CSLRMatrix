#pragma once
#include "CSLRMatrix.h"
#include <iostream>
#include "OutOfRangeException.h"
#include "IncompatibleDimentionException.h"

class Vector {
	friend class CSLRMatrix;
	friend class OutOfRangeException;
	friend class IncompatibleDimentionException;

	int vector_dimention;
	double* vector_values;

public:
	Vector();
	explicit Vector(int size);
	explicit Vector(int size, double value);
	Vector(const Vector& vector_2);
	Vector(Vector&& vector_2);
	~Vector();

	int get_dimention() const;
	double length() const;

	Vector& operator+();

	Vector operator+(const Vector &vector2) const;

	Vector operator-();

	Vector operator-(const Vector &vector2) const;

	Vector& operator=(const Vector &vector2);

	Vector& operator+=(const Vector &vector2);

	Vector& operator-=(const Vector &vector2);

	Vector operator*(double number) const;
	double operator*(const Vector &vector2) const;
	friend Vector operator*(double number, Vector& vector);
	

	double& operator[](int index);
	const double& operator[](int index) const;

	friend std::istream& operator>>(std::istream& p_in, Vector& vec);
	friend std::ostream& operator<<(std::ostream& p_out, const Vector& vec);

	explicit operator double ();
};