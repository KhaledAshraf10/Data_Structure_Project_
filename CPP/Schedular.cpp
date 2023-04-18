#include "../Headers/Schedular.h"

Schedular::Schedular()
{
}

void Schedular::load()
{
	inputfile.open("inputFile.txt"); // it can use function from UI to enter file name and then i should make check if file name exist or not 
	int nFCFS, nSJF, nRR, TS, RTF, MaxW, STL, FP, nProcess/*,process dataType,kill datatype*/;
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
