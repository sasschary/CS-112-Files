/*
 * PlayList.cpp defines the PlayList methods.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#include "PlayList.h"
#include <cassert>
#include <fstream>

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
	// Open a stream to the playlist file
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// Read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// Close the stream
	fin.close();
}

/* Retrive length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
 * @param: artist, a string
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}


