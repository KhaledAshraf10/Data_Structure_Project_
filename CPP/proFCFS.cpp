
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"


ProFCFS::ProFCFS(schedular* p) :processor(p)
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

void ProFCFS::inctimer(Process* p)
{}

void ProFCFS::dectimer(Process* p)
{}

void ProFCFS::add_process(Process* p)
{
	inctimer(p->getCpuTime());


}

