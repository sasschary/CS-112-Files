/*
 * Application.h declares class Application.
 * Student Name: Zachary Clark
 * Date: September 9th, 2019
 * Begun by: Zachary Clark for CS 112 Project 1
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include "PlayList.h"
using namespace std;

class Application {
public:
	void start();

private:
	void displayOptions();
	PlayList choosePlayList();
	void printResults(vector<Song> results);
	Song inputUserSong();

};



#endif /* APPLICATION_H_ */
