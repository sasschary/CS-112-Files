/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Zachary Clark
 * Date: 11-19
 */
 
#include "BST.h"

/* Default constructor
 * Constructs an empty BST.
 */
BST::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

/* Insert an Item into our BST.
 * @param: it, the Item we will insert
 * Postcondition: it has been inserted into the BST.
 */
void BST::insert(const Item& it) {
	if (isEmpty()) {
		myRoot = new Node(it);
	} else {
		myRoot -> insert(it);
	}
	myNumItems++;
}

/* Node insert.
 * @param: it, the Item we will insert
 * Postcondition: If this node should point to the new Item, create a new node with the Item an point to it.
 * 				  Else, pass it on to the next Node to decide what to do with it.
 */
void BST::Node::insert(const Item& it) {
	if (it < myItem) {
		if (myLeft == nullptr) { myLeft = new Node(it); }
		else { myLeft -> insert(it); }
	}
	else if (it > myItem) {
		if (myRight == nullptr) { myRight = new Node(it); }
		else { myRight -> insert(it); }
	}
	else { throw Exception("BST::Node::insert()", "Item it is already in the set!"); }
}

/* BST containment function.
 * @param: it, the Item we will search for in our BST.
 * Returns true if it is contained in the BST, otherwise false.
 */
bool BST::contains(const Item& it) const {
	if (isEmpty()) return false;
	else return myRoot -> contains(it);
}

/* Node containment function.
 * @param: it, the Item we are searching for in our BST.
 * Returns true if our Node contains it, or relies on myLeft and myRight nodes to return the proper value.
 * Otherwise returns false.
 */
bool BST::Node::contains(const Item& it) const {
	if (it == myItem) return true;
	if (it < myItem && myLeft != nullptr) return myLeft -> contains(it);
	if (it > myItem && myRight != nullptr) return myRight -> contains(it);
	return false;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

/* BST Post order traversing
 * Traverses the BST with a post ordering.
 */
void BST::traversePostorder() {
	if (!isEmpty()) myRoot -> traversePostorder();
}

/* Node Post order traversing
 * Traverses the BST's Nodes with a post ordering.
 */
void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/* BST inorder traversing
 * Traverses the BST with an in ordering.
 */
void BST::traverseInorder() {
	if (!isEmpty()) myRoot -> traverseInorder();
}

/* Node In order traversing
 * Traverses the BST's Nodes with an in ordering.
 */
void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}
