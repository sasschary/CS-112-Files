/*
 * main.cpp tests the classes in our project.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#include "PlayListTester.h"
#include "SongTester.h"

int main() {
	SongTester sTester;
	sTester.runTests();

	PlayListTester plTester;
	plTester.runTests();
}




