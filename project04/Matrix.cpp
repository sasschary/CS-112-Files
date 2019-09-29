/* Matrix.cpp defines Matrix class methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

Vec<Item>& Matrix::operator[](unsigned index) {
	if ( index < myRows ) {
		return myVec[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

const Vec<Item>& Matrix::operator[](unsigned index) const {
	if ( index < myRows ) {
		return myVec[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

bool Matrix::operator!=(const Matrix& m2) const {
	return !(*this == m2);
}

void Matrix::readFrom(istream& in) {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			in >> myVec[i][j];
		}
	}
}

void Matrix::readFrom(const string fileName) {

	ifstream fin(fileName);
	assert( fin.is_open() );

	fin >> myRows >> myColumns;
	myVec.setSize(myRows);

	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
	}

	readFrom(fin);
	fin.close();
}

void Matrix::writeTo(ostream& out) const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << "\t" << flush;
		}
		out << "\n" << flush;
	}
}

void Matrix::writeTo(const string fileName) const {
	ofstream fout(fileName);
	assert( fout.is_open() );

	fout << myRows << "\t" << myColumns << "\n" << flush;
	writeTo(fout);

	fout.close();
}

Matrix Matrix::operator+(const Matrix& mat2) const {
	Matrix sum(myRows, myColumns);

	if ( myRows != mat2.getRows() || myColumns != mat2.getColumns() ) {
		throw invalid_argument("Matrices are not the same size!");
	} else {
		for (unsigned i = 0; i < myRows; i++) {
			for (unsigned j = 0; j < myColumns; j++) {
				sum[i][j] = myVec[i][j] + mat2[i][j];
			}
		}

	}

	return sum;
}

Matrix Matrix::operator-(const Matrix& mat2) const {
	Matrix diff(myRows, myColumns);

	if ( myRows != mat2.getRows() || myColumns != mat2.getColumns() ) {
		throw invalid_argument("Matrices are not the same size!");
	} else {
		for (unsigned i = 0; i < myRows; i++) {
			for (unsigned j = 0; j < myColumns; j++) {
				diff[i][j] = myVec[i][j] - mat2[i][j];
			}
		}

	}

	return diff;
}

Matrix Matrix::getTranspose() const {
	Matrix transpose(myColumns, myRows);

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			transpose[j][i] = myVec[i][j];
		}
	}

	return transpose;
}


