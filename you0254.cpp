#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"
#include "MyPCB.h"
#include "LinkedList.h"
#include "FCFSQueue.h"
#include "SJFQueue.h"
#include "SRTFQueue.h"
#include "RRQueue.h"
using namespace std;

void printTable(LinkedList& procs)
{
	procs.sortByPid();
	cout << "   -------------------------------------------------------------------------------------" << endl;
	cout << "   |  pid  | arrival | burst | finish | waiting | turnaround | response | # of context |" << endl;
	cout << "   -------------------------------------------------------------------------------------" << endl;
	int avgBurst = 0;
	float avgWait = 0;
	float avgTurnaround = 0;
	float avgResponse = 0;
	int totalContext = 0;
	Node* currentNode = procs.front();
	int i = 0;
	while (currentNode != nullptr)
	{
		// variables for computing and printing
		MyPCB* current = currentNode->getValuePtr();
		int pid = current->getPid();
		int arrival = current->getArrivalTime();
		int burst = current->getCPUBurstTime();
		float finish = current->getFinish();
		float wait = (finish - burst - arrival);
		float turnaround = (finish - arrival);
		float response = current->getResponse();
		int context = current->getContextSwitches();
		current = nullptr;

		// variables for averages
		avgBurst += burst;
		avgWait += wait;
		avgTurnaround += turnaround;
		avgResponse += response;
		totalContext += context;

		cout << "   | ";
		cout.width(5);
		cout << pid << " | ";

		cout.width(7);
		cout << arrival << " | ";

		cout.width(5);
		cout << burst << " | ";

		cout.width(6);
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(1);
		cout << finish << " | ";

		cout.width(7);
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(1);
		cout << wait << " | ";

		cout.width(10);
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(1);
		cout << turnaround << " | ";

		cout.width(8);
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(1);
		cout << response << " | ";

		cout.width(12);
		cout << context << " | " << endl;

		cout << "   -------------------------------------------------------------------------------------" << endl;
		currentNode = currentNode->getNext();
		++i;
	}
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);
	cout << "   Average CPU burst time = " << (float)avgBurst / i << " ms\tAverage waiting time = " << avgWait / i << " ms" << endl;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);
	cout << "   Average turn-around time = " << avgTurnaround / i << " ms\tAverage response time = " << avgResponse / i << " ms" << endl;
	cout << "   Total No. of Context Switching Performed = " << totalContext << endl;
	cout << endl;
}

void doFCFS(string filename)
{
	// === SETUP === //
	float clock = 0;
	LinkedList arrival;
	LinkedList terminate;
	FCFSQueue ready;
	arrival.populate(filename);
	arrival.sortByArrival();

	// === FUNCTIONALITY === //
	while (ready.front() != nullptr || arrival.front() != nullptr)
	{
		// if it is now the arrival time for the next process, add it to the cpu
		if (arrival.front() != nullptr)
		{
			if (arrival.front()->getValue().getArrivalTime() <= clock)
			{
				Node* prev = ready.front();

				// enqueue function will handle context swithc in the appropriate classes -- doesnt matter for FCFS
				ready.enqueue(arrival.front()->getValue()); 
				arrival.deleteAtFront();

				// if context switch occurred, clock will have to increase by 0.5
				if (prev != nullptr)
				{
					// if context switch
					if (prev->getValue().getPid() != ready.front()->getValue().getPid())
					{
						ready.front()->getValuePtr()->setResponse(0);
						clock += 0.5;
					}
				}
				else
				{
					ready.front()->getValuePtr()->setResponse(0);
				}
			}
		}

		// print current status at the start of this next 1ms time interval
		/*
		cout << endl << endl << endl << "Time: " << clock << endl;
		cout << "Not Admitted:" << endl << arrival << endl;
		cout << "In Ready Queue:" << endl << ready;
		*/
		// current process now uses cpu
		if (ready.front() != nullptr)
		{
			ready.front()->getValuePtr()->useCPU();
			if (ready.front()->getValue().isFinished())
			{
				ready.front()->getValuePtr()->setFinish(clock+1);
				terminate.insertAtBack(ready.front()->getValue());
				ready.dequeueFront();
				if (ready.front() != nullptr)
				{
					ready.front()->getValuePtr()->setResponse(clock + 1 - ready.front()->getValuePtr()->getArrivalTime());
				}
			}
		}
		++clock;
	}

	// === FINAL OUTPUT === //
	/*
	cout << endl << "Finished Processes: " << endl;
	cout << terminate << endl;
	*/
	cout << endl;
	cout << "   *************************************************************************************" << endl;
	cout << "   ************ Scheduling algorithm : FCFS        *************************************" << endl;
	cout << "   *************************************************************************************" << endl;
	cout << endl;
	printTable(terminate);
}

void doSJF(string filename)
{
	// === SETUP === //
	float clock = 0;
	LinkedList arrival;
	LinkedList terminate;
	SJFQueue ready;
	arrival.populate(filename);
	arrival.sortByArrival();

	// === FUNCTIONALITY === //
	while (ready.front() != nullptr || arrival.front() != nullptr)
	{
		// if it is now the arrival time for the next process, add it to the cpu
		if (arrival.front() != nullptr)
		{
			if (arrival.front()->getValue().getArrivalTime() <= clock)
			{
				Node* prev = ready.front();

				// enqueue function will handle context swithc in the appropriate classes -- doesnt matter for FCFS
				ready.enqueue(arrival.front()->getValue());
				arrival.deleteAtFront();

				// if context switch occurred, clock will have to increase by 0.5
				if (prev != nullptr)
				{
					// if context switch
					if (prev->getValue().getPid() != ready.front()->getValue().getPid())
					{
						clock += 0.5;
						ready.front()->getValuePtr()->setResponse(0);
						prev->getValuePtr()->doContextSwitch();
					}
				}
				else
				{
					ready.front()->getValuePtr()->setResponse(0);
				}
			}
		}

		// print current status at the start of this next 1ms time interval
		/*
		cout << endl << endl << endl << "Time: " << clock << endl;
		cout << "Not Admitted:" << endl << arrival << endl;
		cout << "In Ready Queue:" << endl << ready;
		*/
		// current process now uses cpu
		if (ready.front() != nullptr)
		{
			ready.front()->getValuePtr()->useCPU();
			if (ready.front()->getValue().isFinished())
			{
				ready.front()->getValuePtr()->setFinish(clock + 1);
				terminate.insertAtBack(ready.front()->getValue());
				ready.dequeueFront();
				if (ready.front() != nullptr)
				{
					ready.front()->getValuePtr()->setResponse(clock + 1 - ready.front()->getValuePtr()->getArrivalTime());
				}
			}
		}
		++clock;
	}

	// === FINAL OUTPUT === //
	/*
	cout << endl << "Finished Processes: " << endl;
	cout << terminate << endl;
	*/
	cout << endl;
	cout << "   *************************************************************************************" << endl;
	cout << "   ************ Scheduling algorithm : SJF         *************************************" << endl;
	cout << "   *************************************************************************************" << endl;
	cout << endl;
	printTable(terminate);
}

void doSRTF(string filename)
{
	// === SETUP === //
	float clock = 0;
	LinkedList arrival;
	LinkedList terminate;
	SRTFQueue ready;
	arrival.populate(filename);
	arrival.sortByArrival();
	bool finishflag = false;

	// === FUNCTIONALITY === //
	while (ready.front() != nullptr || arrival.front() != nullptr)
	{
		// if it is now the arrival time for the next process, add it to the cpu
		if (arrival.front() != nullptr)
		{
			if (arrival.front()->getValue().getArrivalTime() <= clock)
			{
				Node* prev = ready.front();

				// enqueue function will handle context swithc in the appropriate classes -- doesnt matter for FCFS
				ready.enqueue(arrival.front()->getValue());
				arrival.deleteAtFront();

				// if context switch occurred, clock will have to increase by 0.5
				if (prev != nullptr)
				{
					// if context switch
					if (prev->getValue().getPid() != ready.front()->getValue().getPid())
					{
						// actually a context switch
						/*
						if (!((clock - ready.front()->getValue().getArrivalTime()) > 0.1))
						{
							clock += 0.5;
							prev->getValuePtr()->doContextSwitch();
						}
						*/
						if (!finishflag)
						{
							clock += 0.5;
							prev->getValuePtr()->doContextSwitch();
						}

						// set response if first time in cpu
						if (ready.front()->getValue().getResponse() < 0)
						{
							ready.front()->getValuePtr()->setResponse(clock - ready.front()->getValuePtr()->getArrivalTime());
						}
					}
				}
				else
				{
					ready.front()->getValuePtr()->setResponse(0); // only element in queue, serviced immediately
				}
				prev = nullptr;
			}
		}
		finishflag = false;

		// current process now uses cpu
		if (ready.front() != nullptr)
		{
			ready.front()->getValuePtr()->useCPU();
			if (ready.front()->getValue().isFinished())
			{
				ready.front()->getValuePtr()->setFinish(clock + 1);
				terminate.insertAtBack(ready.front()->getValue());
				ready.dequeueFront();
				if (ready.front() != nullptr)
				{
					if (ready.front()->getValue().getResponse() < 0)
					{
						ready.front()->getValuePtr()->setResponse(clock + 1 - ready.front()->getValuePtr()->getArrivalTime());
					}
				}
				finishflag = true;
			}
		}
		clock += 1;
	}

	// === FINAL OUTPUT === //
	/*
	cout << endl << "Finished Processes: " << endl;
	cout << terminate << endl;
	*/
	cout << endl;
	cout << "   *************************************************************************************" << endl;
	cout << "   ************ Scheduling algorithm : SRTF        *************************************" << endl;
	cout << "   *************************************************************************************" << endl;
	cout << endl;
	printTable(terminate);
}

void doRR(string filename, int quantum)
{
	// === SETUP === //
	float clock = 0;
	int quantumCounter = 0;
	LinkedList arrival;
	LinkedList terminate;
	RRQueue ready;
	arrival.populate(filename);
	arrival.sortByArrival();
	if (quantum < 1) { quantum = 1; }

	// === FUNCTIONALITY === //
	while (ready.front() != nullptr || arrival.front() != nullptr)
	{
		// if it is now the arrival time for the next process, add it to the cpu
		if (arrival.front() != nullptr)
		{
			if (arrival.front()->getValue().getArrivalTime() <= clock)
			{
				// enqueue function will add the new process to the end of the queue
				// round robin queues do not preempt, so context switching will not happen here
				ready.enqueue(arrival.front()->getValue());
				if (ready.front()->getValue().getPid() == arrival.front()->getValue().getPid())
				{
					ready.front()->getValuePtr()->setResponse(0);
				}
				arrival.deleteAtFront();
			}
		}

		// If the quantum interval has completed, perform a context switch
		if (quantumCounter == quantum)
		{
			// get pid of current process in cpu
			int currentPid = ready.front()->getValuePtr()->getPid();
			Node* prev = ready.front();

			// cycle
			ready.cycle();

			// if a new process is in the cpu, then a context switch occurred
			// at the START of the time quantum
			if (currentPid != ready.front()->getValuePtr()->getPid())
			{
				clock += 0.5;
				quantumCounter = 0;
				prev->getValuePtr()->doContextSwitch();
				if (ready.front()->getValue().getResponse() < 0)
				{
					ready.front()->getValuePtr()->setResponse(clock - ready.front()->getValuePtr()->getArrivalTime());
				}
			}
			prev = nullptr;
		}


		// current process now uses cpu
		if (ready.front() != nullptr)
		{
			ready.front()->getValuePtr()->useCPU();
			if (ready.front()->getValue().isFinished())
			{
				ready.front()->getValuePtr()->setFinish(clock + 1);
				terminate.insertAtBack(ready.front()->getValue());
				ready.dequeueFront();
				quantumCounter = -1; // since it's incremented at end of loop, but process hasn't used cpu yet
				if (ready.front() != nullptr)
				{
					if (ready.front()->getValue().getResponse() < 0)
					{
						ready.front()->getValuePtr()->setResponse(clock + 1 - ready.front()->getValuePtr()->getArrivalTime());
					}
				}
			}
		}
		clock += 1;
		quantumCounter += 1;
	}

	// === FINAL OUTPUT === //
	cout << endl;
	cout << "   *************************************************************************************" << endl;
	cout << "   ************ Scheduling algorithm : Round Robin      ********************************" << endl;
	cout << "   ************ (No of tasks = ";
	cout.width(4);
	cout << terminate.length();
	cout << " Quantum = ";
	cout.width(4);
	cout << quantum;
	cout << ")     ********************************" << endl;
	cout << "   *************************************************************************************" << endl;
	cout << endl;
	printTable(terminate);
}



int main()
{
	// === VARIABLES === //
	string filename;
	int algorithm;
	int quantum;
	bool invalidInput;

	// === FUNCTIONALITY === //
	// prompt user for the given format specified in the lab
	//	unixprompt> myscheduler text_input_file (0,1,2, or 3) [quantumsize]
	//		0 = FIFO
	//		1 = SJF
	//		2 = SRTF
	//		3 = RR (quantum required)
	cout << "Please Input in the Following Format: file_name (0,1,2,3) [quantum]" << endl;
	cout << "   0 = FCFS" << endl;
	cout << "   1 = SJF" << endl;
	cout << "   2 = SRTF" << endl;
	cout << "   3 = RR" << endl;
	cout << "   [quantum] is required only for RR" << endl << endl;

	do {
		invalidInput = false;
		cout << "unixprompt> myscheduler ";
		cin >> filename;
		cin >> algorithm;
		if (algorithm == 3)
		{
			cin >> quantum;
		}

		// perform a switch statement on the algorithm int to determine
		// which operations to perform
		switch (algorithm)
		{
		case 0:
			doFCFS(filename);
			break;
		case 1:
			doSJF(filename);
			break;
		case 2:
			doSRTF(filename);
			break;
		case 3:
			doRR(filename, quantum);
			break;
		default:
			cout << "** Invalid Algorithm **" << endl;
			invalidInput = true;
			break;
		}
	} while (invalidInput);
	return 0;
}