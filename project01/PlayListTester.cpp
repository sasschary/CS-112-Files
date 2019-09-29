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
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddRemoveSong();
	testSave();
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

void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()... " << flush;

	// Load a playlist with test songs
	PlayList pList("testSongs.txt");

	// Empty case (Year 2015)
	vector<Song> searchResult = pList.searchByYear(2015);
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// Case of 1 year
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	// Case of 2 years
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void PlayListTester::testSearchByTitlePhrase() {
	cout << "- searchByTitlePhrase()... " << flush;

	// Load a playlist with test songs
	PlayList pList("testSongs.txt");

	// Empty case (random characters that aren't in a title)
	vector<Song> searchResult = pList.searchByTitlePhrase("ThisWillBeNowhereInTheTitles");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// Case of 1 song with the phrase
	searchResult = pList.searchByTitlePhrase("Maybe");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	// Case of 2 songs with the phrase
	searchResult = pList.searchByTitlePhrase("Let");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[0].getArtist() == "The Beatles" );
	assert( searchResult[1].getTitle() == "Let It Be" );
	assert( searchResult[1].getArtist() == "Joan Baez" );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void PlayListTester::testAddRemoveSong() {
	cout << "- addSong()... " << flush;

	// Load a playlist with only a single song
	PlayList pList("singleSong.txt");

	// Create and add a song to the playlist
	Song s1("Time", "Hans Zimmer", 2010);
	pList.addSong(s1);

	// Ensure there are two songs in the playlist and that the song we just added is in the playlist
	assert( pList.getNumSongs() == 2 );
	assert( pList.searchByTitlePhrase("Time").size() == 1 );
	cout << " 0 " << flush;

	// Add and test another song. Also test that there are now two songs by Hans Zimmer in the list.
	Song s2("Stay", "Hans Zimmer", 2014);
	pList.addSong(s2);
	assert( pList.getNumSongs() == 3 );
	assert( pList.searchByTitlePhrase("Stay").size() == 1 );
	assert( pList.searchByArtist("Hans Zimmer").size() == 2 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
	cout << "- removeSong()... " << flush;

	// Remove the first song we added to ensure that removeSong() works
	// while also testing that we don't have to remove them in any order.
	pList.removeSong(s1);
	assert( pList.getNumSongs() == 2 );
	assert( pList.searchByTitlePhrase("Time").size() == 0 );
	assert( pList.searchByArtist("Hans Zimmer").size() == 1 );
	cout << " 0 " << flush;

	// Remove the second song we added previously
	pList.removeSong(s2);
	assert( pList.getNumSongs() == 1 );
	assert( pList.searchByTitlePhrase("Stay").size() == 0 );
	assert( pList.searchByArtist("Hans Zimmer").size() == 0 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;

}

void PlayListTester::testSave() {

	cout << "- save()... " << flush;

	// Read in testSave.txt to a playlist, then add a new song to it and remove a different one.
	PlayList pl1("testSave.txt");
	Song s1("Stay", "Hans Zimmer", 2014);
	Song s2("Call Me Maybe", "Carly Rae Jepsen", 2012);
	pl1.addSong(s1);
	pl1.removeSong(s2);

	// Save the playlist, then create a second playlist from the file.
	pl1.save();
	PlayList pl2("testSave.txt");

	// Iterate through the songs in pl1 and pl2 and verify that every one is the same song.
	for (unsigned i = 0; i < pl1.getNumSongs(); i++) {
		assert( pl1.getSong(i) == pl2.getSong(i) );
		cout << " " << i << " " << flush;
	}

	cout << "Passed!" << endl;

}
