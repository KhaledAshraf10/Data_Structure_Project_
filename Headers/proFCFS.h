#pragma once
#include "../Headers/Schedular.h"
//#include "../Headers/processor.h"
#include "LinkedList.h"
#include"processor.h"
//class processor;
class Schedular;
class Process;
class ProFCFS : public processor 
{
private:
	LinkedList<Process*> Plist;
	int noP; //no of processes in RDY LIST

public:

	ProFCFS(Schedular* p,int overheatT) ;

	virtual ~ProFCFS();

	  int gettimer() const override ;

	 void ScheduleAlgo() ;

	void  forkingrequest(int AT, int RT);

	 void inctimer(Process* p) override;
	 void inctimer(int time) ;
	 void dectimer(Process* p) override;
	 void add_process(Process* p) override;
	 bool RandomKiller() ;
	 void PrintRDY() override;
	 bool PrintRUN() override;
	 Process* getprocess(Schedular* S) {
		 if (RUNLIST != nullptr) {
			 return RUNLIST;



		 }
		 else {
			 return nullptr;
		 }



	 }

	// ana esmy eyad




};

