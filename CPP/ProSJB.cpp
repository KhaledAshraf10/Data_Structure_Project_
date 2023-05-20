
#include "../Headers/ProSJB.h"
#include "../Headers/Schedular.h"

ProSJB::ProSJB(Schedular* p) :processor(p)
{

	timer = 0;
	RUNLIST = nullptr;
	
}


ProSJB::~ProSJB()
{}


int ProSJB::gettimer() const
{
	return timer;

}


void ProSJB::ScheduleAlgo()
{


	if (RUNLIST == nullptr) {
		if (Plist.count() == 0) { return; }

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



	if (1 <= x && x <= 15)

	{

		pS->Add_To_BLK(RUNLIST);
		RUNLIST = nullptr;

	}
	else if (20 <= x && x <= 30) {

		Plist.enqueueS(RUNLIST);
		inctimer(RUNLIST);
		RUNLIST = nullptr;
	

	}
	else if (50 <= x && x <= 60) {


		pS->Add_To_TRM(RUNLIST);
		RUNLIST = nullptr;

	}














	else if (RUNLIST->getremainingtime() == 0) {

		pS->Add_To_TRM(RUNLIST);
		RUNLIST = nullptr;

	}




}

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

	inctimer(p);
	Plist.enqueueS(p);



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
Process* ProSJB::getRUNList()
{
	return RUNLIST;

}

