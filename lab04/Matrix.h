/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {

public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;

	unsigned getRows() const { return myRows; }
	unsigned getColumns() const { return myColumns; }

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;

	friend class MatrixTester;

};

#endif
