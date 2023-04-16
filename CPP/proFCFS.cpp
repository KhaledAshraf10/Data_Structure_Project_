#include "ProFCFS.h"


ProFCFS::ProFCFS(scheduler* p) :processor(p)
{
	timer = 0;

	RUNLIST = nullptr;
}

ProFCFS::~ProFCFS()
{}

int ProFCFS::gettimer() const
{}

bool ProFCFS::ScheduleAlgo()
{}

void ProFCFS::forkingrequest(int AT, int RT)
{}

void ProFCFS::inctimer(int time)
{}

void ProFCFS::dectimer(int time)
{}

void ProFCFS::add_process(Process* p)
{
	inctimer(p->getCpuTime());


}

