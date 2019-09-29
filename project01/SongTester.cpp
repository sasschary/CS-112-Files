/*
 * SongTester.cpp defines the test-methods for class SongTester.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#include "Song.h"
#include "SongTester.h"
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;

void SongTester::runTests() {
	cout << "Testing class Song..." << endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	testEqualTo();
	cout << "All tests passed!" << endl;
}

void SongTester::testConstructors() {
	cout << "- constructors ... " << flush;

	// Default constructor
	Song s;
	assert( s.getTitle() == "" );
	assert( s.getArtist() == "" );
	assert( s.getYear() == 0 );
	cout << " 0 " << flush;

	// Explicit constructor
	Song s1("Badge", "Cream", 1969);
	assert( s1.getTitle() == "Badge" );
	assert( s1.getArtist() == "Cream" );
	assert( s1.getYear() == 1969 );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void SongTester::testReadFrom() {
	cout << "- readFrom()... " << flush;
	ifstream fin("testSongs.txt");
	assert( fin.is_open() );
	Song s;
	string separator;

	// Read first song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Call Me Maybe" );
	assert( s.getArtist() == "Carly Rae Jepsen" );
	assert( s.getYear() == 2012 );
	cout << " 0 " << flush;

	// Read second song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 1 " << flush;

	// Read third song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "Joan Baez" );
	assert( s.getYear() == 1971 );
	cout << " 2 " << flush;

	// Read fourth song and separator in test playlist
	s.readFrom(fin);
	getline(fin, separator);
	assert( s.getTitle() == "Penny Lane" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 3 " << flush;

	fin.close();
	cout << "Passed!" << endl;
}

void SongTester::testWriteTo() {
	cout << "- writeTo()... " << flush;

	// Declare three songs
	Song s1("Badge", "Cream", 1969);
	Song s2("Godzilla", "Blue Oyster Cult", 1977);
	Song s3("Behind Blue Eyes", "The Who", 1971);

	// Write the three songs to an output file
	ofstream fout("testSongOutput.txt");
	assert( fout.is_open() );
	s1.writeTo(fout);
	fout << "---\n";
	s2.writeTo(fout);
	fout << "---\n";
	s3.writeTo(fout);
	fout << "---\n";
	fout.close();

	// Use readFrom() to see if writeTo() worked
	ifstream fin("testSongOutput.txt");
	assert( fin.is_open() );
	Song s4, s5, s6;
	string separator;

	// Read and check the first song
	s4.readFrom(fin);
	getline(fin, separator);
	assert( s4.getTitle() == "Badge" );
	assert( s4.getArtist() == "Cream" );
	assert( s4.getYear() == 1969 );
	cout << " 0 " << flush;

	// Read and check the second song
	s5.readFrom(fin);
	getline(fin, separator);
	assert( s5.getTitle() == "Godzilla" );
	assert( s5.getArtist() == "Blue Oyster Cult" );
	assert( s5.getYear() == 1977 );
	cout << " 1 " << flush;

	// Read and check the third song
	s6.readFrom(fin);
	getline(fin, separator);
	assert( s6.getTitle() == "Behind Blue Eyes" );
	assert( s6.getArtist() == "The Who" );
	assert( s6.getYear() == 1971 );
	cout << " 2 " << flush;

	fin.close();
	cout << "Passed!" << endl;
}


void SongTester::testEqualTo() {

	// Read in the test songs file
	cout << "- operator==()... " << flush;
	ifstream fin("testSongsEqual.txt");
	assert( fin.is_open() );
	Song s0, s1, s2, s3, s4, s5;
	string separator;
	s0.readFrom(fin);
	getline(fin, separator);
	s1.readFrom(fin);
	getline(fin, separator);
	s2.readFrom(fin);
	getline(fin, separator);
	s3.readFrom(fin);
	getline(fin, separator);
	s4.readFrom(fin);
	getline(fin, separator);
	s5.readFrom(fin);
	getline(fin, separator);

	// Test case where the songs are equal
	assert( s0 == s0 );
	cout << " 0 " << flush;

	// Test case where only the title differs
	assert( !( s1 == s3 ) );
	cout << " 1 " << flush;

	// Test case where only the artist differs
	assert( !( s0 == s4 ) );
	cout << " 2 " << flush;

	// Test case where only the year differs
	assert( !( s4 == s5 ) );
	cout << " 3 " << flush;

	fin.close();
	cout << "Passed!" << endl;

}
