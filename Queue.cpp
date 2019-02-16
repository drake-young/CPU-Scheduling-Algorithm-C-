//===========================================================================
//
// Drake Young
// Queue member functions
// Last Modified: 10/14/2018
//
//===========================================================================

#include"Queue.h"

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
Queue::Queue() {
	headPtr = nullptr;
}

//*********************************************************
//				Copy Constructor
//
//	Data in:	Another Queue object
//	Data out:	none
//	Task:		creates a new linked list and copies the
//				data from the parameter (not the poitners)
//*********************************************************
Queue::Queue(const Queue& copy) {
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
Queue::~Queue() {
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
//				front()
//
//	Data in:	none
//	Data out:	pointer to the first node in the list
//	Task:		return the node referenced by the private
//				attribute headPtr
//
//*********************************************************
Node* Queue::front() {
	return headPtr;
}

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
bool Queue::enqueue() {
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
bool Queue::enqueue(dataType dataValue) {
	MyPCB toInsert(dataValue.getPid(), dataValue.getArrivalTime(), dataValue.getCPUBurstTime(), dataValue.getPriority());
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setNext(nullptr);
		headPtr->setValue(toInsert);
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
		insertPtr->setValue(toInsert);

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
//				dequeueFront
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		Deletes the first node in the queue by 
//				pointing a temp pointer to that node
//				changing headPtr to point to the next
//				then deleting the temp pointer that points
//				to node that is being removed
//
//*********************************************************
bool Queue::dequeueFront() {
	// Condition for empty list
	if (headPtr == nullptr) {
		return false;
	}
	// Temp pointer
	Node *tempPtr = headPtr;

	// Change head pointer to second list node	
	headPtr = headPtr->getNext();

	// Deallocate The memory used in the initial list position
	delete tempPtr;

	// Preventing future dangling pointers
	tempPtr = nullptr;

	return true;
}

//*********************************************************
//				contains (value)
//
//	Data in:	value. that the list is being checked
//				for
//	Data out:	boolean. Returns true if it contains the 
//				value and false if it doesnt
//	Task:		step through the linked list to determine
//				whether a specific data value exists in
//				the list.
//
//*********************************************************
bool Queue::contains(dataType dataValue) {
	Node *currentPtr = headPtr;
	while (currentPtr != nullptr) {
		// Returns true if the value is found
		if (currentPtr->getValue() == dataValue) {
			return true;
		}
		currentPtr = currentPtr->getNext();
	}

	currentPtr = nullptr;
	// if it makes it through the list without finding the value
	// it returns false.
	return false;
}

//===========================================================================
//=====================	Overloaded Operators ================================
//===========================================================================

//*********************************************************
//						+ (plus) operator
//
//	Task:	perform the union of two Linked Lists. This 
//			operator returns returnList, which contains
//			all unique data from the two lists
//
//*********************************************************
Queue Queue::operator+(const Queue &right) {
	Queue returnList;
	Node *currentPtr = headPtr;

	// Add Unique Left Side Nodes to the returnList
	while (currentPtr != nullptr) {

		// if the list of values that is returned from this 
		// function does not contain the data held in the current node,
		// add that data to the returnList
		if (!returnList.contains(currentPtr->getValue())) {
			returnList.enqueue(currentPtr->getValue());
		}
		currentPtr = currentPtr->getNext();
	}

	// start currentPtr at start of right now
	currentPtr = right.headPtr;

	// Add Unique Right Side Nodes to the returnList
	// same algorithm performed starting at right.headPtr
	// Add Unique Left Side Nodes to the returnList
	while (currentPtr != nullptr) {

		// if the list of values that is returned from this 
		// function does not contain the data held in the current node,
		// add that data to the returnList
		if (!returnList.contains(currentPtr->getValue())) {
			returnList.enqueue(currentPtr->getValue());
		}
		currentPtr = currentPtr->getNext();
	}

	currentPtr = nullptr;
	return returnList;
}

//*********************************************************
//						<< operator
//
//	Task:	overloads the output operator to display
//			the contents of a Linked List with spaces
//			in between.
//
//*********************************************************
ostream & operator<<(ostream & out, const Queue list) {
	Node *currentPtr = list.headPtr;
	while (currentPtr != nullptr) {
		out << currentPtr->getValue().getPid() << " " << currentPtr->getValue().getArrivalTime() << " " << currentPtr->getValue().getCPUBurstTime() << " " << currentPtr->getValue().getPriority() << endl;
		currentPtr = currentPtr->getNext();
	}
	currentPtr = nullptr;
	return out;
}
