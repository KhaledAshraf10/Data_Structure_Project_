#pragma once
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"
#include <time.h>

<<<<<<< HEAD

ProFCFS::ProFCFS(Schedular* p,int overheatT) :processor(p,overheatT)
=======
Queue<MyStruct> ProFCFS::KillSigList;
ProFCFS::ProFCFS(Schedular* p) :processor(p)
>>>>>>> 30e0de58619aa1c2afcc98d42ec784b945680fa4
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
		if (Plist.size() == 0) {
		if (this->IsHeated())
			overheatingcounter++;
		 return; 
		}         
		  
	
		if (!this->IsHeated()) {
			Plist.getbeg(RUNLIST);
			dectimer(RUNLIST);
<<<<<<< Updated upstream
<<<<<<< HEAD
		if (Plist.size() == 0) {
		if (this->IsHeated())
			overheatingcounter++;
		 return; 
		}         
		  
	
		if (!this->IsHeated()) {
			Plist.getbeg(RUNLIST);
			dectimer(RUNLIST);
=======
		if (noP == 0) { return; }
>>>>>>> master
=======
>>>>>>> Stashed changes

			noP--;
			return;
		}
		else                               //overheating situation for RUNLIST empty and RDY list occupied
		{                     
			for (int i = 0; i < noP; i++) {
				Process* temp;
				Plist.getbeg(temp);
				pS->Add_To_BLK(temp);

			}
			noP = 0;
			overheatingcounter++;
			this->timer = 0;
			return;

		}
		  

	}
	else if (this->IsHeated()) {
		pS->Add_To_BLK(RUNLIST);
		RUNLIST = nullptr;

		for (int i = 0; i < noP; i++) {
			Process* temp;
			Plist.getbeg(temp);
			pS->Add_To_BLK(temp);

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






