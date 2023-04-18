#include "../Headers/Schedular.h"

Schedular::Schedular()
{
}

void Schedular::load()
{
	inputfile.open("inputFile.txt"); // it can use function from UI to enter file name and then i should make check if file name exist or not 
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
		arr[i] = new Process(AT, PID, CT);
		/*for (int i = 0; i < NIO; i++)
		{
			arr[i].;
		}*/
	}
	inputfile.close();
}

Schedular::~Schedular()
{
	for (int i = 0; i < 5; i++) {
		delete arr[i]; // Deallocate the memory for each Process object
	}
	delete[] arr; // Deallocate the memory for the array of pointers
}
