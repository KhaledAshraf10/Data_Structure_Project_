#include "processor.h"
#include "LinkedList.h"
#pragma once
class ProFCFS : public processor
{
private:
	LinkedList<Process*> Plist;
	int noP; //no pf processes in RDY LIST

public:

	ProFCFS(Schedular* p);

	virtual ~ProFCFS();

	virtual  int gettimer() const override;

	virtual void ScheduleAlgo() override;

	void  forkingrequest(int AT, int RT);

	virtual void inctimer(Process* p) override;
	virtual void inctimer(int time);
	virtual void dectimer(Process* p) override;
	virtual void add_process(Process* p) override;
	virtual bool RandomKiller();
	virtual bool PrintRDY() override;
	virtual bool PrintRUN() override;

	// ana esmy eyad




};

