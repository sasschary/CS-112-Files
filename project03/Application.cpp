/*
 * Application.cpp runs the application for addin multiple vectors together.
 * Student Name: Zachary Clark and Christian Mutschler
 * Date: 9-27-19
 */

#include "Application.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/* Run the application
 * Precondition: none.
 * Postcondition: The final value has been printed to the console, and stored in finalPoint.
 */
void Application::run() {
	string ptInput;
	Vec finalPoint(dims), newVector(dims);

	cout << "\nWelcome! " << flush;

	// While we don't have a valid number of dimensions...
	while ( dims == 0 ) {
		cout << "Please enter the number of dimensions in your space: " << flush;
		cin >> dims;
	}

	cout << "\nPlease enter the starting point, as comma separated points, e.g. 0,0,0: " << flush;
	cin >> ptInput;

	// Count the number of commas in the point. If it is not equal to dims - 1, there are not the right number of elements, so try again.
	unsigned commas = count(ptInput.begin(), ptInput.end(), ',');
	while ( commas != dims - 1) {
		cout << "Invalid number of coordinates. Please input a starting point as comma separated points, or type 'q' to quit and show the final position: " << flush;
		cin >> ptInput;
		commas = count(ptInput.begin(), ptInput.end(), ',');
	}

	// Parse the initial point
	finalPoint = parsePoint(ptInput);

	// Loop and keep asking for and adding new points. If parsePoint() returns a vector of size zero, the user has stopped inputting new vectors, so break out of the loop.
	while (true) {
		newVector = inputNewVector();
		if (newVector.getSize() == 0) {
			break;
		}
		finalPoint = finalPoint + newVector;
	}

	// Output the ending location.
	cout << "The final location is: (" << flush;
	for ( unsigned i = 0; i < dims - 1; i++ ) {
		cout << finalPoint[i] << ", " << flush;
	}
	cout << finalPoint[dims-1] << ")" << endl;
}

/* Parse a point/vector from a string
 * @param: ptInput, a string which contains comma-separated elements of a point or vector
 * Returns the split string as a new vector.
 */
Vec Application::parsePoint(string ptInput) {
	Vec point(dims);
	Item coord;
	string delimiter = ",";

	for( unsigned i = 0; i < dims; i++ ) {
		// Find a substring of ptInput from the beginning of the string to the first comma.
		// Then, convert to a cstring, and convert the cstring to an Item and assign it to coord.
		coord = atoi(ptInput.substr(0, ptInput.find(delimiter)).c_str());

		// Then, erase the first element from the string, so that the next loop will find the next element. Then, set the element of the vector to coord.
		ptInput.erase(0, ptInput.find(delimiter) + delimiter.length());
		point[i] = coord;
	}

	return point;
}

/* Has the user input a new vector, and returns the parsed version of that vector.
 * Returns a parsed vector based on user input
 */
Vec Application::inputNewVector() {
	string ptInput;
	Vec inputPoint(dims);

	cout << "Please input a vector as comma separated points, or type 'q' to quit and show the final position: " << flush;
	cin >> ptInput;

	// Check the number of commas to verify we have the correct number of dimensions
	unsigned commas = count(ptInput.begin(), ptInput.end(), ',');
	while ( commas != dims - 1 && ptInput != "q" ) {
		cout << "Invalid number of coordinates. Please input a vector as comma separated points, or type 'q' to quit and show the final position: " << flush;
		cin >> ptInput;
		commas = count(ptInput.begin(), ptInput.end(), ',');
	}

	// If the user has input "q", they don't want to put in any more vectors, so set the vector's size to zero. Otherwise, parse the input and return the vector.
	if ( ptInput == "q" ) {
		inputPoint.setSize(0);
	} else {
		inputPoint = parsePoint(ptInput);
	}

	return inputPoint;
}

