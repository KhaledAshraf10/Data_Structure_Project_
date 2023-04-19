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

public:
	processor(Schedular* p) {
	
	};
	virtual ~processor() {};
	virtual void ScheduleAlgo() = 0;
	virtual int gettimer() const = 0;
	virtual void inctimer(Process* p) = 0;
	virtual void dectimer(Process* p) = 0;
	virtual void add_process(Process* p) = 0;
	virtual void PrintRDY() = 0;
	virtual bool PrintRUN() = 0;


	//first commit











};

