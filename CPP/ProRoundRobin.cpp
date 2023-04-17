
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
{
	return timer;

}


bool ProRoundRobin::ScheduleAlgo()
{


	if (RUNLIST == nullptr) {

		Plist.dequeue(RUNLIST);
		
		dectimer(RUNLIST);

	}

	else
		if (counter <= timeslice) {


			RUNLIST->decremainingtime();

			counter++;
		}

		else

		{
			Plist.enqueue(RUNLIST);
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

void ProRoundRobin::add_process(Process* p) {


	Plist.enqueue(p);


}