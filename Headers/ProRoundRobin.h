#pragma once

#include "processor.h"

#include"../Headers/Queue.h"



class ProRoundRobin : public processor
{
private:
	Queue<Process*> Plist;

	int RTF; //a thershold to be used in migration functionality
     int timeslice;    //the timeslice for RR algorithm(to be loaded from the input file)


	int counter;   // used to monitor the timeslice of the RR algorithm
	int nop; //no of processors inside the rdy list

	


public:

	 ProRoundRobin(Schedular* p);

	virtual ~ProRoundRobin();

	virtual  int gettimer() const override;
	virtual void ScheduleAlgo() override;

	virtual void inctimer(Process* p) override;
	virtual void dectimer(Process* p) override;

	virtual void add_process(Process* p) override;
	Process* getRUNList();
	void PrintRDY() override;
	bool PrintRUN() override;
	Process* getprocess(Schedular* S) {
		if (RUNLIST != nullptr) {
			return RUNLIST;



		}



	}
	bool IsInRDY(int id) override;
	bool IsInRUN(int id) override;
	string getType() override;
	Process* getRdyProcess(int id) override;





};
