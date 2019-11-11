/* ArrayQueueTester.h declares the class that tests class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Zachary Clark
 * Date: 11-11-19
 */
 
#ifndef QUEUETESTER_H_
#define QUEUETESTER_H_

#include "ArrayQueue.h"

class ArrayQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
};

#endif /*QUEUETESTER_H_*/
