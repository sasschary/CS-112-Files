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
	myFile = fileName;

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

/* Search by year
 * @param: year, and unsigned int
 * Return: a vector containing all the Songs in mySongs released in yeart.
 */
vector<Song> PlayList::searchByYear(unsigned year) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getYear() == year ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}

/* Search by title phrase
 * @param: phrase, a string
 * Return: a vector containing all the Songs in mySongs containing phrase in their title.
 */
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getTitle().find(phrase) != string::npos ) {
			v.push_back( mySongs[i] );
		}
	}

	return v;
}

/* Add a song to the playlist
 * @param: newSong, a Song
 * Postcondition: newSong has been appended to the end of the playlist
 */
void PlayList::addSong(const Song& newSong) {
	mySongs.push_back(newSong);
}

/* Remove a song from the playlist
 * @param: aSong, a Song
 * Postcondition: aSong has been removed from the playlist
 */
void PlayList::removeSong(const Song& aSong) {
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i] == aSong ) {
			mySongs.erase(mySongs.begin() + i);
		}
	}
}

/* Get a song from the playlist
 * @param: index, an unsigned int referring to the song's index within mySongs.
 * Return: the song with the specified index
 */
Song PlayList::getSong(unsigned index) {
	return mySongs[index];
}

/* Save the playlist to its original file
 * Precondition: The playlist exists
 * Postcondition: the playlist in its current state has been written to myfile
 */
void PlayList::save() const {

	// Open an ofstream and clear the contents of the file when it's opened.
	ofstream fout;
	fout.open(myFile, ofstream::trunc);

	// Write each of the songs in the playlist to the file
	for (unsigned i = 0; i < mySongs.size(); i++) {
		mySongs[i].writeTo(fout);
		fout << "---\n";
	}

	fout.close();
}
