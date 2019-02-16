#ifndef MYPCB_
#define MYPCB_

class MyPCB
{
private:
	int pid;
	int arrivalTime;
	int CPUBurstTime;
	int priority;
	int timeRan;
	int contextSwitches;
	float wait;
	float timeFinish;
	float response;

public:
	MyPCB()
	{
		pid = 0;
		arrivalTime = 0;
		CPUBurstTime = 0;
		priority = 0;
		timeRan = 0;
		wait = 0;
		timeFinish = 0;
		response = -1;
		contextSwitches = 0;
	}
	MyPCB(int myPid, int myArrivalTime, int myCPUBurstTime, int myPriority)
	{
		pid = myPid;
		arrivalTime = myArrivalTime;
		CPUBurstTime = myCPUBurstTime;
		priority = myPriority;
		timeRan = 0;
		wait = 0;
		timeFinish = 0;
		response = -1;
		contextSwitches = 0;
	}

	int getPid() { return pid; }
	int getArrivalTime() { return arrivalTime; }
	int getCPUBurstTime() { return CPUBurstTime; }
	int getPriority() { return priority; }
	int getContextSwitches() { return contextSwitches; }
	float getWait() { return wait; }
	float getFinish() { return timeFinish; }
	float getResponse() { return response; }

	void setPid(int newpid) { pid = newpid; }
	void setArrivalTime(int newarrivaltime) { arrivalTime = newarrivaltime; }
	void setCPUBurstTime(int newbursttime) { CPUBurstTime = newbursttime; }
	void setPriority(int newpriority) { priority = newpriority; }
	void setContextSwitches(int newcontextswitches) { contextSwitches = newcontextswitches; }
	void setWait(float newwait) { wait = newwait; }
	void setWait(int newwait) { wait = (float)newwait; }
	void setFinish(float finish) { timeFinish = finish; }
	void setFinish(int finish) { timeFinish = (float)finish; }
	void setResponse(float newresponse) { response = newresponse; }
	void setResponse(int newresponse) { response = (float)newresponse; }

	void useCPU()
	{
		if (CPUBurstTime > timeRan)
		{
			++timeRan;
		}
	}
	void doContextSwitch()
	{
		++contextSwitches;
	}

	float getRemainingTime() { return CPUBurstTime - timeRan; }

	bool isFinished() { return CPUBurstTime == timeRan; }

	bool operator==(MyPCB &right)
	{
		return (right.getPid() == pid && right.getArrivalTime() == arrivalTime && right.getCPUBurstTime() == CPUBurstTime && right.getPriority() == priority);
	}
};

#endif /* MYPCB_ */