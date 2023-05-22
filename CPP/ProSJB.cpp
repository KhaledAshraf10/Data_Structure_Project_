
#include "../Headers/ProSJB.h"
#include "../Headers/Schedular.h"

ProSJB::ProSJB(Schedular* p,int overheatT) :processor(p,overheatT)
{

	timer = 0;
	RUNLIST = nullptr;
	nop = 0;
	
}


ProSJB::~ProSJB()
{}


int ProSJB::gettimer() const
{
	return timer;

}


void ProSJB::ScheduleAlgo()
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




			Process* temp;
			while (Plist.dequeue(temp)) {
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
		if (Plist.count() == 0) { return; }

		Plist.dequeue(RUNLIST);

		dectimer(RUNLIST);

		nop--;
		return;

	}


	else if (RUNLIST->getremainingtime() == 0) {






		pS->Add_To_TRM(RUNLIST);
		RUNLIST = nullptr;
		return;

	}

	else if (RUNLIST->getremainingtime() != 0) {


		int totalexecutiontime = RUNLIST->getCpuTime() - RUNLIST->getremainingtime();

		IO_R_D* temp = nullptr;
		if (!RUNLIST->IOIsEmpty()) {
			RUNLIST->peekIO(temp);
			if (totalexecutiontime == temp->IO_R) {
				pS->Add_To_BLK(RUNLIST);
				RUNLIST = nullptr;
				return;





			}
		}

		RUNLIST->decremainingtime();
		return;


	}
}

	/*else*/






































void ProSJB::inctimer(Process* p)
{

	timer += (p->getremainingtime());
	nop++;

}

void ProSJB::dectimer(Process* p)
{
	int x = p->getremainingtime();
	timer -= (p->getremainingtime());
	nop--;

}

void ProSJB::add_process(Process* p) {
Plist.enqueueS(p);
	inctimer(p);
	
	nop++;



}


void ProSJB::PrintRDY() {
	Plist.Printlistid();
	


}





bool ProSJB::PrintRUN() {
	if (RUNLIST != nullptr) {
		cout << RUNLIST->getId();
		return true;

	}
	else {
		return false;
	}


}


bool ProSJB::IsInRDY(int id)
{
	return false;
}

bool ProSJB::IsInRUN(int id)
{
	return false;
}

string ProSJB::getType()
{
	return "ProSJB";
}

Process* ProSJB::getRdyProcess(int id)
{
	return nullptr;
}

void ProSJB::setRUNNull()
{
	RUNLIST = nullptr;
}
void ProSJB::deleteNode(Process* p)
{
	return;
}
void ProSJB::decNoop()
{
	nop--;
}


int ProSJB::getSizeOfRDYList()
{
	return 0;
}
LinkedList<Process*> ProSJB::getRDYList()
{
	return LinkedList<Process*>();
}

void ProSJB::incrementBusyTime()
{
	Busytime = Busytime + 1;
}

void ProSJB::incrementIDLETime()
{
	IDLEtime = IDLEtime + 1;
}

int ProSJB::getBusyTime()
{
	return Busytime;
}

int ProSJB::getIDLETime()
{
	return IDLEtime;
}


Process* ProSJB::getRUNList()
{
	return RUNLIST;

}

