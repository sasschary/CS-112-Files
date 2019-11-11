/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Zachary Clark
 * Date: 11-11-19
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

/* Explicity constructor
 * @param: capacity, the capacity of the array we will create
 * Postcondition: We have constructed an empty ArrayQueue with the specified capacity
 */
ArrayQueue::ArrayQueue(const unsigned capacity) {
	if (capacity <= 0) throw QueueException("ArrayQueue(0)", "ArrayQueue capacity must be positive!");
	mySize = 0;
	myCapacity = capacity;
	myFirstIndex = 0;
	myLastIndex = capacity - 1;
	myArrayPtr = new Item[capacity];
}
/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

/* First Item retriever
 * Returns the first Item in the queue, or throws an EmptyQueueException
 */
Item ArrayQueue::getFirst() const {
	if (isEmpty()) throw EmptyQueueException("ArrayQueue::getFirst()");
	return myArrayPtr[myFirstIndex];
}

/* Last Item retriever
 * Returns the final Item in the queue, or throws an EmptyQueueException
 */
Item ArrayQueue::getLast() const {
	if (isEmpty()) throw EmptyQueueException("ArrayQueue::getLast()");
	return myArrayPtr[myLastIndex];
}

/* Append operator
 * @param: it, the Item we will append to the Queue
 * Postcondition: The Queue has had it appended, or else has thrown a FullQueue exception.
 */
void ArrayQueue::append(const Item& it) {
	if (isFull()) throw FullQueueException("ArrayQueue::append(Item)");
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

/* Remove operator
 * Returns the removed Item, or else throws an EmptyQueueException.
 * Postcondition: The first Item in the ArrayQueue has been removed
 */
Item ArrayQueue::remove() {
	if (isEmpty()) throw EmptyQueueException("ArrayQueue::remove()");
	Item ret = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	mySize--;
	return ret;
}

