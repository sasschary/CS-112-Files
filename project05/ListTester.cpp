/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *
 * Students: Zachary Clark and Nathan Bouman
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testInequality();
	testGetIndex();
	testRemove();
	testReadFromString();
	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == double() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11.0 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11; // @suppress("Assignment to itself")
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!" << endl;
}

/* Inequality tester
 * Tests operator !=
 *
 * Written by Zachary Clark
 */
void ListTester::testInequality() {
	cout << "Testing !=... " << flush;

	// Empty case
	List<double> l1, l2;
	assert( !(l1 != l2) );
	cout << " 0 " << flush;

	// Nonempty, different sizes
	List<double> l11, l12;
	l11.append(10);
	l11.append(11);
	l12.append(10);
	assert( l11 != l12 );
	cout << " 1 " << flush;

	// Nonempty, same size (1), but not equal
	List<double> l3, l4;
	l3.append(10);
	l4.append(11);
	assert( l3 != l4 );
	cout << " 2 " << flush;

	// Nonempty, same size (1), equal
	List<double> l5, l6;
	l5.append(10);
	l6.append(10);
	assert( !(l5 != l6) );
	cout << " 3 " << flush;

	// Nonempty, same size (2), but not equal
	List<double> l7, l8;
	l7.append(10);
	l8.append(11);
	l7.append(12);
	l8.append(13);
	assert( l7 != l8 );
	cout << " 4 " << flush;

	// Nonempty, same size (2), equal
	List<double> l9, l10;
	l9.append(10);
	l10.append(10);
	l9.append(11);
	l10.append(11);
	assert( !(l9 != l10) );
	cout << " 5 " << flush;

	cout << " Passed!" << endl;
}

/* Index retrieval tester
 * Tests list.getIndexOf(Item)
 *
 * Written by Zachary Clark
 */
void ListTester::testGetIndex() {
	cout << "Testing getIndexOf()... " << flush;

	// Empty case
	List<double> l1;
	assert( l1.getIndexOf(10) == -1 );
	cout << " 0 " << flush;

	// Single instance, only item in list
	List<double> l2;
	l2.append(10);
	assert( l2.getIndexOf(10) == 0 );
	cout << " 1 " << flush;

	// Single instance, not the only item in the list
	List<double> l3;
	l3.append(10);
	l3.append(11);
	l3.append(12);
	assert( l3.getIndexOf(10) == 0 );
	assert( l3.getIndexOf(11) == 1 );
	assert( l3.getIndexOf(12) == 2 );
	assert( l3.getIndexOf(13) == -1 );
	cout << " 2 " << flush;

	// Multiple instances
	List<double> l4;
	l4.append(10);
	l4.append(11);
	l4.append(11);
	l4.append(12);
	assert( l4.getIndexOf(11) == 1 );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

/* Item removal tester
 * Tests list.remove(index)
 *
 * Written by Zachary Clark
 */
void ListTester::testRemove() {
	cout << "Testing remove()... " << flush;

	// Remove from empty list
	List<double> l1;
	try {
		l1.remove(0);
		cerr << "Successfully removed Item from empty list";
		exit(1);
	} catch (range_error&) {
		cout << " 0 " << flush;
	}

	// Remove the sole item from a list
	List<double> l2;
	l2.append(10);
	double ret = l2.remove(0);
	assert( ret == 10 );
	assert( l2.mySize == 0 );
	assert( l2.myFirst == nullptr );
	assert( l2.myLast == nullptr );
	cout << " 1 " << flush;

	// Remove one item from a list of two items. Uses a negative index
	List<double> l3;
	l3.append(10);
	l3.append(11);
	ret = l3.remove(0);
	assert( ret == 10 );
	assert( l3.mySize == 1 );
	assert( l3.myFirst == l3.myLast );
	assert( l3.getIndexOf(10) == -1 );
	assert( l3.myFirst -> myItem == 11 );
	cout << " 2 " << flush;

	// Remove an item from a list of several items. Uses an index past the end of the list
	List<double> l4;
	l4.append(10);
	l4.append(11);
	l4.append(12);
	l4.append(13);
	ret = l4.remove(5);
	assert( ret == 13 );
	assert( l4.mySize == 3 );
	assert( l4.getIndexOf(13) == -1 );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

/* File read tester
 * Tests list.readFrom(string)
 *
 * Written by Zachary Clark
 */
void ListTester::testReadFromString() {
	cout << "Testing readFrom(string)... " << flush;
	List<double> l1;
	l1.append(10);
	l1.readFrom("ListInputTest1.txt");
	for (int i = 0; i < 5; i++) {
		assert( l1.getIndexOf(i + 11) == i );
	}
	assert( l1.mySize == 5);

	cout << " Passed!" << endl;
}

/* Stream write tester
 * Tests list.writeTo(ostream)
 *
 * Written by Zachary Clark
 */
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;
	List<double> l1;
	for (unsigned i = 10; i < 15; i++) {
		l1.append(i);
	}

	ofstream fout("ListOutputTest1.txt");
	assert( fout.is_open() );
	l1.writeTo(fout, "\t");

	List<double> l2;
	l2.readFrom("ListOutputTest1.txt");
	assert ( !(l2 != l1));

	cout << " Passed!" << endl;
}

//Testing Equality
// Written by Nathan Bouman
void ListTester::testEquality(){
	cout <<"Testing Equality... "<< flush;
	List<double> lista;
	List<double> listb;

	//test same a and b values
	for (int i = 0; i < 3; i++){
		lista.append(i);
		listb.append(i);
	}
	assert(lista.myFirst -> myItem == 0);
	assert(lista.myFirst -> myNext -> myItem == 1);
	assert(lista.myLast -> myItem == 2);
	assert(listb.myFirst -> myItem == 0);
	assert(listb.myFirst -> myNext -> myItem == 1);
	assert(listb.myLast -> myItem == 2);
	assert(lista == listb);
	cout <<" 0 "<< flush;

	//b and a are different
	listb.append(100);
	assert(listb.myLast -> myItem != lista.myLast -> myItem);
	assert (!(lista == listb));
	cout <<" 1 "<< flush;
	cout <<" Passed "<< endl;

}
//Testing readFrom istream
// Written by Nathan Bouman
void ListTester::testReadFromStream(){
	cout <<"Testing readFromstream... "<< flush;
	List<double> lista,listb;
	for (int i = 0; i < 3; i++){
		lista.append(i);
	}
	ifstream fin ("readFrom(istream)Test.txt");
	assert(fin.is_open());
	listb.readFrom(fin);
	assert(lista == listb);
	fin.close();
	cout <<" 0 "<< flush;
	cout <<" Passed "<< endl;
}
//Testing writeTo string
// Written by Nathan Bouman
void ListTester::testWriteToFile(){
	cout <<"Testing writeToFile... "<< flush;
	List<double> a;
	List<double> b;
	ifstream fin ("writeTo(string).txt");
	a.readFrom(fin);
	a.writeTo("testout.txt", '\n');
	fin.close();
	ifstream newfin("testout.txt");
	b.readFrom(newfin);
	assert (a == b);
	cout <<" 0 "<< flush;
	cout <<" Passed "<< endl;
}
//Testing Prepend
// Written by Nathan Bouman
void ListTester::testPrepend(){
	cout<< "Testing prepend... "<< flush;
	//test non-empty list
	List<double> list1;
	ifstream fin ("readFrom(istream)Test.txt");
	list1.readFrom(fin);
	list1.prepend(1);
	list1.prepend(0);
	//testing to see if nodes are in order
	assert(list1.myFirst -> myItem == 0);
	assert(list1.myFirst -> myNext -> myItem == 1);
	assert(list1.myFirst -> myNext -> myNext -> myItem == 0);
	assert(list1.myFirst -> myNext -> myNext -> myNext -> myItem == 1);
	assert(list1.myLast -> myItem == 2);
	cout <<" 0 "<< flush;
	//test empty list
	List<double> list0;
	list0.prepend(0);
	assert(list0.mySize == 1);
	assert(list0.myFirst -> myItem == 0);
	cout <<" 1 "<< flush;
	cout <<"Passed"<< endl;
}
//Testing Append
// Written by Nathan Bouman
void ListTester::testInsert(){
	cout<<"Testing insert..."<< flush;
	List<double> list1;
	ifstream fin("readFrom(istream)Test.txt");
	list1.readFrom(fin);
	//testing at 0
	list1.insert(5,0);
	assert(list1.myFirst -> myItem == 5);
	assert(list1.myFirst -> myNext -> myItem == 0);
	assert(list1.myFirst -> myNext -> myNext -> myItem == 1);
	assert(list1.myLast -> myItem == 2);
	cout <<" 0 "<< flush;
	//testing at 1
	list1.insert(5,1);
	assert(list1.myFirst -> myItem == 5);
	assert(list1.myFirst -> myNext -> myItem == 5);
	assert(list1.myFirst -> myNext -> myNext -> myItem == 0);
	assert(list1.myFirst -> myNext -> myNext -> myNext -> myItem == 1);
	assert(list1.myLast -> myItem == 2);
	cout <<" 1 "<< flush;
	cout <<" Passed "<< endl;
}

