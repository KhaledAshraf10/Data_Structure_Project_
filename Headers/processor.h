#include <iostream>
#include "process.h"
using namespace std;


#pragma once
class processor
{
protected:
	Schedular* pS;
	int timer; // a sum for all CTs in the processor's rdy list
	bool flag; // a flag to determine whether the processor is IDLE(=1) or BUSY(=0)
	Process*  RUNLIST; 

public:
	processor(Schedular* p) {
		pS = p;
		
	};
	virtual ~processor() {};
	virtual bool ScheduleAlgo() = 0;
	virtual int gettimer() const {};
	virtual void inctimer(Process* p) = 0;
	virtual void dectimer(Process* p) = 0;
	virtual void add_process(Process* p) = 0;


	//first commit











};

