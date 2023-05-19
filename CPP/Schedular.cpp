#include "../Headers/Schedular.h"
#include "../Headers/proFCFS.h"
#include "../Headers/ProRoundRobin.h"



Schedular::Schedular()
{ 
	//NEW = new Process * [nProcess];

	load();
	TimeStep = 0;
	arr_Processor = new processor * [nFCFS + nSJF + nRR];

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
		
		int AT=0, PID=0, CT=0, NIO=0;
		inputfile >> AT >> PID >> CT >> NIO;

		// if i put Process id in New list or process 
		Process* P = new Process(AT, PID, CT); // it should contain NIO
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
		arr_Processor[i] = new ProFCFS(this);
		
	}

	for (int i = nFCFS; i < nSJF+nFCFS; i++)
	{
		arr_Processor[i] = new ProFCFS(this);
	}
	for (int i = nSJF + nFCFS; i < nSJF + nFCFS + nRR; i++)

	{
		arr_Processor[i] = new ProRoundRobin(this);
	}
}

void Schedular::Phase_1_Simulation()
{
	
	if (TimeStep == 0)
	{
		/*load();*/
		Add_To_NEW();
		Add_To_arr_Processor();
		TimeStep++;
		
		/*userUI.printProcessIDs(this);*/
		userUI.printProcessIDs();
		
		
	}
	else
	{
		Process* P;
		int ArrivalTime;
		int counter = 0;
		for (int i = 0; i < nProcess; i++)
		{
			NEW.dequeue(P);// get arrival time of first process that should sort ascendingly
			ArrivalTime = P->getArrivalTime();
			 
			//while (CheckTimeStep(ArrivalTime) == 0) 
			//{
			//	TimeStep++; // increment till time step be equal arrival time
			//}
			 if (ArrivalTime == TimeStep) {          //should be changed to allow all precsses to get scheduled
				 arr_Processor[(ArrivalTime-1)%11]->add_process(P);                                                        //!! processes should be deleted from new 
				 /*arr_Processor[(ArrivalTime-1)%11]->setrecent();*/
				 counter++;// for e.x it will add first process to first processor 
			 }
		}
		
		for (int j = 0;j < nFCFS+nRR+nSJF; j++)
		{
		 
			
			arr_Processor[j]->ScheduleAlgo(); // it excute each processor to run 
		/*	if (arr_Processor[j]->isrecent()) { arr_Processor[j]->unsetrecent(); }*/
		}
		/*userUI.printProcessIDs(this);*/
		userUI.printProcessIDs(); 
		TimeStep++;
	}
	
}
void Schedular::Add_To_BLK(Process* n)
{

	BLK1.enqueue(n);
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
	return BLK1;
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


void Schedular::IncreamentTimeStep()
{
	srand(time(NULL)); // seed the random number generator with the current time
	int randomNumber = rand() % 100 + 1; // generate a random number between 1 to 100
	TimeStep++;
	if (randomNumber < 10)
	{
		Process* temp;

		BLK1.dequeue(temp);
		arr_Processor[1]->add_process(temp); //BLK.Dequeu() should return process
		
	}
}
auto Schedular::PicksShortRDY()
{
	auto* ShortRDY = arr_Processor[0];
	for (int i = 0; i < nFCFS + nSJF + nRR; i++)
	{
		if (arr_Processor[i]->gettimer() > arr_Processor[i + 1]->gettimer())
		{
			ShortRDY = arr_Processor[i + 1];
		}
	}
	return ShortRDY;
}
void Schedular::Add_To_RDY()
{
	

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
