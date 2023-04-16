#pragma once
#include "LinkedList.h"
#include <fstream>
class Schedular
{
private:
	LinkedList<int>* processorList; // int must replace by proessor data type from  sou3dy 
	LinkedList<int>* processList;	// int must replace by process data type from  abstar
	ifstream inputfile;
	
public:
	Schedular();
	void load();
	void ShortRDY(); // should return Shortest rdy queue 
	void LongRDY(); // should return Longest rdy queue , will used in work steal
	int CalcCT(); // should take rdy queu and claculate CT for all process in it 
	void RRmSJF(); // check mirgration bet RR & SJF using RTF, if proccess in RR has remaining time less than RTF => mirgrate to SJF
	void FCFSmRR(); // check mirgration bet FCFS & RR using MaxW, if proccess in FCFS has waiting time greater than MaxW => mirgrate to RR
	bool CalcSL(); // check for steal limit > 40, using SL = (LongRDY().ClacCT()-ShortRDY().ClacCT())/LongRDY().ClacCT()
	void STLA(); // stealing action should done every STL, 
	void SigKill(); //take list of signal kill that is sorted acc and at time equal sig kill it should move this process to TRM, check : process should in FCFS => RUN or RDY





};