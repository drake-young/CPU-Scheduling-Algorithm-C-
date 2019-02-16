#ifndef SJFQUEUE_
#define SJFQUEUE_

#include "Queue.h"
#include<iostream>
#include<string>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// SJF Queue child class. This is a container object
class SJFQueue : public Queue {
private:
public:
	// Default Constructor
	SJFQueue();

	// Copy Constructor
	SJFQueue(const SJFQueue& copy);

	// Destructor
	~SJFQueue();

	// Members
	bool enqueue();
	bool enqueue(dataType dataValue);
};

#endif /* SJFQUEUE_ */
