/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Zachary Clark
 * Date: 11-11-19
 */

 #include "ArrayQueueTester.h"
 #include "LinkedQueueTester.h"
 
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	LinkedQueueTester lqt;
 	lqt.runTests();
 }
 
 
