#include <iostream>
#include "Vector.h"
#include "CSLRMatrix.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimentionException.h"

using namespace std;

int main() {
	int dimention;
	cout << "Enter your vector dimention: ";
	cin >> dimention;
	Vector vector(dimention), vector2(dimention);
	cout << endl << "Default vector with dimention = " << dimention << ": " << vector << endl << "Enter new values for the vector: ";
	for (int i = 0; i < dimention; i++) 
		cin >> vector[i];
	cout << endl << "Your vector: " << vector << endl;
	cout << "Enter values for the vector2: ";
	cin >> vector2;
	cout << endl << "Your vector2: " << vector2 << endl;
	cout << "Vector get_dimention method: " << vector.get_dimention() << endl;
	cout << "Vector length method: " << vector.length() << endl;
	cout << "Unary +: " << (+vector) << endl;
	cout << "Binary +: " << vector + vector2 << endl;
	cout << "Unary -: " << (-vector) << endl;
	cout << "Binary -: " << vector - vector2;
	cout << "+=: " << (vector += vector2) << endl;
	cout << "-=: " << (vector -= vector2) << endl;
	cout << "vector*2: " << (vector * 2) << endl;
	cout << "2*vector: " << (2 * vector) << endl;
	cout << "vector*vector2: " << (vector * vector2) << endl;
	CSLRMatrix matrix1, matrix2;
	cout << "Enter Matrix1:" << endl;
	cin >> matrix1;
	cout << "Enter Matrix2:" << endl;
	cin >> matrix2;
	cout << "Matrix1 get_dimention method: " << matrix1.get_dimention() << endl;
	cout << "Matrix1 get_element_amount method: " << matrix1.get_element_amount() << endl;
	cout << "Matrix1 * 2: " << matrix1 * 2 << endl;
	cout << "2 * Matrix1: " << 2 * matrix1 << endl;
	cout << "Matrix1 * vector: " << matrix1 * vector << endl;
	cout << "vector * Matrix1: " << vector * matrix1 << endl;
	cout << "Matrix1 * ((vector1 * 2) + vector2): " << matrix1 * ((vector * 2) + vector2) << endl;
	cout << "Move vector2 to vector3" << endl;
	Vector vector3(move(vector2));
	cout << "Vector2: " << vector2 << endl << "Vector3: " << vector3 << endl;
	try {
		cout << "vector3 * vector2 (ImcopatibleDimentionException): " << vector3 + vector2 << endl;
	}
	catch (const IncompatibleDimentionException& exception) {
		cerr << exception.what() << endl;
	}

	try {
		cout << "vector[" << dimention + 1 << "] (OutOfRangeException): " << vector[dimention + 1] << endl;;
	}
	catch (const OutOfRangeException& exception) {
		cerr << exception.what() << endl;
	}
}