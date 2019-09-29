/*
 * PlayListTester.h tests the PlayList class.
 * Student Name: Zachary Clark
 * Date: September 8th, 2019
 * Begun by: Joel Adams, for CS 122 at Calvin College (*cough* *cough* It's a University *cough* *cough*)
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testSearchByYear();
	void testSearchByTitlePhrase();
	void testAddRemoveSong();
	void testSave();
};

#endif /* PLAYLISTTESTER_H_ */
