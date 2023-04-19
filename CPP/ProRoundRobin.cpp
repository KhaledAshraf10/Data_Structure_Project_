
#include "../Headers/ProRoundRobin.h"
#include "../Headers/Schedular.h"






//sdfa

 ProRoundRobin::ProRoundRobin(Schedular* p) :processor(p)

{
	 nop = 0;
	 counter=0;
	timer = 0;
	RUNLIST = nullptr;
	timeslice = 3;
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
	
	//else if (RUNLIST->getremainingtime() ==0) {



	//	//Ps->move to TRM(RUNLIST);

	//}
	srand(time(0));
	int x = 1 + (rand() % 100);
	
		//if (counter <= timeslice) {
  //          srand(time(0));
		//	int x = 1 + (rand() % 100);

		//	RUNLIST->decremainingtime();

		//	//counter++;

			

			if (1 <= x&&x <= 15)

			{

				//Ps->move to BLK(RUNLIST)		
				RUNLIST = nullptr;

			}
			else if (20 <= x&&x <= 30) {

				Plist.enqueue(RUNLIST);
				inctimer(RUNLIST);
				RUNLIST = nullptr;
				counter == 0;

			}
			else if (50 <= x&&x <= 60) {


				//pS->//move to TRM;
				RUNLIST = nullptr;

			}










	//}
	srand(time(0));
	int x = 1 + (rand() % 100);
	
		//if (counter <= timeslice) {
  //          srand(time(0));
		//	int x = 1 + (rand() % 100);


		else if(counter>=timeslice)

		{
			Plist.enqueue(RUNLIST);
			inctimer(RUNLIST);
			RUNLIST = nullptr;
			counter == 0;


		}
		//else if (RUNLIST->getremainingtime() == 0) {

		//	//Ps->move to TRM(RUNLIST);
		//	RUNLIST = nullptr;

		//}




}

void ProRoundRobin::inctimer(Process* p)
{

	timer+=(p->getremainingtime());
	nop++;

}

void ProRoundRobin::dectimer(Process *p)
{
	int x = p->getremainingtime();
	timer -= (p->getremainingtime());
	nop--;

}

void ProRoundRobin::add_process(Process* p) {

	inctimer(p);
	Plist.enqueue(p);



}


bool ProRoundRobin::PrintRDY() {
	Plist.Printlistid();
	return true;


}





bool ProRoundRobin::PrintRUN() {
	if (RUNLIST != nullptr) {
		cout << RUNLIST->getId();
		return true;

	}
	else {
		return false;
	}


}