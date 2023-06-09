#pragma once
#include <iostream>
#include "process.h"
#include "Schedular.h"
using namespace std;


class Schedular;

class processor
{
protected:
	Schedular* pS;
	int timer; // a sum for all CTs in the processor's rdy list
	bool isIdle; // a flag to determine whether the processor is IDLE(=1) or BUSY(=0)
	Process*  RUNLIST; 
	bool  recent;
	int overheatprop = 5;   //very low probability of 5 percent to overheat
	int overheatmaltime; //timesteps for the processor to regain activation after overheating (taken from the input file)
	bool isHeated; //flag to indicate whether the precssor is currently wrokin or not
	int overheatingcounter;  //counter to process the ovrheating time
	int Busytime;
	int IDLEtime;


public:
	processor(Schedular* p,int overheatT) {
		pS = p;
		recent = false;
		this->overheatmaltime = overheatT;
	
	};
	virtual ~processor() {};
	virtual void ScheduleAlgo() = 0;
	virtual int gettimer() const = 0;
	virtual void inctimer(Process* p) = 0;
	virtual void dectimer(Process* p) = 0;
	virtual void add_process(Process* p) = 0;
	virtual void PrintRDY() = 0;
	virtual bool PrintRUN() = 0;
	virtual Process* getRUNList() = 0;
	virtual Process* getprocess(Schedular* S) = 0;
	virtual bool isrecent() { return recent; }
	virtual void setrecent() { recent = true; }
	virtual void unsetrecent() { recent = false; }

	virtual bool IsHeated() { return isHeated; }
	virtual void setIsHeated() { isHeated = true; }
	virtual void unsetIsHeated() { isHeated = false; }
	virtual bool IsInRDY(int id) = 0;
	virtual bool IsInRUN(int id) = 0;
	virtual string getType() = 0;
	virtual Process* getRdyProcess(int id) = 0;
  
	virtual void setRUNNull() = 0;
	virtual void deleteNode(Process* p) = 0;
	virtual void decNoop() = 0;


	virtual int getSizeOfRDYList() = 0;
	virtual LinkedList<Process*> getRDYList() = 0;
	virtual void incrementBusyTime() = 0;
	virtual void incrementIDLETime() = 0;
	virtual	int getBusyTime() = 0;
	virtual int getIDLETime() = 0;
	virtual void KillSig() = 0;


		

	//first commit











};

