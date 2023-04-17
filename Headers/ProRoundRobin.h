#include "processor.h"
#pragma once
class ProRoundRobin : public processor
{
private:
	Queue Plist;

	int RTF; //a thershold to be used in migration functionality
     int timeslice;    //the timeslice for RR algorithm(to be loaded from the input file)


	int counter;   // used to monitor the timeslice of the RR algorithm

	


public:

	ProRoundRobin(Schedular* p);

	virtual ~ProRoundRobin();

	virtual  int gettimer() const override;
	virtual bool ScheduleAlgo() override;

	virtual void inctimer(Process* p) override;
	virtual void dectimer(Process* p) override;

	virtual void add_process(Process* p) override





};
