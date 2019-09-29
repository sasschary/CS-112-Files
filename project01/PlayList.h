
/*
 * PlayList.h declares class PlayList.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <string>
#include <vector>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year) const;
	vector<Song> searchByTitlePhrase(const string& phrase) const;
	void addSong(const Song& newSong);
	void removeSong(const Song& aSong);
	Song getSong(unsigned index);
	void save() const;

private:
	vector<Song> mySongs;
	string myFile;
};

#endif /* PLAYLIST_H_ */
