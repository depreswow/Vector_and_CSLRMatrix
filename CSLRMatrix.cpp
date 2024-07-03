#include "CSLRMatrix.h"
#include <iostream>

CSLRMatrix::CSLRMatrix() {
	adiag = nullptr;
	dimention = 0;
	atr = nullptr;
	atr_size = 0;
	jptr = nullptr;
	iptr = nullptr;
	iptr_size = 0;
}

CSLRMatrix::CSLRMatrix(const double* in_adiag, int in_dimention, const double* in_atr, const double* in_jptr, int in_atr_size, const double* in_iptr, int in_iptr_size) 
	: dimention(in_dimention), atr_size(in_atr_size), iptr_size(in_iptr_size) {
	adiag = new double[dimention];
	for (int i = 0; i < dimention; i++) 
		adiag[i] = in_adiag[i];
	atr = new double[atr_size];
	jptr = new int[atr_size];
	for (int i = 0; i < atr_size; i++) { 
		atr[i] = in_atr[i]; 
		jptr[i] = in_jptr[i]; 
	}
	iptr = new int[iptr_size];
	for (int i = 0; i < iptr_size; i++) 
		iptr[i] = in_iptr[i];
}
CSLRMatrix::CSLRMatrix(const CSLRMatrix& matrix) 
	: dimention(matrix.dimention), atr_size(matrix.atr_size), iptr_size(matrix.iptr_size) {
	adiag = new double[dimention];
	for (int i = 0; i < dimention; i++) 
		adiag[i] = matrix.adiag[i];
	atr = new double[atr_size];
	jptr = new int[atr_size];
	for (int i = 0; i < atr_size; i++) { 
		atr[i] = matrix.atr[i]; 
		jptr[i] = matrix.jptr[i]; }
	iptr = new int[iptr_size];
	for (int i = 0; i < iptr_size; i++) 
		iptr[i] = matrix.iptr[i];
}

CSLRMatrix::~CSLRMatrix() {
	delete[] adiag;
	delete[] atr;
	delete[] jptr;
	delete[] iptr;
}

int CSLRMatrix::get_dimention() const { 
	return dimention; 
}
int CSLRMatrix::get_element_amount() const { 
	return (dimention + (atr_size * 2)); 
}

CSLRMatrix& CSLRMatrix::operator=(const CSLRMatrix& matrix) {
	if (this == &matrix)
		return *this;
	dimention = matrix.dimention;
	atr_size = matrix.atr_size;
	iptr_size = matrix.iptr_size;
	delete[] adiag;
	delete[] atr;
	delete[] jptr;
	delete[] iptr;
	adiag = new double[dimention];
	for (int i = 0; i < dimention; i++)
		adiag[i] = matrix.adiag[i];
	atr = new double[atr_size];
	jptr = new int[atr_size];
	for (int i = 0; i < atr_size; i++) {
		atr[i] = matrix.atr[i];
		jptr[i] = matrix.jptr[i];
	}
	iptr = new int[iptr_size];
	for (int i = 0; i < iptr_size; i++)
		iptr[i] = matrix.iptr[i];
	return *this;
}

CSLRMatrix CSLRMatrix::operator*(double number) const {
	CSLRMatrix buffer(*this);
	for (int i = 0; i < dimention; i++) 
		buffer.adiag[i] *= number;
	for (int i = 0; i < atr_size; i++) 
		buffer.atr[i] *= number;
	return buffer;
}

Vector CSLRMatrix::operator*(const Vector& vector) const {
	if (dimention != vector.get_dimention())
		throw IncompatibleDimentionException(dimention, vector.get_dimention());
	Vector answer(vector.get_dimention());
	for (int i = 0; i < this->get_dimention(); i++) 
		answer[i] = vector[i] * adiag[i];
	for (int i = 0; i < this->get_dimention(); i++) {
		for (int j = iptr[i]; i < iptr[i + 1]; i++) {
			answer[i] += (vector[jptr[j]] * atr[j]);
			answer[jptr[j]] += (vector[i] * atr[j]);
		}
	}
	return answer;
}
CSLRMatrix operator*(double number, const CSLRMatrix& matrix) { 
	return (matrix * number); 
}

Vector operator*(const Vector& vector, const CSLRMatrix& matrix) {
	return matrix * vector;
}

std::istream& operator>>(std::istream& p_in, CSLRMatrix& matrix) {
	p_in >> matrix.dimention;
	for (int i = 0; i < matrix.dimention; i++) 
		p_in >> matrix.adiag[i];
	
	p_in >> matrix.atr_size;
	for (int i = 0; i < matrix.atr_size; i++) 
		p_in >> matrix.atr[i];
	
	for (int i = 0; i < matrix.atr_size; i++) 
		p_in >> matrix.jptr[i];
	
	p_in >> matrix.iptr_size;
	for (int i = 0; i < matrix.iptr_size; i++) 
		p_in >> matrix.iptr[i];
	return p_in;
}
std::ostream& operator<<(std::ostream& p_out, const CSLRMatrix& matrix) {
	p_out << "adiag: ";
	for (int i = 0; i < matrix.dimention; i++) 
		p_out << matrix.adiag[i] << " ";
	p_out << "\n";
	
	p_out << "atr: ";
	for (int i = 0; i < matrix.atr_size; i++) 
		p_out << matrix.atr[i];
	p_out << "\n";
	
	p_out << "jptr: ";
	for (int i = 0; i < matrix.atr_size; i++) 
		p_out << matrix.jptr[i];
	p_out << "\n";
	
	p_out << "iptr: ";
	for (int i = 0; i < matrix.iptr_size; i++) 
		p_out << matrix.iptr[i];
	p_out << "\n";
	return p_out;
}