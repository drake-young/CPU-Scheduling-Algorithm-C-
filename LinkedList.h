#ifndef LINKEDLIST_
#define LINKEDLIST_

#include<iostream>
#include<string>
#include<fstream>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// Linked List class. This is a container object
class LinkedList {
private:
public:
	// Putting here for debugging purposes so I don't need to write a getter fxn
	Node * headPtr;

	// Default Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy Constructor
	LinkedList(const LinkedList& copy);

	// Members
	Node* front();

	bool insertAtFront();
	bool insertAtFront(dataType dataValue);

	bool insertBeforePosition(int index);
	bool insertBeforePosition(int index, dataType dataValue);

	bool insertAtBack();
	bool insertAtBack(dataType dataValue);

	bool deleteAtFront();

	bool deleteBeforePosition(int index);

	bool deleteAtPosition(int index);

	bool deleteAtBack();

	bool contains(dataType dataValue);

	void remove(dataType dataValue);

	void populate(string filename);

	void sortByPid();
	void sortByArrival();
	int length();

	// Overloaded Operators
	LinkedList operator+(const LinkedList &right);
	LinkedList operator-(const LinkedList right);
	LinkedList& operator=(const LinkedList &right);
	friend ostream &operator<< (ostream &out, const LinkedList list);
};

#endif //LINKEDLIST_
