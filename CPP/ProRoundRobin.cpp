
#include "../Headers/ProRoundRobin.h"
#include "../Headers/Schedular.h"





//sdfa

ProRoundRobin::ProRoundRobin(Schedular* p) :processor(p)
{
	timer = 0;
	RUNLIST = nullptr;
}


ProRoundRobin::~ProRoundRobin()
{}


int ProRoundRobin::gettimer() const
{}


bool ProRoundRobin::ScheduleAlgo()
{


	if (RUNLIST == nullptr) {

		RUNLIST = Plist.dequeue();

		dectimer(RUNLIST);

	}

	else
		if (counter <= timeslice) {


			RUNLIST->decremainingtime();

			counter++;
		}

		else

		{
			Plist.Queue(RUNLIST);
			inctimer(RUNLIST);
			RUNLIST = nullptr;

		}




}

void ProRoundRobin::inctimer(Process* p)
{

	timer+=(p->getremainingtime());

}

void ProRoundRobin::dectimer(Process *p)
{

	timer -= (p->getremainingtime());

}

