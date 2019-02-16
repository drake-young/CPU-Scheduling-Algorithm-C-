#ifndef SRTFQUEUE_
#define SRTFQUEUE_

#include "Queue.h"
#include<iostream>
#include<string>
#include "Node.h"
#include "MyPCB.h"
using namespace std;

typedef MyPCB dataType;

// SJF Queue child class. This is a container object
class SRTFQueue : public Queue {
private:
public:
	// Default Constructor
	SRTFQueue();

	// Copy Constructor
	SRTFQueue(const SRTFQueue& copy);

	// Destructor
	~SRTFQueue();

	// Members
	bool enqueue();
	bool enqueue(dataType dataValue);
};

#endif /* SRTFQUEUE_ */
