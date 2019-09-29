/*
 * main.cpp tests the classes in our project.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#include "Application.h"
#include "PlayListTester.h"
#include "SongTester.h"
#include <iostream>
#include <cstring>

int main(int argc, char **argv) {
	if ( argc == 1 ) {

		// Start the application
		Application app;
		app.start();

	} else if ( argc == 2 && strcmp(argv[1], "test") == 0 ) {

		// Run the test environment
		SongTester sTester;
		sTester.runTests();

		PlayListTester plTester;
		plTester.runTests();

	} else {

		std::cout << "Invalid arguments!" << std::endl;

	}

}




