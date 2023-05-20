#pragma once
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"
#include <time.h>

Queue<MyStruct> ProFCFS::KillSigList;
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
		if (noP == 0) { return; }

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

				RUNLIST = nullptr;
			
			}
			else if (20 <= x && x <= 30) {

				Plist.InsertEnd(RUNLIST);
				inctimer(RUNLIST);
				RUNLIST = nullptr;
				noP++;
				
				
			}
			else if (50 <= x && x <= 60) {


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


void ProFCFS::KillSig()
{
	MyStruct s1, tempp;
	int TimeStep = pS->getTimeStep();
	int nFCFS = pS->getnFCFS();
	processor** arr_Processor = pS->getProcessorList();
	pS->LoadSigKillList();
	KillSigList.peek(s1);
	if (s1.KillTime != TimeStep)
	{
		return;
	}
	while (KillSigList.peek(s1))
	{
		if (s1.KillTime == TimeStep)
		{
			for (int i = 0; i < nFCFS; i++) // ana mout2kd en list of processor awl hagat feha hya fcfs
			{
				if (arr_Processor[i]->IsInRUN(s1.ID) && arr_Processor[i]->getType() == "ProFCFS")
				{
					//arr_Processor[i]->KillProcess(s1.ID);
					KillSigList.dequeue(tempp);
					pS->Add_To_TRM(arr_Processor[i]->getprocess(pS));
				}
				else if (arr_Processor[i]->IsInRDY(s1.ID) && arr_Processor[i]->getType() == "ProFCFS")
				{
					KillSigList.dequeue(tempp);
					pS->Add_To_TRM(arr_Processor[i]->getRdyProcess(s1.ID));
					//Plist.DeleteNode(arr_Processor[i]->getRdyProcess(s1.ID));
				}
			}
		}

	}
}
Process* ProFCFS::getRUNList()
{
	return RUNLIST;
}


void ProFCFS::EnqueuEelements(const MyStruct& element)
{
	KillSigList.enqueue(element);
}

bool ProFCFS::IsInRDY(int id)
{
	
	return Plist.Check(id);
}
Process* ProFCFS::getRdyProcess(int id)
{
	return Plist.getRdyProcessFL(id);
}

bool ProFCFS::IsInRUN(int id)
{	
	return RUNLIST->getId() == id;
}

string ProFCFS::getType()
{
	return "ProFCFS";
}


void ProFCFS::PrintRDY() 
{
		Plist.PrintListid();
}






