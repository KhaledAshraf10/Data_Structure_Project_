#include "../Headers/Schedular.h"
#include "../Headers/proFCFS.h"
#include "../Headers/ProRoundRobin.h"
#include <chrono>
#include <thread> 


Schedular::Schedular()
{ 
	//NEW = new Process * [nProcess];

	load();
	TimeStep = 0;
	arr_Processor = new processor * [nFCFS + nSJF + nRR];
	P = new ProFCFS(this,5);
	me = this;
	
	
	
}

void Schedular::load()
{
	inputfile.open("File_1.txt"); // it can use function from UI to enter file name and then i should make check if file name exist or not 
	inputfile >> nFCFS >> nSJF >> nRR >> TS >> RTF >> MaxW >> STL >> FP >> nProcess;
	

	/*
	nFCFS , nSJF, nRR stand for number of processor for each type
	TS => time slice for RR
	RTF =>
	MaxW =>
	STL => check stealing action every STL
	FP => fork probability
	nProcess => number of process
	*/
	//sss



	
	
	

	for (int i = 0; i < nProcess ; i++)
	{	
		int AT = 0, PID = 0, CT = 0, NIO = 0, IOR = 0, IOD = 0;
		inputfile >> AT >> PID >> CT >> NIO;
		
		// if i put Process id in New list or process 

		Queue<IO_R_D*>* arr = new Queue<IO_R_D*>;
		Process* P = new Process(AT, PID, CT,*arr); // it should contain NIO
		for (int j = 0; j < NIO; j++)
		{
			IO_R_D* struct1 = new IO_R_D;
			inputfile >> IOR >> IOD;
			struct1->IO_R = IOR;
			struct1->IO_D = IOD;
			P->Add_To_IOList(struct1);
		}
		

		NEW.enqueue(P);
		
	}





	
	/*inputfile.close();*/
	
	
}

void Schedular::Add_To_NEW()
{
	/*for (int i = 0; i < nProcess; i++)
	{
		inputfile >> AT >> PID >> CT >> NIO;
		NEW[i] = new Process(AT, PID, CT);
		for (int i = 0; i < NIO; i++)
		{
			char garbage;
			int IO_R, IO_D;
			inputfile >> garbage >> IO_R >> garbage >> IO_D >> garbage >> garbage;
			NEW[i]->Add_To_IOList(IO_R, IO_D);
		}
	}*/
}

void Schedular::Add_To_arr_Processor()
{
	
	for (int i = 0; i < nFCFS; i++)
	{
		arr_Processor[i] = new ProFCFS(this,5);
		
	}

	for (int i = nFCFS; i < nSJF+nFCFS; i++)
	{
		arr_Processor[i] = new ProFCFS(this,5);
	}
	for (int i = nSJF + nFCFS; i < nSJF + nFCFS + nRR; i++)

	{
		arr_Processor[i] = new ProRoundRobin(this,5,5,5);
	}
}

void Schedular::Phase_1_Simulation()
{
	static int q;
	static bool executed = false;  

	if (!executed)
	{
		
		cout << "Choose the mode : 1,2 or 3 ";
		cin >> q;
		executed = true;  
	}

	else
	{
		Process* P;
		int ArrivalTime;
		int counter = 0;
		if (TimeStep == 1) {

			for (int i = 0; i < nProcess; i++)
			{

				NEW.dequeue(P);// get arrival time of first process that should sort ascendingly
				ArrivalTime = P->getArrivalTime();

				//while (CheckTimeStep(ArrivalTime) == 0) 
				//{
				//	TimeStep++; // increment till time step be equal arrival time
				//}

				if (ArrivalTime == TimeStep) {          //should be changed to allow all precsses to get scheduled
					processor* shortest = PicksShortRDY();
					shortest->add_process(P);        //!! processes should be deleted from new 


					/*arr_Processor[(ArrivalTime-1)%11]->setrecent();*/
					counter++;// for e.x it will add first process to first processor 
				}
			}
		}
		for (int j = 0;j < nFCFS+nRR+nSJF; j++)

		{
			Process* P;
			int ArrivalTime;
			int counter = 0;
			if (TimeStep == 1) {

				for (int i = 0; i < nProcess; i++)
				{

					NEW.dequeue(P);// get arrival time of first process that should sort ascendingly
					ArrivalTime = P->getArrivalTime();

					//while (CheckTimeStep(ArrivalTime) == 0) 
					//{
					//	TimeStep++; // increment till time step be equal arrival time
					//}

					if (ArrivalTime == TimeStep) {          //should be changed to allow all precsses to get scheduled
						processor* shortest = PicksShortRDY();
						shortest->add_process(P);        //!! processes should be deleted from new 


						/*arr_Processor[(ArrivalTime-1)%11]->setrecent();*/
						counter++;// for e.x it will add first process to first processor 
					}
				}
			}
			for (int j = 0; j < nFCFS + nRR + nSJF; j++)
			{


				arr_Processor[j]->ScheduleAlgo(); // it excute each processor to run 
				/*	if (arr_Processor[j]->isrecent()) { arr_Processor[j]->unsetrecent(); }*/
			}
			/*userUI.printProcessIDs(this);*/
			userUI.FirstMode();
			TimeStep++;
		}
	}
	if (q == 2) {
		while (true) {
			if (TimeStep == 0)
			{
				/*load();*/
				Add_To_NEW();
				Add_To_arr_Processor();
				TimeStep++;

				/*userUI.printProcessIDs(this);*/
				userUI.FirstMode();
				std::this_thread::sleep_for(std::chrono::seconds(1));

			}
			else
			{
				Process* P;
				int ArrivalTime;
				int counter = 0;
				if (TimeStep == 1) {

					for (int i = 0; i < nProcess; i++)
					{

						NEW.dequeue(P);// get arrival time of first process that should sort ascendingly
						ArrivalTime = P->getArrivalTime();

						//while (CheckTimeStep(ArrivalTime) == 0) 
						//{
						//	TimeStep++; // increment till time step be equal arrival time
						//}

						if (ArrivalTime == TimeStep) {          //should be changed to allow all precsses to get scheduled
							processor* shortest = PicksShortRDY();
							shortest->add_process(P);        //!! processes should be deleted from new 


							/*arr_Processor[(ArrivalTime-1)%11]->setrecent();*/
							counter++;// for e.x it will add first process to first processor 
						}
					}
				}
				for (int j = 0; j < nFCFS + nRR + nSJF; j++)
				{


					arr_Processor[j]->ScheduleAlgo(); // it excute each processor to run 
					/*	if (arr_Processor[j]->isrecent()) { arr_Processor[j]->unsetrecent(); }*/
				}
				/*userUI.printProcessIDs(this);*/
				userUI.FirstMode();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				TimeStep++;
			}


		}
	}
}
void Schedular::Add_To_BLK(Process* n)
{

	BLK.enqueue(n);
}
void Schedular::Add_To_TRM(Process* n)
{
	TRM.enqueue(n);
}

processor** Schedular::getProcessorList()
{
	return arr_Processor;
}


Queue<Process*> Schedular::getBLKList()
{
	return BLK;
}
//LinkedList<Process*> Schedular::getTRMList()
//{
//	return TRM;
//}
Queue<Process*> Schedular::getTRMList()
{
	return TRM;
}

void Schedular::Check_Every_TimeStep()
{
}

bool Schedular::CheckTimeStep(int ArrivalTime)
{
	if (ArrivalTime == TimeStep) return true;
	else return false;

} 

int Schedular::getnFCFS()
{
	return nFCFS;
}

int Schedular::getnSJF()
{	
	return nSJF;
}

int Schedular::getnRR()
{
	return nRR;
}

int Schedular::getTimeStep()
{
	return TimeStep;
}


void Schedular::SigKill(Process* p) 
{
	
	for (int i = 0; i < nFCFS; i++) {
		processor* processorPtr = arr_Processor[i];
		Process* runList = processorPtr->getRUNList();

		
		for (int j = 0; j < sizeof(runList); j++) {
			if (runList[j].getId() == p->getId()) {
				
				Add_To_TRM(p);

				
				return;
			}
		}
	}
}




//
//void Schedular::IncreamentTimeStep()
//{
//	srand(time(NULL)); // seed the random number generator with the current time
//	int randomNumber = rand() % 100 + 1; // generate a random number between 1 to 100
//	TimeStep++;
//	if (randomNumber < 10)
//	{
//		Process* temp;
//
//		BLK.dequeue(temp);
//		arr_Processor[1]->add_process(temp); //BLK.Dequeu() should return process
//		
//	}
//}
processor* Schedular::PicksShortRDY()
{
	processor* ShortRDY = arr_Processor[0];
	for (int i = 1; i < nFCFS + nSJF + nRR; i++)
	{
		if (arr_Processor[i-1]->gettimer() > arr_Processor[i]->gettimer())
		{
			ShortRDY = arr_Processor[i];
		}
	}
	return ShortRDY;

}
//void Schedular::BLKToRDY()
//{
//	Process* p1 = nullptr;
//	
//	BLK.peek(p1);
//	if (p1->getIO_RD().getValue1At(0) == TimeStep) // it should not be that it should get IO_R if its equal time step it should go to shortes rdy list
//	{
//		PicksShortRDY()->add_process(p1);
//		BLK.dequeue(p1);
//		
//	}
//}

void Schedular::Fork(Process* p)
{
	PicksShortRDY()->add_process(p);

}
void Schedular::BLKToRDY()
{
	Process * p1 = nullptr;
	IO_R_D * s;
	BLK.peek(p1);
	p1->peekIO(s);
	
	if (s->IO_R + s->IO_D == TimeStep)  // when the sum of IOR and IOD equal time step it mean that process wait in blk 
	{
		PicksShortRDY()->add_process(p1);
		BLK.dequeue(p1);
		p1->DequeueIO(s);
		
	}
}







Schedular::~Schedular()
{
	//for (int i = 0; i < 5; i++) {
	//	delete NEW[i]; // Deallocate the memory for each Process object
	//	delete arr_Processor[i];
	//}
	//delete[] NEW; // Deallocate the memory for the array of pointers
	//delete[]arr_Processor;
}

void Schedular::LoadSigKillList()
{	 
	while (inputfile)
	{
		int ID, SKT; // id of process and signal kill time
		inputfile >> ID >> SKT;
		MyStruct structt{ ID,SKT };
		P->EnqueuEelements(structt);
	}
}

//void Schedular::SigKill(Queue<MyStruct> KillSigList, Schedular& a)
//{
//	MyStruct s1,tempp;
//	KillSigList.peek(s1);
//	if (s1.KillTime != a.TimeStep)
//	{
//		return;
//	}
//	while (KillSigList.peek(s1))
//	{
//		if (s1.KillTime == a.TimeStep)
//		{
//			for (int i = 0; i < a.nFCFS; i++) // ana mout2kd en list of processor awl hagat feha hya fcfs
//			{
//				if (a.arr_Processor[i]->IsInRDY(s1.ID) || a.arr_Processor[i]->IsInRUN(s1.ID))
//				{
//					//arr_Processor[i]->KillProcess(s1.ID);
//					KillSigList.dequeue(tempp);
//				}
//			}
//		}
//		
//	}
//}

void Schedular::KillOrphanProcesses()
{
	for (int i = 0; i < nFCFS; i++) {
		processor* currentProcessor = arr_Processor[i];
		Process* runningProcess = currentProcessor->getRUNList();

		// Check if the running process is orphaned
		if (runningProcess != nullptr && runningProcess->getparentid() != -1) {
			int parentID = runningProcess->getparentid();


			bool isParentTerminated = false;

			if (TRM.isProcessInQueue(parentID) == true) {
				 isParentTerminated = true;
			}

			// Kill the orphan process and move it to TRM list
			if (isParentTerminated) {
				Add_To_TRM(runningProcess);
				currentProcessor->setRUNNull();

				//arr_Processor[i]->setRUNlist(); // Clear the RUNLIST by setting it to nullptr
			}
		}

			for (int j = 0 ; j < currentProcessor->getSizeOfRDYList(); j++)
			if (currentProcessor->getRDYList().getProcessByPosition(j) != nullptr && currentProcessor->getRDYList().getProcessByPosition(j)->getparentid() != -1)
			{
				int parentID = currentProcessor->getRDYList().getProcessByPosition(j)->getparentid();
				bool isParentTerminated = false;
				if (TRM.isProcessInQueue(parentID) == true) {
					 isParentTerminated = true;
				}

				// Kill the orphan process and move it to TRM list
				if (isParentTerminated) {
					Add_To_TRM(currentProcessor->getRDYList().getProcessByPosition(j));
					//check
					currentProcessor->deleteNode(currentProcessor->getRDYList().getProcessByPosition(j));
					currentProcessor->decNoop();
					 // Clear the RUNLIST by setting it to nullptr
				}

			}
		
		
		
		}
	}

int Schedular::getnprocess() {
	return nProcess;
}

