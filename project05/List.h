/*
 * List.h declares the methods for the List class
 * Written by Zachary Clark and Nathan Bouman for CS 112
 */

#ifndef LIST_H_
#define LIST_H_
#include <string>
using namespace std;

template <class Item>

class List {
public:
	List();
	List(const List& original);
	~List();
	const unsigned getSize() const;
	const Item& getFirst() const;
	const Item& getLast() const;
	void append(const Item& newItem);
	List& operator=(const List& original);
	const bool operator!=(const List& list2) const;
	const int getIndexOf(const Item& item) const;
	Item remove(int index);
	void readFrom(const string& fileName);
	void writeTo(ostream& out, string sep = " ");
	bool operator==(const List<Item>& original);
	void readFrom(istream& in);
	void writeTo(string file, const char divider);
	void prepend(const Item& item);
	void insert(const Item& it, unsigned index);

private:
	struct Node {
		Item myItem;
		Node* myNext;
		Node();
		Node(Item newItem, Node* newNext);
		~Node();
	};

	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	void makeCopyOf(const List &original);

	friend class ListTester;


};

/*
 * List.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: Sasschary
 */

#include "List.h"
#include <iostream>
#include <fstream>
#include <cassert>

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = nullptr;

}

template <class Item>
void List<Item>::makeCopyOf(const List &original) {
	myFirst = myLast = nullptr;
	mySize = 0;
	Node *oPtr = original.myFirst;
	while (oPtr != nullptr) {
		append(oPtr -> myItem);
		oPtr = oPtr -> myNext;
	}
}

template <class Item>
List<Item>::List(const List& original) {
	makeCopyOf(original);
}

template <class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = nullptr;
	mySize = 0;
}

template <class Item>
const unsigned List<Item>::getSize() const {
	return mySize;
}

template <class Item>
const Item& List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("Ya can't get the first element of an empty list, ya dingus!");
	}

	return myFirst -> myItem;
}

template <class Item>
const Item& List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("Ya can't get the last element of an empty list, ya dingus!");
	}

	return myLast -> myItem;
}

template <class Item>
void List<Item>::append(const Item& newItem) {
	Node* newNode = new Node(newItem, nullptr);

	if (mySize == 0) {
		myFirst = myLast = newNode;
	} else {
		myLast -> myNext = newNode;
		myLast = newNode;
	}
	mySize++;
}

template <class Item>
List<Item>& List<Item>::operator=(const List& original) {
	if (&original != this) {
		delete myFirst;
		makeCopyOf(original);
	}
	return *this;
}

/* Inequality operator
 * @param: list2, the list we will compare to this one to check for inequality
 * Returns: True if the lists are unequal, false if they are equal.
 *
 * Written by Zachary Clark
 */
template <class Item>
const bool List<Item>::operator!=(const List& list2) const {
	if (mySize != list2.mySize) return true;

	Node* myNodePtr = myFirst;
	Node* otherNodePtr = list2.myFirst;

	while (myNodePtr) {
		if (myNodePtr -> myItem != otherNodePtr -> myItem) return true;
		myNodePtr = myNodePtr -> myNext;
		otherNodePtr = otherNodePtr -> myNext;
	}

	return false;
}

/* Index retrieval
 * @param: item, the item that we want to find in the list.
 * Returns: The index of the first occurrence of the item
 *
 * Written by Zachary Clark
 */
template <class Item>
const int List<Item>::getIndexOf(const Item& item) const {
	if (mySize == 0) return -1;

	Node* nodePtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		if (nodePtr -> myItem == item) return i;
		nodePtr = nodePtr -> myNext;
	}

	return -1;
}

/* Removal operator
 * @param: index, the index of the item which will be removed
 * Returns: The Item from the Node which was removed
 *
 * Written by Zachary Clark
 */
template <class Item>
Item List<Item>::remove(int index) {
	if (mySize == 0) {
		throw range_error("Ya dummy, ya tried to remove an item from an empty list!");
	}

	if (index < 0) index = 0;
	if (index > (int)mySize - 1) index = mySize - 1;

	Item ret;
	Node* prevPtr = myFirst;
	Node* nodePtr = myFirst;

	if (index == 0) {
		ret = myFirst -> myItem;
		Node* secondNode = myFirst -> myNext;
		myFirst -> myNext = nullptr;
		delete myFirst;
		myFirst = secondNode;
		mySize--;
		// If the list is now empty...
		if (mySize + 1 == 1) {
			myLast = nullptr;
			return ret;
		}
		return ret;
	} else {
		for (int i = 0; i < index; i++) {
			prevPtr = nodePtr;
			nodePtr = nodePtr -> myNext;
		}
		ret = nodePtr -> myItem;
		prevPtr -> myNext = nodePtr -> myNext;
		nodePtr -> myNext = nullptr;
		delete nodePtr;
		mySize--;
	}

	return ret;
}

/* Filestream input, reads from fileName and inputs data to the list
 * @param fileName, the file which we will read data from
 * Postcondition: Our List's data is exactly that of the file
 *
 * Written by Zachary Clark
 */
template <class Item>
void List<Item>::readFrom(const string& fileName) {
	for (unsigned i = 0; i < mySize; i++) {
		remove(i);
	}

	ifstream fin(fileName);
	assert( fin.is_open() );

	Item input;
	fin >> input;
	while (!fin.eof()) {
		append(input);
		fin >> input;
	}
}

/* Stream output. Writes list's data to the ostream using separator sep
 * @param: out, an ostream we will write our data to
 * @param: sep, the separator we will use to separate each Item
 * Postcondition: out has the data from our List in it.
 *
 * Written by Zachary Clark
 */
template <class Item>
void List<Item>::writeTo(ostream& out, string sep) {
	Node* nodePtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		out << nodePtr -> myItem << sep;
		nodePtr = nodePtr -> myNext;
	}
}

template <class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

template <class Item>
List<Item>::Node::Node(Item newItem, Node* newNext) {
	myItem = newItem;
	myNext = newNext;
}

template <class Item>
List<Item>::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item " << myItem << endl;
	delete myNext;
}

//Equality Operation
// Written by Nathan Bouman
template <class Item>
bool List<Item>::operator==(const List<Item>& original){
	if (original.mySize != mySize){
		return false;
	}
	if (original.myFirst -> myItem == myFirst -> myItem){
	}
	if (original.myLast -> myItem == myLast -> myItem){
		return true;
	}
	return false;
}
//readFrom istream operation
// Written by Nathan Bouman
template <class Item>
void List<Item>::readFrom(istream& in){
	this -> ~List();
	mySize= 0;
	myFirst = myLast = nullptr;
	Item a;
	for (int i = 0; i < 3; i++){
		in >> a;
		this -> append(a);
	}
}
//writeTo string operation
// Written by Nathan Bouman
template <class Item>
void List<Item>::writeTo(string file, const char divider){
	ofstream fout(file.c_str());
	assert(fout.is_open());
	Node*temp = myFirst;
	while(temp != nullptr){
		fout <<temp -> myItem <<divider<< flush;
		temp = temp -> myNext;
	}
	fout.close();
}
//Prepend operation
// Written by Nathan Bouman
template <class Item>
void List<Item>::prepend(const Item& item){
	Node* nodePtr = new
			Node (item,nullptr);

	//if empty
	if (mySize == 0){
		myFirst = nodePtr;
	}
	//otherwise swap the nodes
	else {
		nodePtr -> myNext = myFirst;
		myFirst = nodePtr;
	}
	mySize++;
}
//Insert operation
// Written by Nathan Bouman
template <class Item>
void List<Item>::insert(const Item& it, unsigned index){
	if(index <= mySize && index > 0){
		Node* temp = myFirst;
		Node* newNode = new Node(it, nullptr);

		//what we want to change
		for (unsigned i = 0; i < index -1; i++){
			temp = temp -> myNext;
		}
		//move new node to the next one
		newNode -> myNext = temp -> myNext;
		temp -> myNext = newNode;
		++mySize;
	}
	else if (index <= 0){
		this -> prepend(it);
	}
	else if (index > mySize){
		this -> append(it);
	}
}


#endif /* LIST_H_ */
