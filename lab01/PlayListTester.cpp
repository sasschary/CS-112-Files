/*
 * PlayListTester.cpp defines the PlayList test-methods.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <cassert>
#include <iostream>
using namespace std;

void PlayListTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}

void PlayListTester::testSearchByArtist() {
	cout << "- searchByArtist()... " << flush;
	// Load a playlist with test songs
	PlayList pList("testSongs.txt");

	// Empty case (0 artists)
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// Case of 1 artist
	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	cout << " 1 " << flush;

	// Case of 2 artists
	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}
