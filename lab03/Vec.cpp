/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
 
#include "Vec.h"
#include <stdexcept>

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if ( size > 0 ) {
		myArray = new Item[size]();
	} else {
		myArray = nullptr;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( mySize > 0 ) {
		myArray = new Item[mySize];

		for ( unsigned i = 0; i < mySize; i++ ) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

Vec::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	if ( this != &original ) {

		if ( mySize != 0 && mySize != original.mySize ) {
			delete [] myArray;
			myArray = nullptr;
		}

		if ( original.mySize == 0 ) {
			myArray = nullptr;
			mySize = 0;
		}

		if ( mySize != original.mySize  ) {
			myArray = new Item[original.mySize];
			mySize = original.mySize;
		}

		for ( unsigned i = 0; i < mySize; i++ ) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

void Vec::setItem(unsigned index, const Item& it) {
	if ( index < mySize && myArray != nullptr ) {
		myArray[index] = it;
	} else {
		throw std::range_error("Index out of range!");
	}
}

Item Vec::getItem(unsigned index) const {
	if ( index < mySize && myArray != nullptr ) {
		return myArray[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

void Vec::setSize(unsigned newSize) {
	if ( mySize != newSize ) {
		if ( newSize == 0 ) {
			delete [] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item *newArray = new Item[newSize]();
			if ( mySize != 0 ) {
				for ( unsigned i = 0; i < mySize; i++ ) {
					newArray[i] = myArray[i];
					if ( i + 1 == newSize ) break;
				}
				delete myArray;
			}

			myArray = newArray;
			mySize = newSize;
		}
	}
}

bool Vec::operator==(const Vec& v2) const {
	if ( mySize != v2.mySize ) return false;

	for ( unsigned i = 0; i < mySize; i++ ) {
		if ( myArray[i] != v2.myArray[i] ) return false;
	}

	return true;
}

void Vec::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++ ) {
		out << myArray[i] << endl;
	}
}

void Vec::readFrom(istream& in) {
	for( unsigned i = 0; i < mySize; i++ ) {
		in >> myArray[i];
	}
}
