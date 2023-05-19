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
	bool flag; // a flag to determine whether the processor is IDLE(=1) or BUSY(=0)
	Process*  RUNLIST; 
	bool  recent;

public:
	processor(Schedular* p) {
		pS = p;
		recent = false;
	
	};
	virtual ~processor() {};
	virtual void ScheduleAlgo() = 0;
	virtual int gettimer() const = 0;
	virtual void inctimer(Process* p) = 0;
	virtual void dectimer(Process* p) = 0;
	virtual void add_process(Process* p) = 0;
	virtual void PrintRDY() = 0;
	virtual bool PrintRUN() = 0;
	virtual Process* getprocess(Schedular* S) = 0;
	virtual bool isrecent() { return recent; }
	virtual void setrecent() { recent = true; }
	virtual void unsetrecent() { recent = false; }
	virtual bool IsInRDY(int id) = 0;
	virtual bool IsInRUN(int id) = 0;
	virtual string getType() = 0;
	virtual Process* getRdyProcess(int id) = 0;
	

		

	//first commit











};

