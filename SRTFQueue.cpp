//===========================================================================
//
// Drake Young
// SRTFQueue member functions
// Last Modified: 10/14/2018
//
//===========================================================================

#include "SRTFQueue.h"

//===========================================================================

//===========================================================================
//=========================	Constructor / Destructor ========================
//===========================================================================

//*********************************************************
//				Default Constructor
//
//	Data in:	none
//	Data out:	none
//	Task:		Assigns headPtr to a nullptr since the 
//				queue is enpty upon construction
//*********************************************************
SRTFQueue::SRTFQueue() {
	headPtr = nullptr;
}

//*********************************************************
//				Copy Constructor
//
//	Data in:	Another SRTFQueue object
//	Data out:	none
//	Task:		creates a new linked list and copies the
//				data from the parameter (not the poitners)
//*********************************************************
SRTFQueue::SRTFQueue(const SRTFQueue& copy) {
	Node *currentPtr = copy.headPtr;	// Traverse List that's copied from
	headPtr = nullptr;
	while (currentPtr != nullptr) {
		// Adds the data to the new pointer, but creates its own pointers
		enqueue(currentPtr->getValue());

		// step to next node in copy
		currentPtr = currentPtr->getNext();
	}
	currentPtr = nullptr;
}

//*********************************************************
//				Destructor
//
//	Data in:	none
//	Data out:	none
//	Task:		ensure that all dynamic memory has been
//				freed appropriatley
//*********************************************************
SRTFQueue::~SRTFQueue() {
	Node *currentPtr = headPtr;
	Node *deletePtr = nullptr;
	while (currentPtr != nullptr && currentPtr->getNext() != nullptr && headPtr->getNext() != nullptr) {
		if (currentPtr->getNext()->getNext() == nullptr) {
			deletePtr = currentPtr->getNext();
			currentPtr->setNext(nullptr);
			delete deletePtr;
			currentPtr = headPtr;
		}
		currentPtr = currentPtr->getNext();
	}
	delete headPtr;
	headPtr = nullptr;
	currentPtr = nullptr;
}

//===========================================================================
//=========================	Member Functions ================================
//===========================================================================

//*********************************************************
//				enqueue()
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the back of the
//				queue that points to a nullptr and is
//				linked to by the previous "end" of the list
//				If the list is empty, headPtr becomes a new
//				node
//
//*********************************************************
bool SRTFQueue::enqueue() {
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setNext(nullptr);
		return true;
	}
	else if (headPtr != nullptr) {
		// Step through to the end of the list
		Node *currentPtr = headPtr;
		while (currentPtr->getNext() != nullptr) {
			currentPtr = currentPtr->getNext();
		}
		// Create node to be inserted
		Node *insertPtr = new Node();
		// Since it's the end, the nextPtr should be nullptr
		insertPtr->setNext(nullptr);

		// currentPtr is no longer end, it points to the new end of the list
		currentPtr->setNext(insertPtr);

		// Prevent dangling pointers
		currentPtr = nullptr;

		return true;
	}
	return false;
}

//*********************************************************
//				enqueue(value)
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the back of the
//				linked list that points to a nullptr and is
//				linked to by the previous "end" of the list
//				If the list is empty, headPtr becomes a new
//				node
//
//*********************************************************
bool SRTFQueue::enqueue(dataType dataValue) {
	MyPCB toInsert(dataValue.getPid(), dataValue.getArrivalTime(), dataValue.getCPUBurstTime(), dataValue.getPriority());
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setNext(nullptr);
		headPtr->setValue(toInsert);
		return true;
	}
	else if (headPtr != nullptr) {
		// if new value should be in front of head
		if (dataValue.getRemainingTime() < headPtr->getValue().getRemainingTime())
		{
			Node* insertNode = new Node();
			insertNode->setValue(dataValue);
			insertNode->setNext(headPtr);
			headPtr = insertNode;
			return true;
		}

		// if same, ensure fcfs
		if (dataValue.getRemainingTime() == headPtr->getValue().getRemainingTime())
		{
			if (dataValue.getArrivalTime() < headPtr->getValue().getArrivalTime())
			{
				Node* insertNode = new Node();
				insertNode->setValue(dataValue);
				insertNode->setNext(headPtr);
				headPtr = insertNode;
				return true;
			}
			else
			{
				Node* insertNode = new Node();
				insertNode->setValue(dataValue);
				insertNode->setNext(headPtr->getNext());
				headPtr->setNext(insertNode);
				return true;
			}
		}

		// otherwise Step through to the end of the list or appropriate insert point
		Node *currentPtr = headPtr;
		while (currentPtr->getNext() != nullptr) {
			if (dataValue.getRemainingTime() < currentPtr->getNext()->getValue().getRemainingTime())
			{
				break;
			}
			else if (dataValue.getRemainingTime() == currentPtr->getNext()->getValue().getRemainingTime())
			{
				if (dataValue.getArrivalTime() < currentPtr->getNext()->getValue().getArrivalTime())
				{
					break;
				}
			}
			currentPtr = currentPtr->getNext();
		}
		// Create node to be inserted
		Node *insertPtr = new Node();
		insertPtr->setValue(toInsert);

		// Either nullptr or the next item in the queue with a greater burst time other than head
		insertPtr->setNext(currentPtr->getNext());

		// currentPtr is no longer end, it points to the new end of the list
		currentPtr->setNext(insertPtr);

		// Prevent dangling pointers
		currentPtr = nullptr;

		return true;
	}
	return false;
}
