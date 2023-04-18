
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


void ProRoundRobin::ScheduleAlgo()
{


	if (RUNLIST == nullptr) {

		Plist.dequeue(RUNLIST);
		
		dectimer(RUNLIST);

	}
	
	else if (RUNLIST->getremainingtime() ==0) {

		//Ps->move to TRM(RUNLIST);

	}

	else
		if (counter <= timeslice) {
            srand(time(0));
			int x = 1 + (rand() % 100);

			RUNLIST->decremainingtime();

			counter++;

			

			if (1 <= x <= 15)

			{

				//Ps->move to BLK(RUNLIST)		
				RUNLIST = nullptr;

			}
			else if (20 <= x <= 30) {

				Plist.enqueue(RUNLIST);
				inctimer(RUNLIST);
				RUNLIST = nullptr;
				counter == 0;

			}
			else if (50 <= x <= 60) {


				//pS->//move to TRM;
				RUNLIST = nullptr;

			}












		}

		else if(counter>=timeslice)

		{
			Plist.enqueue(RUNLIST);
			inctimer(RUNLIST);
			RUNLIST = nullptr;
			counter == 0;

		}
		else if (RUNLIST->getremainingtime() == 0) {

			//Ps->move to TRM(RUNLIST);
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