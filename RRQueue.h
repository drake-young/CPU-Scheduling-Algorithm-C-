#ifndef RRQUEUE_
#define RRQUEUE_

#include "Queue.h"
#include<iostream>
#include<string>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// RR Queue child class. This is a container object
class RRQueue : public Queue {
private:
public:
	// Default Constructor
	RRQueue();

	// Copy Constructor
	RRQueue(const RRQueue& copy);

	// Destructor
	~RRQueue();

	// Members
	bool enqueue();
	bool enqueue(dataType dataValue);
	bool cycle();
};

#endif //RRQUEUE_
