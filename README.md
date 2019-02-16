# CPU Scheduling Algorithm (C++)

This project is a simulation of four CPU scheduling algorithms, as an assignment for the course Operating Systems Concepts (see "Assignment Specifications" pdf file for a detailed description of the assignment

In this assignment, we are tasked with programming our own implementation of the scheduling algorithms: First-Come-First-Served, Shortest Job First, Shortest Remaining Time First, and Round-Robin with a user-specified input file and time quantum

## Source Files

**you0254.cpp**<br/>
Main program. This is the driver program it prompts the user for the appropriate inputs, and performs the specified scheduling algorithm utilizing the appropriate queue concrete class, and outputs the results of the scheduling algorithm
   
**LinkedList.h**<br/>
Contains the class definition of the LinkedList class

**LinkedList.cpp**<br/>
Defines and implements the LinkedList member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Linked List" in order to prevent memory leaks.

**Queue.h**<br/>
Contains the class definition of the parent class Queue 

**Queue.cpp**<br/>
Defines and implements the nonvirtual Queue member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to prevent memory leaks.

**FCFSQueue.h**<br/>
Contains the class definition of the child class FCFSQueue, which inherits from the Queue class

**FCFSQueue.cpp**<br/>
Defines and implements the virtual Queue member functions, as well as the additional FCFSQueue member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to  prevent memory leaks.

**SJFQueue.h**<br/>
Contains the class definition of the child class SJFQueue, which inherits from the Queue class

**SJFQueue.cpp**<br/>
Defines and implements the virtual Queue member functions, as well as the additional SJFQueue member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to  prevent memory leaks.

**SRTFQueue.h**<br/>
Contains the class definition of the child class SRTFQueue, which inherits from the Queue class

**SRTFQueue.cpp**<br/>
Defines and implements the virtual Queue member functions, as well as the additional SRTFQueue member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to prevent memory leaks.

**RRQueue.h**<br/>
Contains the class definition of the child class RRQueue, which inherits from the Queue class

**RRQueue.cpp**<br/>
Defines and implements the virtual Queue member functions, as well as the additional RRQueue member functions. It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to prevent memory leaks.

**MyPCB.h**<br/>
Contains the class definition of the class MyPCB. All implementation of the member functions are contained within the class

**Node.h**<br/>
Contains the class definition of the class Node. All implementation of the member functions are contained within the class

**input4**<br/>
Contains four rows with 3 integer values per row representing the PID, arrival time, and CPU burst time respectively. each line contains a newline character after the final integer, and the integers may be separated on a line by any number of white space characters >= 1

**input10**<br/>
Contains ten rows with 4 integer values per row representing the PID, arrival time, and CPU burst time, and priority respectively. each line contains a newline character after the final integer, and the integers may be separated on a line by any number of white space characters >= 1

**input100**<br/>
Contains one-hundred rows with 4 integer values per row representing the PID, arrival time, and CPU burst time, and priority respectively. each line contains a newline character after the final integer, and the integers may be separated on a line by any number of white space characters >= 1

## Circumstances of the Program

The Program Runs Successfully

The program was developed and tested on gnu g++ 4.4.2.

## How to Build and Run the Program

1. Download, Pull, or Clone this repository 
2. Ensure that you have the following files within your local copy:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;you0254.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Queue.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Queue.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FCFSQueue.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FCFSQueue.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SJFQueue.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SJFQueue.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SRTFQueue.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SRTFQueue.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RRQueue.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RRQueue.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LinkedList.cpp<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LinkedList.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MyPCB.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Node.h<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;input4<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;input10<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;input100<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;makefile<br/>
3. Build the Program.<br/><br/>
Compile the Program By:<br/>
% make<br/><br/>
4. Run the Program by:<br/>
% ./you0254<br/><br/>
5. Delete the obj files, executables, and core dump by<br/>
% ./make clean

## Author

* **Drake Young** - [drake-young](https://github.com/drake-young)

## Sample Output
