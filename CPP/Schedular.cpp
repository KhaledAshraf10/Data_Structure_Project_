#include "../Headers/Schedular.h"
#include "../Headers/proFCFS.h"
#include "../Headers/ProRoundRobin.h"


Schedular::Schedular()
{
	load();
	Process** NEW = new Process * [nProcess];
	processor** arr_Processor = new processor * [nFCFS+nSJF+nRR];
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
	
	inputfile.close();
	
	
}

void Schedular::Add_To_NEW()
{
	for (int i = 0; i < nProcess; i++)
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
	}
}

void Schedular::Add_To_arr_Processor()
{
	for (int i = 0; i < nFCFS; i++)
	{
		arr_Processor[i] = new ProFCFS(this);
		
	}
	//for (int i = 0; i < nSJF; i++)
	//{
	//	arr_Processor[i] = new ProFCFS(this);
	//}
	for (int i = 0; i < nRR; i++)
	{
		arr_Processor[i] = new ProRoundRobin(this);
	}
}

void Schedular::Phase_1_Simulation()
{
	if (TimeStep == 0)
	{
		load();
		Add_To_NEW();
		Add_To_arr_Processor();
		TimeStep++;
		
	}
	else
	{
		int counter = 0;
		for (int i = 0; i < nProcess; i++)
		{
			int ArrivalTime = NEW[i]->getArrivalTime();
			if (ArrivalTime == TimeStep)
			{
				arr_Processor[counter]->add_process(NEW[i]);
				counter++;
			}
		}
		TimeStep++;
		for (int j = 0;j < nFCFS+nRR/*+nSJF*/; j++)
		{
			arr_Processor[j]->ScheduleAlgo();
		}
		
	}
}
void Schedular::Add_To_BLK(Process* n)
{
	BLK.InsertEnd(n);
}
void Schedular::Add_To_TRM(Process* n)
{
	TRM.InsertEnd(n);
}

processor** Schedular::getProcessorList()
{
	return arr_Processor;
}
LinkedList<Process*> Schedular::getBLKList()
{
	return BLK;
}
LinkedList<Process*> Schedular::getTRMList()
{
	return TRM;
}

Schedular::~Schedular()
{
	for (int i = 0; i < 5; i++) {
		delete NEW[i]; // Deallocate the memory for each Process object
		delete arr_Processor[i];
	}
	delete[] NEW; // Deallocate the memory for the array of pointers
	delete[]arr_Processor;
}
