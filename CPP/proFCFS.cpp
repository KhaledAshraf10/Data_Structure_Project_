#pragma once
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"
#include <time.h>


ProFCFS::ProFCFS(Schedular* p,int overheatT) :processor(p,overheatT)
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
	if (this->IsHeated()) {
		if (overheatingcounter == overheatmaltime) {
			this->unsetIsHeated();
			return;
		}
		this->overheatingcounter++;
	return; }
	else {
		srand(time(0));
	int x = 1 + (rand() % 100);

	if (x ==5 ) {
		this->setIsHeated();


	}


	}

	



	if (RUNLIST == nullptr) {
		if (Plist.size() == 0) { return; }

		  Plist.getbeg(RUNLIST);
		  dectimer(RUNLIST);

		  noP--;
		  

	}else
		if (RUNLIST->getremainingtime() != 0) {
			srand(time(0));
			/*int x = 1 + (rand() % 100);*/
			int x = 15;

			if(1<=x && x<=15)
			
			{
			  
				pS->Add_To_BLK(RUNLIST);

		}
		noP = 0;
		overheatingcounter++;
		this->timer = 0;
		return;

	}
	else

	
		
		if (RUNLIST->getremainingtime() != 0) {
			

			//int totalexecutiontime = RUNLIST->getCpuTime() - RUNLIST->getremainingtime();
			//bool flag = false;
			//for (int i = 0; i < sizeof(RUNLIST->getIO_RD())/sizeof(Node2); i++) {               //na2sa l7d get IO matt3ml!!
			//	if (totalexecutiontime == arrayIO[i]) {
			//		pS->Add_To_BLK(RUNLIST);
			//		RUNLIST=nullptr
			//		

			//	}
			//		
			//}
			

			

		

			RUNLIST->decremainingtime();
			return;
			



		}
		else 
			if (RUNLIST->getremainingtime() == 0) {

				pS->Add_To_TRM(RUNLIST);
				RUNLIST = nullptr;
				return;


			}




}

void ProFCFS::forkingrequest(Process* p)
{
	pS->Fork(p);
}
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

Process* ProFCFS::getRUNList()
{
	return RUNLIST;
}

void ProFCFS::PrintRDY() {

	 
		Plist.PrintListid();
		 


	



}






