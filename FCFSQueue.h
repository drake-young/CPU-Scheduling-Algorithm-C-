#ifndef FCFSQUEUE_
#define FCFSQUEUE_

#include "Queue.h"
#include<iostream>
#include<string>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// FCFS Queue child class. This is a container object
class FCFSQueue : public Queue {
private:
public:
	// Default Constructor
	FCFSQueue();

	// Copy Constructor
	FCFSQueue(const FCFSQueue& copy);

	// Destructor
	~FCFSQueue();

	// Members
	bool enqueue();
	bool enqueue(dataType dataValue);
};

#endif //FCFSQUEUE_
