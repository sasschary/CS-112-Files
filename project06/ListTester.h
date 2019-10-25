/*
 * ListTester.h
 *
 *  Created on: Oct 15, 2019
 *      Author: zac6
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	ListTester();
	void runTests();

private:
	void testInsertAfter();
	void testInsertBefore();
	void testOutput();
};

#endif /* LISTTESTER_H_ */
