#include "../Headers/Schedular.h"

Schedular::Schedular()
{
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
	for (int i = 0; i < nProcess; i++)
	{
		inputfile >> AT >> PID >> CT >> NIO;
		arr_Process[i] = new Process(AT, PID, CT);
		for (int i = 0; i < NIO; i++)
		{
			char garbage;
			int IO_R, IO_D;
			inputfile >> garbage >> IO_R >> garbage >> IO_D >> garbage >> garbage;
			arr_Process[i]->Add_To_IOList(IO_R, IO_D);
		}
	}
	inputfile.close();
	for (int i = 0; i < nFCFS; i++)
	{
		arr_Processor[i] = new ProFCFS(this);
	}
	inputfile.close();
}

Schedular::~Schedular()
{
	for (int i = 0; i < 5; i++) {
		delete arr_Process[i]; // Deallocate the memory for each Process object
	}
	delete[] arr_Process; // Deallocate the memory for the array of pointers
}
