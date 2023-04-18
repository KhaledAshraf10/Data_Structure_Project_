
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"
#include <time.h>


ProFCFS::ProFCFS(Schedular* p) :processor(p)
{
	timer = 0;
	noP = 0;

	RUNLIST = nullptr;
}

ProFCFS::~ProFCFS()
{}

int ProFCFS::gettimer() const
{
	return timer;

}

void ProFCFS::ScheduleAlgo()
{
	if (RUNLIST = nullptr) {

		  Plist.getbeg(RUNLIST);
		  noP--;
		 

	}else
		if (RUNLIST->getremainingtime() != 0) {
			srand(time(0));
			int x = 1 + (rand() % 100);

			if(1<=x<=15)
			
			{
			  
                 //Ps->move to BLK(RUNLIST)		
				RUNLIST = nullptr;
			
			}
			else if (20 <= x <= 30) {

				Plist.InsertEnd(RUNLIST);
				inctimer(RUNLIST);
				RUNLIST = nullptr;
				noP++;
				
				
			}
			else if (50 <= x <= 60) {


				//pS->//move to TRM;
				RUNLIST = nullptr;

			}



			



		}
		else 
			if (RUNLIST->getremainingtime() == 0) {

				//pS->//move to TRM;
				RUNLIST = nullptr;


			}




}

void ProFCFS::forkingrequest(int AT, int RT)
{}

void ProFCFS::inctimer(Process* p)
{
	timer += p->getremainingtime();
}

void ProFCFS::dectimer(Process* p)
{
	timer -= p->getremainingtime();
}

void ProFCFS::add_process(Process* p)
{
	Plist.InsertEnd(p);
	noP++;


}

bool ProFCFS::RandomKiller() {
	srand(time(0));
	int x = 1 + (rand() % 999);
	if (RUNLIST->getId() == x) {
		//Ps->move to TRM
		RUNLIST = nullptr;
		return true;
	}
	
	




}


