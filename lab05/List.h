/*
 * List.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Sasschary
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;

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

#endif /* LIST_H_ */
