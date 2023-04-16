#include "processor.h"
#pragma once
class ProRoundRobin : public processor
{
private:
	Queue Plist;

	int RTF; //a thershold to be used in migration functionality


public:

	ProRoundRobin(scheduler* p);

	virtual ~ProRoundRobin();

	virtual  int gettimer() const override;
	virtual bool ScheduleAlgo() override;

	virtual void inctimer(int time) override;
	virtual void dectimer(int time) override;

	virtual void add_process(Process* p) override





};
