#pragma once
#include "LinkedList.h"
#include <fstream>
#include "../Headers/process.h"
#include "../Headers/processor.h"
class Schedular
{
private:

	Process** arr = new Process*;


	LinkedList<processor*> processorList; // int must replace by proessor data type from  sou3dy 

	
	ifstream inputfile;
	int nFCFS, nSJF, nRR, TS, RTF, MaxW, STL, FP, nProcess/*,process dataType,kill datatype*/; 
	int AT, PID, CT, NIO; // data of process taken form file 

public:
	Schedular();
	void load();
	void Add_To_NEW();
	void ShortRDY(); // should return Shortest rdy queue => by looping on all proccesor 
	void Add_To_RDY();
	void Add_To_BLK();
	void Add_To_TRM();
	void Add_To_RUN();

	void Check_Every_TimeStep(); //kol time step processor ha3mlha 

	void LongRDY(); // should return Longest rdy queue , will used in work steal
	int CalcCT(); // should take rdy queu and claculate CT for all process in it => sou3dy hay3mlha 3ando 
	void RRmSJF(); // check mirgration bet RR & SJF using RTF, if proccess in RR has remaining time less than RTF => mirgrate to SJF
	void FCFSmRR(); // check mirgration bet FCFS & RR using MaxW, if proccess in FCFS has waiting time greater than MaxW => mirgrate to RR
	bool CalcSL(); // check for steal limit > 40, using SL = (LongRDY().ClacCT()-ShortRDY().ClacCT())/LongRDY().ClacCT()
	void STLA(); // stealing action should done every STL, 
	void SigKill(); //take list of signal kill that is sorted acc and at time equal sig kill it should move this process to TRM, check : process should in FCFS => RUN or RDY
	/*forking
	process t2oul liy processor en 3ayz fork 3nd time T , processor haymsk process data(3l4an hayb3tha liy scheduler) => new ID , AT = T , CT = reaminging CT parent
	b3d kda processor ya2ol liy schedular create process w yab3t kol haga
	scheduler ha7otha fe shortRDY bet3t FCFS bs , maynf34 child trou7 blk wla tatlop IO
	child momkn fork tany
	lazem yab2a feh list liy parent w children

	orphan
	lw parent ra7 liy trm mafrod lw 3ando children awdyhom liy trm bardo (kol procces 3andha boolean true lw 3andha childred)
	mafrod adwr 3la orphan fe rdy w run betou3 FCFS bs


	flow/simulation
	create list of proccessor w process => atl3 short rdy w ab3t liy procc
	*/
	~Schedular();





};