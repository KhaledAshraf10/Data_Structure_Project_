#pragma once
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
	if (RUNLIST == nullptr) {
		if (Plist.size() == 0) { return; }

		  Plist.getbeg(RUNLIST);
		  dectimer(RUNLIST);

		  noP--;
		  

	}else
		if (RUNLIST->getremainingtime() != 0) {
			srand(time(0));
			int x = 1 + (rand() % 100);

			if(1<=x<=15)
			
			{
			  
				pS->Add_To_BLK(RUNLIST);

				RUNLIST = nullptr;
			
			}
			else if (20 <= x <= 30) {

				Plist.InsertEnd(RUNLIST);
				inctimer(RUNLIST);
				RUNLIST = nullptr;
				noP++;
				
				
			}
			else if (50 <= x <= 60) {


				pS->Add_To_TRM(RUNLIST);
				RUNLIST = nullptr;

			}



			



		}
		else 
			if (RUNLIST->getremainingtime() == 0) {

				pS->Add_To_TRM(RUNLIST);
				RUNLIST = nullptr;


			}




}

void ProFCFS::forkingrequest(int AT, int RT)
{}

void ProFCFS::inctimer(Process* p)
{
	timer += p->getremainingtime();
}

void ProFCFS::inctimer(int time)
{
	timer += time;
}

void ProFCFS::dectimer(Process* p)
{
	timer -= p->getremainingtime();
}

void ProFCFS::add_process(Process* p)
{
	Plist.InsertEnd(p);
	noP++;
	inctimer(p);


}

bool ProFCFS::RandomKiller() {
	srand(time(0));
	int x = 1 + (rand() % 999);
	 

     int time= Plist.DeleteNodeR(x);
	  if (time < 0) {
		  return false;
	  }
	  else {
		  inctimer(time);
		  noP--;
	  }


	return true;

}

bool ProFCFS::PrintRUN() {
	if (RUNLIST != nullptr) {
		cout << RUNLIST->getId();
		return true;

	}
	else {
		return false;
	}


}

void ProFCFS::PrintRDY() {

	 
		Plist.PrintListid();
		 


	



}






