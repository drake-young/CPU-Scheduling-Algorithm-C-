#ifndef QUEUE_
#define QUEUE_

#include<iostream>
#include<string>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// Queue base class. This is a container object
class Queue {
private:
public:
	// Putting here for debugging purposes
	Node * headPtr;

	// Default Constructor
	Queue();

	// Copy Constructor
	Queue(const Queue& copy);

	// Destructor
	~Queue();

	// Members
	Node* front();

	virtual bool enqueue(); // Enqueue CAN be overridden, but has functionality if it isn't
	virtual bool enqueue(dataType dataValue); // Enqueue CAN be overridden, but has functionality if it isn't

	bool dequeueFront();

	bool contains(dataType dataValue);

	// Overloaded Operators
	Queue operator+(const Queue &right);
	friend ostream &operator<< (ostream &out, const Queue list);
};

#endif /* QUEUE_ */
