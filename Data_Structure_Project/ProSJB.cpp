
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


	if (RUNLIST == nullptr) {
		if (Plist.count() == 0) { return; }

		Plist.dequeue(RUNLIST);

		dectimer(RUNLIST);

		nop--;
		return;

	}

	else if (RUNLIST->getremainingtime() ==0) {





		pS->Add_To_TRM(RUNLIST);
		RUNLIST == nullptr;
		return;

	}

	else if (RUNLIST->getremainingtime() != 0) {

	//int totalexecutiontime = RUNLIST->getCpuTime() - RUNLIST->getremainingtime();
		
		//for (int i = 0; i < sizeof(RUNLIST->getIO_RD())/sizeof(Node2); i++) {               //na2sa l7d get IO matt3ml!!
		//	if (totalexecutiontime == arrayIO[i]) {
		// arrayIO[i]=0;
		//		pS->Add_To_BLK(RUNLIST);
		//		RUNLIST=nullptr
		//		return;


		//	}
		//		
		//}
	/*else*/
		RUNLIST->decremainingtime();
		return;






	}







	//if (counter <= timeslice) {
//          srand(time(0));
	  //	int x = 1 + (rand() % 100);

	  //	RUNLIST->decremainingtime();

	  	//counter++;



	//if (1 <= x && x <= 15)

	//{

	//	pS->Add_To_BLK(RUNLIST);
	//	RUNLIST = nullptr;

	//}
	//else if (20 <= x && x <= 30) {

	//	Plist.enqueueS(RUNLIST);
	//	inctimer(RUNLIST);
	//	RUNLIST = nullptr;
	//

	//}
	//else if (50 <= x && x <= 60) {


	//	pS->Add_To_TRM(RUNLIST);
	//	RUNLIST = nullptr;

	//}

















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

