/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Zachary Clark
 * Date: 11-11-19
 */

#include "LinkedQueue.h"

/* Default constructor
 * Constructs an empty LinkedQueue with no nodes.
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = nullptr;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = NULL;
	} else {
		myFirstPtr = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != NULL) {
			temp1->myNextPtr = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}



/* First Item retriever
 * Returns the first Item in the LinkedQueue, or throws an EmptyQueueException.
 */
Item LinkedQueue::getFirst() const {
	if (isEmpty()) throw EmptyQueueException("LinkedQueue::getFirst()");
	return myFirstPtr -> myItem;
}

/* Last Item retriever
 * Returns the final Item in the LinkedQueue, or throws an EmptyQueueException.
 */
Item LinkedQueue::getLast() const {
	if (isEmpty()) throw EmptyQueueException("LinkedQueue::getLast()");
	return myLastPtr -> myItem;
}

/* Append operator
 * @param: it, the Item we will add to the LinkedQueue
 * Postcondition: it has been appended to the end of the LinkedQueue
 */
void LinkedQueue::append(const Item& it) {
	try {
		Node* tempPtr = new Node(it, nullptr);
		if (isEmpty()) {
			myFirstPtr = myLastPtr = tempPtr;
		} else {
			myLastPtr -> myNextPtr = tempPtr;
			myLastPtr = tempPtr;
		}
		mySize++;
	} catch (bad_alloc& ba) {
		throw FullQueueException("LinkedQueue::append()");
	}

}

/* Removal operator
 * Returns the Item that we remove, or throws an EmptyQueueException
 * Postcondition: Our LinkedQueue has had its first Item removed.
 */
Item LinkedQueue::remove() {
	if (isEmpty()) throw EmptyQueueException("LinkedQueue::remove()");
	Node* tempPtr = myFirstPtr;
	Item ret = myFirstPtr -> myItem;
	myFirstPtr = myFirstPtr -> myNextPtr;
	tempPtr -> myNextPtr = nullptr;
	delete tempPtr;
	if (--mySize == 0) myLastPtr = myFirstPtr;
	return ret;
}
