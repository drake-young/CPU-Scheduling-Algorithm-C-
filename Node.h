#ifndef NODE_
#define NODE_

#include "MyPCB.h"

class Node
{
private:
	Node* next;
	MyPCB value;

public:
	Node() 
	{
		next = nullptr;
	}
	Node(MyPCB val)
	{
		next = nullptr;
		value = val;
	}

	~Node() { next = nullptr; }

	Node* getNext() { return next; }
	void setNext(Node* newNext) { next = newNext; }

	MyPCB getValue() { return value; }
	MyPCB* getValuePtr() { return &value; }
	void setValue(MyPCB newVal) { 
		value.setPid(newVal.getPid());
		value.setArrivalTime(newVal.getArrivalTime());
		value.setCPUBurstTime(newVal.getCPUBurstTime());
		value.setPriority(newVal.getPriority());
		value.setFinish(newVal.getFinish());
		value.setWait(newVal.getWait());
		value.setResponse(newVal.getResponse());
		value.setContextSwitches(newVal.getContextSwitches());
	}

	static void swapValues(Node* left, Node* right)
	{
		Node* temp = new Node();
		temp->setValue(right->getValue());
		right->setValue(left->getValue());
		left->setValue(temp->getValue());
		delete temp;
		temp = nullptr;

	}
};

#endif /* NODE_ */