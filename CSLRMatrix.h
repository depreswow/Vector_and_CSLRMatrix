#pragma once
#include "Vector.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimentionException.h"
#include <iostream>

class CSLRMatrix {

	friend class Vector;
	friend class OutOfRangeException;
	friend class IncompatibleDimentionException;

	double* adiag;
	int dimention;

	double* atr;
	int atr_size;

	int* jptr;

	int* iptr;
	int iptr_size;

public:
	CSLRMatrix();
	CSLRMatrix(const double* in_adiag, int in_dimention, const double* in_atr, const double* in_jptr, int in_atr_size, const double* in_iptr, int in_iptr_size);
	CSLRMatrix(const CSLRMatrix& matrix);
	~CSLRMatrix();

	int get_element_amount() const;
	int get_dimention() const;

	CSLRMatrix& operator=(const CSLRMatrix& matrix);

	CSLRMatrix operator*(double number) const;
	Vector operator*(const Vector& vector) const;
	friend CSLRMatrix operator*(double number, const CSLRMatrix& matrix);
	friend Vector operator*(const Vector& vector, const CSLRMatrix& matrix);

	friend std::istream& operator>>(std::istream& p_in, CSLRMatrix& matrix);
	friend std::ostream& operator<<(std::ostream& p_out, const CSLRMatrix& matrix);

};