/*
 * Song.h declares a class for storing song information.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
using namespace std;

class Song {
public:
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;

private:
	string		myTitle;
	string		myArtist;
	unsigned	myYear;
};



#endif /* SONG_H_ */
