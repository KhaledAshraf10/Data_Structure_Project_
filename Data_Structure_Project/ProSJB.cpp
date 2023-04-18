//
//#include "../Headers/ProSJB.h"
//#include "../Headers/Schedular.h"
//
//ProSJB::ProSJB(Schedular* p) :processor(p)
//{
//
//	timer = 0;
//	RUNLIST = nullptr;
//	
//}
//
//
//ProSJB::~ProSJB()
//{}
//
//
//int ProSJB::gettimer() const
//{
//	return timer;
//
//}
//
//
//void ProSJB::ScheduleAlgo()
//{
//
//
//	if (RUNLIST == nullptr) {
//
//		Plist.dequeue(RUNLIST);
//
//		dectimer(RUNLIST);
//
//	}
//
//	//else if (RUNLIST->getremainingtime() ==0) {
//
//	//	//Ps->move to TRM(RUNLIST);
//
//	//}
//	srand(time(0));
//	int x = 1 + (rand() % 100);
//
//	//if (counter <= timeslice) {
////          srand(time(0));
//	  //	int x = 1 + (rand() % 100);
//
//	  //	RUNLIST->decremainingtime();
//
//	  //	//counter++;
//
//
//
//	if (1 <= x && x <= 15)
//
//	{
//
//		//Ps->move to BLK(RUNLIST)		
//		RUNLIST = nullptr;
//
//	}
//	else if (20 <= x && x <= 30) {
//
//		Plist.enqueue(RUNLIST);
//		inctimer(RUNLIST);
//		RUNLIST = nullptr;
//	
//
//	}
//	else if (50 <= x && x <= 60) {
//
//
//		//pS->//move to TRM;
//		RUNLIST = nullptr;
//
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	//else if (RUNLIST->getremainingtime() == 0) {
//
//	//	//Ps->move to TRM(RUNLIST);
//	//	RUNLIST = nullptr;
//
//	//}
//
//
//
//
//}
//
//void ProSJB::inctimer(Process* p)
//{
//
//	timer += (p->getremainingtime());
//	nop++;
//
//}
//
//void ProSJB::dectimer(Process* p)
//{
//	int x = p->getremainingtime();
//	timer -= (p->getremainingtime());
//	nop--;
//
//}
//
//void ProSJB::add_process(Process* p) {
//
//	inctimer(p);
//	Plist.enqueue(p);
//
//
//
//}
//
//
//bool ProSJB::PrintRDY() {
//	Plist.Printlistid();
//	return true;
//
//
//}
//
//
//
//
//
//bool ProSJB::PrintRUN() {
//	if (RUNLIST != nullptr) {
//		cout << RUNLIST->getId();
//		return true;
//
//	}
//	else {
//		return false;
//	}
//
//
//}
//
