///*
// * List.cpp
// *
// *  Created on: Oct 7, 2019
// *      Author: Sasschary
// */
//
//#include "List.h"
//#include <iostream>
//#include <fstream>
//#include <cassert>
//
//List::List() {
//	mySize = 0;
//	myFirst = myLast = nullptr;
//
//}
//
//void List::makeCopyOf(const List &original) {
//	myFirst = myLast = nullptr;
//	mySize = 0;
//	Node *oPtr = original.myFirst;
//	while (oPtr != nullptr) {
//		append(oPtr -> myItem);
//		oPtr = oPtr -> myNext;
//	}
//}
//
//List::List(const List& original) {
//	makeCopyOf(original);
//}
//
//List::~List() {
//	delete myFirst;
//	myFirst = myLast = nullptr;
//	mySize = 0;
//}
//
//const unsigned List::getSize() const {
//	return mySize;
//}
//
//const Item& List::getFirst() const {
//	if (mySize == 0) {
//		throw underflow_error("Ya can't get the first element of an empty list, ya dingus!");
//	}
//
//	return myFirst -> myItem;
//}
//
//const Item& List::getLast() const {
//	if (mySize == 0) {
//		throw underflow_error("Ya can't get the last element of an empty list, ya dingus!");
//	}
//
//	return myLast -> myItem;
//}
//
//void List::append(const Item& newItem) {
//	Node* newNode = new Node(newItem, nullptr);
//
//	if (mySize == 0) {
//		myFirst = myLast = newNode;
//	} else {
//		myLast -> myNext = newNode;
//		myLast = newNode;
//	}
//	mySize++;
//}
//
//List& List::operator=(const List& original) {
//	if (&original != this) {
//		delete myFirst;
//		makeCopyOf(original);
//	}
//	return *this;
//}
//
///* Inequality operator
// * @param: list2, the list we will compare to this one to check for inequality
// * Returns: True if the lists are unequal, false if they are equal.
// *
// * Written by Zachary Clark
// */
//const bool List::operator!=(const List& list2) const {
//	if (mySize != list2.mySize) return true;
//
//	Node* myNodePtr = myFirst;
//	Node* otherNodePtr = list2.myFirst;
//
//	while (myNodePtr) {
//		if (myNodePtr -> myItem != otherNodePtr -> myItem) return true;
//		myNodePtr = myNodePtr -> myNext;
//		otherNodePtr = otherNodePtr -> myNext;
//	}
//
//	return false;
//}
//
///* Index retrieval
// * @param: item, the item that we want to find in the list.
// * Returns: The index of the first occurrence of the item
// *
// * Written by Zachary Clark
// */
//const int List::getIndexOf(const Item& item) const {
//	if (mySize == 0) return -1;
//
//	Node* nodePtr = myFirst;
//	for (unsigned i = 0; i < mySize; i++) {
//		if (nodePtr -> myItem == item) return i;
//		nodePtr = nodePtr -> myNext;
//	}
//
//	return -1;
//}
//
///* Removal operator
// * @param: index, the index of the item which will be removed
// * Returns: The Item from the Node which was removed
// *
// * Written by Zachary Clark
// */
//Item List::remove(int index) {
//	if (mySize == 0) {
//		throw range_error("Ya dummy, ya tried to remove an item from an empty list!");
//	}
//
//	if (index < 0) index = 0;
//	if (index > (int)mySize - 1) index = mySize - 1;
//
//	Item ret;
//	Node* prevPtr = myFirst;
//	Node* nodePtr = myFirst;
//
//	if (index == 0) {
//		ret = myFirst -> myItem;
//		Node* secondNode = myFirst -> myNext;
//		myFirst -> myNext = nullptr;
//		delete myFirst;
//		myFirst = secondNode;
//		mySize--;
//		// If the list is now empty...
//		if (mySize + 1 == 1) {
//			myLast = nullptr;
//			return ret;
//		}
//		return ret;
//	} else {
//		for (int i = 0; i < index; i++) {
//			prevPtr = nodePtr;
//			nodePtr = nodePtr -> myNext;
//		}
//		ret = nodePtr -> myItem;
//		prevPtr -> myNext = nodePtr -> myNext;
//		nodePtr -> myNext = nullptr;
//		delete nodePtr;
//		mySize--;
//	}
//
//	return ret;
//}
//
///* Filestream input, reads from fileName and inputs data to the list
// * @param fileName, the file which we will read data from
// * Postcondition: Our List's data is exactly that of the file
// *
// * Written by Zachary Clark
// */
//void List::readFrom(const string& fileName) {
//	for (unsigned i = 0; i < mySize; i++) {
//		remove(i);
//	}
//
//	ifstream fin(fileName);
//	assert( fin.is_open() );
//
//	Item input;
//	fin >> input;
//	while (!fin.eof()) {
//		append(input);
//		fin >> input;
//	}
//}
//
///* Stream output. Writes list's data to the ostream using separator sep
// * @param: out, an ostream we will write our data to
// * @param: sep, the separator we will use to separate each Item
// * Postcondition: out has the data from our List in it.
// *
// * Written by Zachary Clark
// */
//void List::writeTo(ostream& out, string sep) {
//	Node* nodePtr = myFirst;
//	for (unsigned i = 0; i < mySize; i++) {
//		out << nodePtr -> myItem << sep;
//		nodePtr = nodePtr -> myNext;
//	}
//}
//
//List::Node::Node() {
//	myItem = Item();
//	myNext = nullptr;
//}
//
//List::Node::Node(Item newItem, Node* newNext) {
//	myItem = newItem;
//	myNext = newNext;
//}
//
//List::Node::~Node() {
////	cout << "~Node() is deallocating the node containing item " << myItem << endl;
//	delete myNext;
//}
