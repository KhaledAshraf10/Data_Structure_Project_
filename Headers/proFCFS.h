#include "processor.h"
#include "LinkedList.h"
#pragma once
class ProFCFS : public processor
{
private:
	LinkedList Plist;

public:

	ProFCFS(scheduler* p);

	virtual ~ProFCFS();

	virtual  int gettimer() const override;

	virtual bool ScheduleAlgo() override;

	void  forkingrequest(int AT, int RT);

	virtual void inctimer(int time) override;
	virtual void dectimer(int time) override;
	virtual void add_process(Process* p) override;


	// ana esmy eyad




};

