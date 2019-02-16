//===========================================================================
//
// Drake Young
// Linked List members
// Last Modified: 10/14/2018
//
//===========================================================================

#include"LinkedList.h"

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
//				Linked List is enpty upon construction
//*********************************************************
LinkedList::LinkedList() {
	headPtr = nullptr;
}

//*********************************************************
//				Destructor
//
//	Data in:	none
//	Data out:	none
//	Task:		ensure that all dynamic memory has been
//				freed appropriatley
//*********************************************************
LinkedList::~LinkedList() {
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

//*********************************************************
//				Copy Constructor
//
//	Data in:	Another Linked List object
//	Data out:	none
//	Task:		creates a new linked list and copies the
//				data from the parameter (not the poitners)
//*********************************************************
LinkedList::LinkedList(const LinkedList& copy) {
	Node *currentPtr = copy.headPtr;	// Traverse List that's copied from
	headPtr = nullptr;
	while (currentPtr != nullptr) {
		// Adds the data to the new pointer, but creates its own pointers
		insertAtBack(currentPtr->getValue());

		// step to next node in copy
		currentPtr = currentPtr->getNext();
	}
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
Node* LinkedList::front() {
	return headPtr;
}

//*********************************************************
//				insertAtFront
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the front of the
//				linked list that points to the next node
//				if there are other nodes in the list. If 
//				the list is empty, it reassigns headPtr
//				to the empty node that is made
//
//*********************************************************
bool LinkedList::insertAtFront() {
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setNext(nullptr);
		return true;
	}
	else if (headPtr != nullptr) {
		Node *insertPtr = new Node();		// Create the node to insert in the linked list
		insertPtr->setNext(headPtr);		// The insertPtr now points to the "old" first item
		headPtr = insertPtr;				// headPtr now points to insertPtr, which points to the "old" first item
		return true;
	}
	return false;
}

//*********************************************************
//				insertAtFront(value)
//
//	Data in:	data value to initiate the node with
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the front of the
//				linked list that points to the next node
//				if there are other nodes in the list. If 
//				the list is empty, it reassigns headPtr
//				to the empty node that is made
//	Node:		Do Not Use on Empty List
//
//*********************************************************
bool LinkedList::insertAtFront(dataType dataValue) {
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setValue(dataValue);
		headPtr->setNext(nullptr);
		return true;
	}
	else if (headPtr != nullptr) {
		Node *insertPtr = new Node();		// Create the node to insert in the linked list
		insertPtr->setNext(headPtr);	// The insertPtr now points to the "old" first item
		insertPtr->setValue(dataValue);	// Gives it the data
		headPtr = insertPtr;			// headPtr now points to insertPtr, which points to the "old" first item
		return true;
	}
	return false;
}

//*********************************************************
//				insertBeforePosition
//
//	Data in:	integer index of the list node the new
//				node is inserted before
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the list, linked
//				directly before the position index passed
//	Note:		Do Not Use on Empty List
//
//*********************************************************
bool LinkedList::insertBeforePosition(int index) {
	Node *currentPtr = headPtr;			// Current node being looked at
	Node *insertPtr = new Node();		// the node to be inserted

	// Step through to the position before the index
	for (index; index > 0; index--) {
		if (currentPtr->getNext() == nullptr) {
			// If the index doesn't exist
			return false;
		}
		else {
			currentPtr = currentPtr->getNext();
		}
	}
	// currentPtr and insertPtr both have the node at the index as their nextPtr
	insertPtr->setNext(currentPtr->getNext());
	// currentPtr --> insertPtr --> nextPtr[index input]
	currentPtr->setNext(insertPtr);
	currentPtr = nullptr;
	return true;
}

//*********************************************************
//				insertBeforePosition (value)
//
//	Data in:	integer index of the list node the new
//				node is inserted before, and the data
//				value for the new node
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		insert a new empty node to the list, linked
//				directly before the position index passed
//
//*********************************************************
bool LinkedList::insertBeforePosition(int index, dataType dataValue) {
	Node *currentPtr = headPtr;			// Current node being looked at
	Node *insertPtr = new Node();		// the node to be inserted
	insertPtr->setValue(dataValue);		// Gives the new node the data value

	// Step through to the position before the index
	for (index; index > 0; index--) {
		if (currentPtr->getNext() == nullptr) {
			// If the index doesn't exist
			return false;
		}
		else {
			currentPtr = currentPtr->getNext();
		}
	}
	// currentPtr and insertPtr both have the node at the index as their nextPtr
	insertPtr->setNext(currentPtr->getNext());
	// currentPtr --> insertPtr --> nextPtr[index input]
	currentPtr->setNext(insertPtr);

	currentPtr = nullptr;
	return true;
}

//*********************************************************
//				insertAtBack
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
bool LinkedList::insertAtBack() {
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
//				insertAtBack(value)
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
bool LinkedList::insertAtBack(dataType dataValue) {
	if (headPtr == nullptr) {
		headPtr = new Node();
		headPtr->setNext(nullptr);
		headPtr->setValue(dataValue);
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
		insertPtr->setValue(dataValue);

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
//				deleteAtFront
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		Deletes the first node in the list by 
//				pointing a temp pointer to that node
//				changing headPtr to point to the next
//				then deleting the temp pointer that points
//				to node that is being removed
//
//*********************************************************
bool LinkedList::deleteAtFront() {
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
//				deleteAtPosition
//
//	Data in:	integer value to indicate the index of the
//				node to be deleted
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		Deletes the the node at the position
//				(index)	if the index is greater than the
//				list size or if the list is empty, the 
//				function fails
//
//*********************************************************
bool LinkedList::deleteAtPosition(int index) {
	// Condition for index 0 being passed
	if (index == 0) {
		if (deleteAtFront())
			return true;
		else
			return false;
	}
	Node *currentPtr = headPtr;		// Current node being looked at
									// Step through to the position before the index
	for (int i = 0; i < index - 1; i++) {
		// If this list is empty or index is greater than list size
		if (currentPtr == nullptr) {
			return false;
		}
		else {
			currentPtr = currentPtr->getNext();
		}
	}


	// If the index is the end of the list, call the deleteAtBack function
	if (currentPtr->getNext() == nullptr) {
		if (deleteAtBack()) {
			return true;
		}
		else
			return false;
	}

	// tempPtr points to the one to be removed
	Node *tempPtr = currentPtr->getNext();

	// makes this link skip the one to be deleted
	currentPtr->setNext(currentPtr->getNext()->getNext());

	// Deallocate that node
	delete tempPtr;

	// Preventing dangling pointers later
	tempPtr = nullptr;
	currentPtr = nullptr;

	return true;
}
//*********************************************************
//				deleteBeforePosition
//
//	Data in:	integer value to indicate the index of the
//				node to be deleted. index must be >0
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		Deletes the the node at the position
//				(index) before the value passed if the 
//				index is greater than the list size or if
//				the list is empty, the function fails
//
//*********************************************************
bool LinkedList::deleteBeforePosition(int index) {
	if (index == 0) {
		return false;
	}

	index--;	// by decrementing the index, we can now implement the same algorithm
				// that deleteAtPosition uses
				// Condition for index 0 being passed
	if (index == 1) {
		if (deleteAtFront())
			return true;
		else
			return false;
	}
	Node *currentPtr = headPtr;		// Current node being looked at
									// Step through to the position before the index
	for (int i = 0; i < index - 1; i++) {
		// If this list is empty or index is greater than list size
		if (currentPtr == nullptr) {
			return false;
		}
		else {
			currentPtr = currentPtr->getNext();
		}
	}


	// If the index is the end of the list, call the deleteAtBack function
	if (currentPtr->getNext() == nullptr) {
		if (deleteAtBack()) {
			return true;
		}
		else
			return false;
	}

	// tempPtr points to the one to be removed
	Node *tempPtr = currentPtr->getNext();

	// makes this link skip the one to be deleted
	currentPtr->setNext(currentPtr->getNext()->getNext());

	// Deallocate that node
	delete tempPtr;

	// Preventing dangling pointers later
	tempPtr = nullptr;
	currentPtr = nullptr;

	return true;
}

//*********************************************************
//				deleteAtBack
//
//	Data in:	none
//	Data out:	boolean. Returns true if successful
//				or false if it fails
//	Task:		Deletes the last node in the list and
//				repoints the last Node's nextPtr to 
//				nullptr.
//
//*********************************************************
bool LinkedList::deleteAtBack() {
	// Condition for empty list
	if (headPtr == nullptr) {
		return false;
	}

	// condition for list with only one node
	if (headPtr->getNext() == nullptr) {
		delete headPtr;
		headPtr = nullptr;
		return true;
	}

	// Step through to the second-to-last of the list
	// Used for when the list has at least two nodes
	Node *currentPtr = headPtr;
	while (currentPtr->getNext()->getNext() != nullptr) {
		currentPtr = currentPtr->getNext();
	}

	// Deallocate the last node
	delete currentPtr->getNext();

	// set last node's pointer to null pointer
	currentPtr->setNext(nullptr);

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
bool LinkedList::contains(dataType dataValue) {
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

//*********************************************************
//				remove (value)
//
//	Data in:	value of the data that is to be removed
//	Data out:	none
//	Task:		find the index that contains the value,
//				then call .deleteAtPosition for that index
//
//*********************************************************
void LinkedList::remove(dataType dataValue) {
	Node *currentPtr = headPtr;
	int index = 0;	// starts at 0 and steps through, incrementing with each successive node
	while (currentPtr != nullptr) {
		// calls deleteAtPosition if value is found
		if (currentPtr->getValue() == dataValue) {
			deleteAtPosition(index);
			currentPtr = nullptr;
			return;	// only one delete per function call
		}
		currentPtr = currentPtr->getNext();
		++index;
	}
	currentPtr = nullptr;
}

//*********************************************************
//				populate (filename)
//
//	Data in:	name of file to populate from
//	Data out:	void
//	Task:		read through the input file and populate
//				the LinkedList using MyPCB objects from 
//				the file
//				file is in the form of:
//					PID		Arrival_time	CPU_Burst
//	NOTE:		The given input files have an additional 
//				column for priority, but this column is not
//				used anywhere in lab 2, and the lab instructions
//				show a sample file containing only these three
//				columns.
//
//*********************************************************
void LinkedList::populate(string filename) {
	// === SETUP === //
	int pid = -1;
	int arrivalTime;
	int cpuTime;
	int priority;
	int prevPid; 
	MyPCB* toInsert;
	ifstream infile;
	infile.open(filename);

	// === FUNCTIONALITY === //
	while (!infile.eof())
	{
		// get relevant data
		prevPid = pid;
		infile >> pid;
		infile >> arrivalTime;
		infile >> cpuTime;

		if (prevPid == pid)
		{
			// same process was read twice, no need to add a duplicate
			continue;
		}

		// check if it's the end of the line and handle the priority column
		// appropriately
		if (infile.peek() == '\n') { priority = 0; }
		else { infile >> priority; }

		// use the LinkedList insertAtBack(value) function to append the node to its back
		toInsert = new MyPCB(pid, arrivalTime, cpuTime, priority);
		this->insertAtBack(*toInsert);
	}

	// === CLEANUP === //
	toInsert = nullptr;
	infile.close();
}

//*********************************************************
//				sortByArrival ()
//
//	Data in:	N/A
//	Data out:	void
//	Task:		iterate through the LinkedList and sort
//				the processes in ascending order by arrival
//				time
//
//*********************************************************
void LinkedList::sortByArrival() {
	// if list is empty, it's already sorted
	if (headPtr == nullptr) { return; }

	// bubble sort
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		int i = 0;
		Node *currentPtr = headPtr;
		while (currentPtr->getNext() != nullptr)
		{
			// if current pid > next pid in list, then swap the two
			if (currentPtr->getValue().getArrivalTime() > currentPtr->getNext()->getValue().getArrivalTime())
			{
				// swap values without swapping pointers
				Node::swapValues(currentPtr, currentPtr->getNext());
				sorted = false;
			}
			currentPtr = currentPtr->getNext();
		}
	}
}

//*********************************************************
//				sortByPid ()
//
//	Data in:	N/A
//	Data out:	void
//	Task:		iterate through the LinkedList and sort
//				the processes in ascending order by pid
//
//*********************************************************
void LinkedList::sortByPid() {
	// if list is empty, it's already sorted
	if (headPtr == nullptr) { return; }

	// bubble sort
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		int i = 0;
		Node *currentPtr = headPtr;
		while (currentPtr->getNext() != nullptr)
		{
			// if current pid > next pid in list, then swap the two
			if (currentPtr->getValue().getPid() > currentPtr->getNext()->getValue().getPid())
			{
				// swap values without swapping pointers
				Node::swapValues(currentPtr, currentPtr->getNext());
				sorted = false;
			}
			currentPtr = currentPtr->getNext();
		}
	}
}

//*********************************************************
//				length ()
//
//	Data in:	N/A
//	Data out:	int containing number of nodes in the list
//	Task:		iterate through the LinkedList and count
//				the number of nodes. return this count
//
//*********************************************************
int LinkedList::length() {
	int counter = 0;

	// if list is empty, it's already sorted
	if (headPtr == nullptr) { return 0; }

	Node* currentPtr = headPtr;
	++ counter;
	while (currentPtr->getNext() != nullptr)
	{
		currentPtr = currentPtr->getNext();
		++counter;
	}
	return counter;
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
LinkedList LinkedList::operator+(const LinkedList &right) {
	LinkedList returnList;
	Node *currentPtr = headPtr;

	// Add Unique Left Side Nodes to the returnList
	while (currentPtr != nullptr) {

		// if the list of values that is returned from this 
		// function does not contain the data held in the current node,
		// add that data to the returnList
		if (!returnList.contains(currentPtr->getValue())) {
			returnList.insertAtBack(currentPtr->getValue());
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
			returnList.insertAtBack(currentPtr->getValue());
		}
		currentPtr = currentPtr->getNext();
	}

	currentPtr = nullptr;
	return returnList;
}

//*********************************************************
//						- (minus) operator
//
//	Task:	perform the difference on the two LInked
//			lists, returning a Linked List that contains
//			all values in the left side that are also
//			not in the right side.
//
//*********************************************************
LinkedList LinkedList::operator-(const LinkedList right) {
	LinkedList returnList = *this;

	// Step through right
	Node *currentPtr = right.headPtr;

	while (currentPtr != nullptr) {
		// If the left contains the right, remove it from the left
		if (contains(currentPtr->getValue())) {
			// Step through the left list to remove the first instance of that element
			returnList.remove(currentPtr->getValue());
		}
		currentPtr = currentPtr->getNext();
	}
	currentPtr = nullptr;
	return returnList;
}

//*********************************************************
//						= (assignment) operator
//
//	Task:	Assign the value of data in one linked list to
//			the value of the data in another. Adjusts
//			size of the list appropriately.
//
//*********************************************************
LinkedList& LinkedList::operator=(const LinkedList &right) {
	Node *currentPtr = headPtr;
	// Empties the "this" list first
	while (currentPtr != nullptr) {
		deleteAtBack();
	}

	currentPtr = right.headPtr;
	dataType value;

	while (currentPtr != nullptr) {
		value = currentPtr->getValue();
		insertAtBack(value);
		currentPtr = currentPtr->getNext();
	}

	return *this;
}

//*********************************************************
//						<< operator
//
//	Task:	overloads the output operator to display
//			the contents of a Linked List with spaces
//			in between.
//
//*********************************************************
ostream & operator<<(ostream & out, const LinkedList list) {
	Node *currentPtr = list.headPtr;
	while (currentPtr != nullptr) {
		out << currentPtr->getValue().getPid() << " " << currentPtr->getValue().getArrivalTime() << " " << currentPtr->getValue().getCPUBurstTime() << " " << currentPtr->getValue().getPriority() << endl;
		currentPtr = currentPtr->getNext();
	}
	currentPtr = nullptr;
	return out;
}
