
#include "../Headers/ProRoundRobin.h"
#include "../Headers/Schedular.h"






//sdfa

 ProRoundRobin::ProRoundRobin(Schedular* p,int overheatT,int rtf,int slice) :processor(p,overheatT)

{
	 nop = 0;
	 counter=0;
	timer = 0;
	RUNLIST = nullptr;
	timeslice = slice;
	this->RTF = rtf;
}


ProRoundRobin::~ProRoundRobin()
{}


int ProRoundRobin::gettimer() const
{
	return timer;

}


void ProRoundRobin::ScheduleAlgo()
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
		counter == 0; //to maintain the timeslice for next process
		return;
		

	}
	else if (RUNLIST->getremainingtime() != 0) {
		//int totalexecutiontime = RUNLIST->getCpuTime() - RUNLIST->getremainingtime();
		//bool flag = false;
		//for (int i = 0; i < sizeof(RUNLIST->getIO_RD())/sizeof(Node2); i++) {               //na2sa l7d get IO matt3ml!!
		//	if (totalexecutiontime == arrayIO[i]) {
		//		pS->Add_To_BLK(RUNLIST);
		//		RUNLIST=nullptr
		// counter=0; 
		//	return;

		//	}
		//		
		//}
		if (counter == timeslice) {
			Plist.enqueue(RUNLIST);

			
			this->inctimer(RUNLIST);   //includes nop++

			RUNLIST = nullptr;
			counter = 0;
			return;





		}




		RUNLIST->decremainingtime(); //actual processing
		counter++;
		return;



	}

	


			

		//	if (1 <= x&&x <= 15)

		//	{

		//		pS->Add_To_BLK(RUNLIST);
		//		RUNLIST = nullptr;

		//	}
		//	else if (20 <= x&&x <= 30) {

		//		Plist.enqueue(RUNLIST);
		//		inctimer(RUNLIST);
		//		RUNLIST = nullptr;
		//		counter == 0;

		//	}
		//	else if (50 <= x&&x <= 60) {


		//		pS->Add_To_TRM(RUNLIST);
		//		RUNLIST = nullptr;

		//	}
		//	else if(counter>=timeslice)
		//	{
		//		Plist.enqueue(RUNLIST);
		//		inctimer(RUNLIST);
		//		RUNLIST = nullptr;
		//		counter == 0;
		//	}
		//else if (RUNLIST->getremainingtime() == 0) {

		//		pS->Add_To_TRM(RUNLIST);
		//	RUNLIST = nullptr;

		//}




}

void ProRoundRobin::inctimer(Process* p)
{

	timer+=(p->getremainingtime());
	nop++;

}

void ProRoundRobin::dectimer(Process *p)
{
	int x = p->getremainingtime();
	timer -= (p->getremainingtime());
	nop--;

}

void ProRoundRobin::add_process(Process* p) {

	inctimer(p);
	Plist.enqueue(p);
	nop++;



}

Process* ProRoundRobin::getRUNList()
{
	return RUNLIST;
}


void ProRoundRobin::PrintRDY() {
	Plist.Printlistid();
	


}





bool ProRoundRobin::PrintRUN() {
	if (RUNLIST != nullptr) {
		cout << RUNLIST->getId();
		return true;

	}
	else {
		return false;
	}


}

bool ProRoundRobin::IsInRDY(int id)
{
	return false;
}

bool ProRoundRobin::IsInRUN(int id)
{
	return false;
}

string ProRoundRobin::getType()
{
	return "ProRoundRobin";
}

Process* ProRoundRobin::getRdyProcess(int id)
{
	return nullptr;
}

int ProRoundRobin::getSizeOfRDYList()
{
	return 0;
}

LinkedList<Process*> ProRoundRobin::getRDYList()
{
	return LinkedList<Process*>();
}
