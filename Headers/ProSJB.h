#pragma once
#include"processor.h"
#include "../Headers/Queue.h"

class ProSJB : public processor
{
private:
	PriorityQueue  Plist;
	int nop; //no of processes in RDY LIST
	

public:

	ProSJB(Schedular* p,int overheatT);

	virtual ~ProSJB();

	virtual  int gettimer() const override;
	virtual void ScheduleAlgo() override;

	virtual void inctimer(Process* p) override;
	virtual void dectimer(Process* p) override;

	virtual void add_process(Process* p) override;
	void PrintRDY() override;
	bool PrintRUN() override;
	Process* getRUNList();
	Process* getprocess(Schedular* S) {
		if (RUNLIST != nullptr) {
			return RUNLIST;



		}



	}
	bool IsInRDY(int id) override;
	bool IsInRUN(int id) override;
	string getType() override;
	Process* getRdyProcess(int id) override;

	int getSizeOfRDYList();
	LinkedList<Process*> getRDYList();




};
