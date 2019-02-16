*******************************************************
*  Name      :    Drake Young               
*  Class     :    CSCI 3453           
*  Lab#      :    2   
*  Due Date  :    Oct. 29, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

In this assignment, we are tasked with programming our own implementation
of the scheduling algorithms: First-Come-First-Served, Shortest Job First,
Shortest Remaining Time First, and Round-Robin with a user-specified
input file and time quantum


*******************************************************
*  Source files
*******************************************************

Name:  you0254.cpp
   Main program.  This is the driver program it prompts the user for the appropriate inputs, and performs the specified
   scheduling algorithm utilizing the appropriate queue concrete class, and outputs the results of the scheduling algorithm

Name:  LinkedList.h
   Contains the class definition of the LinkedList class

Name: LinkedList.cpp
   Defines and implements the LinkedList member functions. It also handles the allocation and deallocation
   of the dynamic memory necessary for this "Linked List" in order to prevent memory leaks.

Name:	Queue.h
	Contains the class definition of the parent class Queue 
	
Name:	Queue.cpp
   Defines and implements the nonvirtual Queue member functions. It also handles the allocation and deallocation
   of the dynamic memory necessary for this "Queue" in order to prevent memory leaks.
   
Name:	FCFSQueue.h
	Contains the class definition of the child class FCFSQueue, which inherits from the Queue class
	
Name:	FCFSQueue.cpp
   Defines and implements the virtual Queue member functions, as well as the additional FCFSQueue member functions. 
   It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to 
   prevent memory leaks.
   
Name:	SJFQueue.h
	Contains the class definition of the child class SJFQueue, which inherits from the Queue class
	
Name:	SJFQueue.cpp
   Defines and implements the virtual Queue member functions, as well as the additional SJFQueue member functions. 
   It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to 
   prevent memory leaks.
   
Name:	SRTFQueue.h
	Contains the class definition of the child class SRTFQueue, which inherits from the Queue class
	
Name:	SRTFQueue.cpp
   Defines and implements the virtual Queue member functions, as well as the additional SRTFQueue member functions. 
   It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to 
   prevent memory leaks.
   
Name:	RRQueue.h
	Contains the class definition of the child class RRQueue, which inherits from the Queue class
	
Name:	RRQueue.cpp
   Defines and implements the virtual Queue member functions, as well as the additional RRQueue member functions. 
   It also handles the allocation and deallocation of the dynamic memory necessary for this "Queue" in order to 
   prevent memory leaks.
   
Name:	MyPCB.h
	Contains the class definition of the class MyPCB. All implementation of the member functions are
	contained within the class

Name:	Node.h
	Contains the class definition of the class Node. All implementation of the member functions are
	contained within the class
	
Name: input4
   Contains four rows with 3 integer values per row representing the PID, arrival time, and CPU burst time
   respectively. each line contains a newline character after the final integer, and the integers may be
   separated on a line by any number of white space characters >= 1
   
Name: input10
   Contains ten rows with 4 integer values per row representing the PID, arrival time, and CPU burst time, and priority
   respectively. each line contains a newline character after the final integer, and the integers may be
   separated on a line by any number of white space characters >= 1
   
Name: input100
   Contains one-hundred rows with 4 integer values per row representing the PID, arrival time, and CPU burst time, and priority
   respectively. each line contains a newline character after the final integer, and the integers may be
   separated on a line by any number of white space characters >= 1

*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on the CSE Grid


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress and extract it use the following commands 
       % tar -xvzf [you0254.tar.gz]

   Now you should see a directory named you0254 with the files:
        you0254.cpp
		Queue.cpp
		Queue.h
		FCFSQueue.cpp
		FCFSQueue.h
		SJFQueue.cpp
		SJFQueue.h
		SRTFQueue.cpp
		SRTFQueue.h
		RRQueue.cpp
		RRQueue.h
		LinkedList.cpp
		LinkedList.h
		MyPCB.h
		Node.h
		input4
		input10
		input100
        makefile
        readme.txt

2. Build the program.

    Compile the program by:
    % make

3. Run the program by:
   % ./[you0254]

4. Delete the obj files, executables, and core dump by
   %./make clean

