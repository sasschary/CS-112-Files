/*
 * Application.cpp runs the application itself.
 * Student Name: Zachary Clark
 * Date: September 9th, 2019
 * Begun by: Zachary Clark for CS 112 Project 1
 */

#include "Application.h"


/* Runs the application.  */
void Application::start() {

	cout << "Welcome to the PlayList Manager!" << endl << endl;

	unsigned choice;
	string search;
	vector<Song> results;

	// Ask the user for the playlist to start out with.
	PlayList pl = choosePlayList(); // @suppress("Invalid arguments")

	while ( true ) {

		// Display menu options and wait for user input
		displayOptions();
		cin >> choice;
		cin.ignore();

		// Based on the user's input, choose what to do next
		switch(choice) {

		// Artist search
		case 1:
			cout << "Enter artist to search: " << flush;
			cin >> search;
			results = pl.searchByArtist(search);
			printResults(results);
			break;

		// Year search
		case 2:
			cout << "Enter year to search: " << flush;
			cin >> search;
			results = pl.searchByYear(atoi(search.c_str()));
			printResults(results);
			break;

		// Title phrase search
		case 3:
			cout << "Enter title phrase to search: " << flush;
			cin >> search;
			results = pl.searchByTitlePhrase(search);
			printResults(results);
			break;

		case 4:
			pl.addSong(inputUserSong());
			cout << "Song added!" << endl;
			break;

		case 5:
			pl.removeSong(inputUserSong());
			cout << "Song removed!" << endl;
			break;

		case 6:
			pl.save();
			cout << "Playlist saved!" << endl;
			break;

		case 7:
			pl = choosePlayList();
			break;

		case 0:
			cout << "Goodbye!" << endl;
			exit(0);
		}
	}
}

/* Displays the menu options to the user. */
void Application::displayOptions() {
	cout << "Please enter:" << endl;
	cout << "    1 - To search the playlist for songs by a given artist" << endl;
	cout << "    2 - To search the playlist for songs from a given year" << endl;
	cout << "    3 - To search the playlist for songs with a given  phrase in their title" << endl;
	cout << "    4 - To add a new song to the playlist" << endl;
	cout << "    5 - To remove all instances of a song from the playlist" << endl;
	cout << "    6 - To save the playlist" << endl;
	cout << "    7 - To open a new playlist" << endl;
	cout << "    0 - To quit" << endl;
	cout << ">" << flush;
}

/* Allows the user to input a filename that will either be created or turned into a playlist
 * Return: chosenPl, a playlist from the filename that was input
 */
PlayList Application::choosePlayList() {
	string filename;
	cout << "Please enter the filename of a playlist to open or create: " << flush;
	cin >> filename;
	PlayList chosenPl(filename);
	return chosenPl;
}

/* Prints the results from a search to the console
 * @param: results, a vector<Song>
 */
void Application::printResults(vector<Song> results) {

	// If there are no results, tell the user.
	if ( results.size() == 0 ) {
		cout << "No results!" << endl;
	} else {			// Otherwise, print all results to the console.
		cout << endl;
		for (unsigned i = 0; i < results.size(); i++) {
			results[i].writeToConsole();
			cout << "---" << endl;
		}
	}
	cout << endl;

}

/* Has the user input data for a new song
 * Returns: a Song with the data which user inputs
 */
Song Application::inputUserSong() {
	string newSongTitle, newSongArtist, newSongYearString;
	unsigned newSongYear;

	cout << "Enter the song's title: " << flush;
	getline(cin, newSongTitle); // Extra line input so that a leftover \n doesn't mess up title input due to switching from cin to getline.
	getline(cin, newSongTitle);
	cout << "Enter the song's artist: " << flush;
	getline(cin, newSongArtist);
	cout << "Enter the song's release year: " << flush;
	getline(cin, newSongYearString);
	newSongYear = atoi(newSongYearString.c_str());

	return Song(newSongTitle, newSongArtist, newSongYear);
}


