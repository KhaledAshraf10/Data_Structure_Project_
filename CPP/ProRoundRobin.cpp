#include "ProRoundRobin.h"




//sdfa

ProRoundRobin::ProRoundRobin(scheduler* p) :processor(p)
{
	timer = 0;
	RUNLIST = nullptr;
}


ProRoundRobin::~ProRoundRobin()
{}


int ProRoundRobin::gettimer() const
{}


bool ProRoundRobin::ScheduleAlgo()
{}

void ProRoundRobin::inctimer(int timestep)
{

	inctimer(p->getCpuTime());

}

void ProRoundRobin::dectimer(int timestep)
{}

