/*
 * ListTester.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: zac6
 */

#include "ListTester.h"
#include "List.h"
#include <iostream>
#include <cassert>
using namespace std;

ListTester::ListTester() {
	// TODO Auto-generated constructor stub

}

void ListTester::runTests() {
	testInsertAfter();
	testInsertBefore();
	testOutput();

	cout << "\nAll tests passed!" << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing insertAfter()... " << flush;
	List<double> l1;
	for (unsigned i = 0; i < 50; i++) {
		l1.append(i);
	}

	// Insert a bunch of numbers and make sure they are added successfully
	bool ret = l1.insertAfter(9, 100);
	assert(ret == true);
	ret = l1.insertAfter(18, 200);
	assert(ret == true);
	ret = l1.insertAfter(27, 300);
	assert(ret == true);
	ret = l1.insertAfter(36, 400);
	assert(ret == true);
	ret = l1.insertAfter(45, 500);
	assert(ret == true);

	// Insert an item after an item which is not in the line, and check that it is unsuccessful.
	ret = l1.insertAfter(400000, 99);
	assert(ret == false);

	assert(l1.getSize() == 55);

	// Iterate through the list and verify that all the items were inserted properly
	unsigned j = 0;
	for (unsigned i = 0; i < 54; i++) {
		if (i % 10 == 0 && i != 0) {
			assert(l1.getIndexOf(i * 10) == (double)i);
		} else {
			assert(l1.getIndexOf(j) == (double)i);
			j++;
		}
	}
	cout << " Passed!" << endl;
}

void ListTester::testInsertBefore() {
	cout << "Testing insertBefore()... " << flush;
	List<double> l1;
	for (unsigned i = 0; i < 50; i++) {
		l1.append(i);
	}

	// Insert a bunch of numbers and make sure they are added successfully
	bool ret = l1.insertBefore(10, 100);
	assert(ret == true);
	ret = l1.insertBefore(19, 200);
	assert(ret == true);
	ret = l1.insertBefore(28, 300);
	assert(ret == true);
	ret = l1.insertBefore(37, 400);
	assert(ret == true);
	ret = l1.insertBefore(46, 500);
	assert(ret == true);

	// Insert an item after an item which is not in the line, and check that it is unsuccessful.
	ret = l1.insertBefore(400000, 99);
	assert(ret == false);

	assert(l1.getSize() == 55);

	// Iterate through the list and verify that all the items were inserted properly
	unsigned j = 0;
	for (unsigned i = 0; i < 54; i++) {
		if (i % 10 == 0 && i != 0) {
			cout << i << flush;
			assert(l1.getIndexOf(i * 10) == (double)i);
		} else {
			assert(l1.getIndexOf(j) == (double)i);
			j++;
		}
	}

	cout << " Passed!" << endl;
}

void ListTester::testOutput() {
	cout << "Testing output... " << flush;

	List<double> l1;
	for (unsigned i = 0; i < 10; i++) {
			l1.append(i);
	}

	ofstream out("testOutput.txt");
	assert(out.is_open());
	out << l1 << flush;
	out.close();

	ifstream fin("correctTestOutput.txt");
	assert(fin.is_open());
	string correctOutput;
	getline(fin, correctOutput);
	fin.close();

	ifstream fin2("testOutput.txt");
	assert(fin2.is_open());
	string testOutput;
	getline(fin2, testOutput);
	fin2.close();

	assert(correctOutput == testOutput);

	cout << " Passed!" << endl;
}
