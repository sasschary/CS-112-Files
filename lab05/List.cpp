/*
 * List.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: Sasschary
 */

#include "List.h"
#include <iostream>

using namespace std;

List::List() {
	mySize = 0;
	myFirst = myLast = nullptr;

}

void List::makeCopyOf(const List &original) {
	myFirst = myLast = nullptr;
	mySize = 0;
	Node *oPtr = original.myFirst;
	while (oPtr != nullptr) {
		append(oPtr -> myItem);
		oPtr = oPtr -> myNext;
	}
}

List::List(const List& original) {
	makeCopyOf(original);
}

List::~List() {
	delete myFirst;
	myFirst = myLast = nullptr;
	mySize = 0;
}

const unsigned List::getSize() const {
	return mySize;
}

const Item& List::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("Ya can't get the first element of an empty list, ya dingus!");
	}

	return myFirst -> myItem;
}

const Item& List::getLast() const {
	if (mySize == 0) {
		throw underflow_error("Ya can't get the last element of an empty list, ya dingus!");
	}

	return myLast -> myItem;
}

void List::append(const Item& newItem) {
	Node* newNode = new Node(newItem, nullptr);

	if (mySize == 0) {
		myFirst = myLast = newNode;
	} else {
		myLast -> myNext = newNode;
		myLast = newNode;
	}
	mySize++;
}

List& List::operator=(const List& original) {
	if (&original != this) {
		delete myFirst;
		makeCopyOf(original);
	}
	return *this;
}

List::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

List::Node::Node(Item newItem, Node* newNext) {
	myItem = newItem;
	myNext = newNext;
}

List::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item " << myItem << endl;
	delete myNext;
}
