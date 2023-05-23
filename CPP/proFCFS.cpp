#pragma once
#include "../Headers/proFCFS.h"
#include "../Headers/schedular.h"
#include <time.h>

Queue<MyStruct> ProFCFS::KillSigList;
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
		if (overheatingcounter == pS->getOverHeatT()) {
			this->unsetIsHeated();
			return;
		}
		this->overheatingcounter++;
		return;
	}
	else {
		srand(time(0));
		int x = 1 + (rand() % 100);

		if (x < 0) {
			this->setIsHeated();
			for (int i = 0; i < Plist.size(); i++) {
				Process* temp;
				Plist.getbeg(temp);
				pS->GoToShortestRDY(temp);



			}
			if (RUNLIST) {
				pS->GoToShortestRDY(RUNLIST);
				RUNLIST = nullptr;
			}
			return;

		}


	}





	if (RUNLIST == nullptr) {
		if (Plist.size() == 0) { return; }
		else {
			Plist.getbeg(RUNLIST);
			dectimer(RUNLIST);

			noP--;

		}
	}
	else
		if (RUNLIST->getremainingtime() != 0) {


			int totalexecutiontime = RUNLIST->getCpuTime() - RUNLIST->getremainingtime();
			bool flag = false;
			IO_R_D* temp = nullptr;
			if (!RUNLIST->IOIsEmpty()) {
				RUNLIST->peekIO(temp);
				if (totalexecutiontime == temp->IO_R) {
					pS->Add_To_BLK(RUNLIST);
					RUNLIST = nullptr;
					return;





				}
			}
			
				RUNLIST->decremainingtime();   //actual processing
				srand(time(0));
				int F = 1 + (rand() % 100);  //forkprobability
				//if (F <= pS->getFP())
				//	/*this->forkingrequest(RUNLIST);*/
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
					KillSigList.dequeue(tempp);//arr_Processor[i]->KillProcess(s1.ID);
					pS->Add_To_TRM(arr_Processor[i]->getRUNList());
					arr_Processor[i]->setRUNNull();
					return;
				}
				else if (arr_Processor[i]->IsInRDY(s1.ID) && arr_Processor[i]->getType() == "ProFCFS")
				{

					KillSigList.dequeue(tempp);
					Process* s = arr_Processor[i]->getRdyProcess(s1.ID);
					arr_Processor[i]->dectimer(s);
					pS->Add_To_TRM(s);
					
					arr_Processor[i]->deleteNode(s);
					arr_Processor[i]->decNoop();
					return;
					
				}

			}



		}
	}

}
void ProFCFS::PrintRDY() 
{
	Plist.PrintListid();
}
void ProFCFS::EnqueuEelements(const MyStruct & element)
{
	KillSigList.enqueue(element);
	}



Process* ProFCFS::getProcessWithValidParent()
{
	Node<Process*>* current = Plist.getHead();

	while (current != nullptr) {
		Process* process = current->getItem();
		int parentID = process->getparentid();

		if (parentID != -1) {
			return process;
		}
	}
}
bool ProFCFS::IsInRDY(int id)
{
	return Plist.Check(id);
}
Process * ProFCFS::getRdyProcess(int id)
{
	
	return Plist.getRdyProcessFL(id);
}

void ProFCFS::setRUNNull()
{
	RUNLIST = nullptr;
}

void ProFCFS::deleteNode(Process* p)
{
	Plist.DeleteNode(p);
}

void ProFCFS::decNoop()
{
	noP--;
}

void ProFCFS::incrementBusyTime()
{
	Busytime = Busytime + 1;
}

void ProFCFS::incrementIDLETime()
{
	IDLEtime = IDLEtime + 1;
}

int ProFCFS::getBusyTime()
{
	return Busytime;
}

int ProFCFS::getIDLETime()
{
	return IDLEtime;
}

bool ProFCFS::IsInRUN(int id)
{
	if (RUNLIST == nullptr)
	{
		return false;
	}
	else
	{
		return RUNLIST->getId() == id;
	}
	
}

string ProFCFS::getType()
{
return "ProFCFS";
}


	/*	current = current->getNext();
	}

	return nullptr;
}*/
int ProFCFS::getSizeOfRDYList()
{
	int count = 0;
	Node<Process*>* current = Plist.getHead();
	while (current != nullptr) {
		count++;
		current = current->getNext();
	}
	return count;
}
LinkedList<Process*> ProFCFS::getRDYList() {
	return Plist;
}