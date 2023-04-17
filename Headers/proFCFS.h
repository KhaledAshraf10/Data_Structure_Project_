#include "processor.h"
#include "LinkedList.h"
#pragma once
class ProFCFS : public processor
{
private:
	LinkedList<Process*> Plist;

public:

	ProFCFS(Schedular* p);

	virtual ~ProFCFS();

	virtual  int gettimer() const override;

	virtual bool ScheduleAlgo() override;

	void  forkingrequest(int AT, int RT);

	virtual void inctimer(Process* p) override;
	virtual void dectimer(Process* p) override;
	virtual void add_process(Process* p) override;


	// ana esmy eyad




};

