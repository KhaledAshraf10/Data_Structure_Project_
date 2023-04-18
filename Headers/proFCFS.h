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

	ProFCFS(Schedular* p) ;

	virtual ~ProFCFS();

	  int gettimer() const override ;

	 void ScheduleAlgo() ;

	void  forkingrequest(int AT, int RT);

	 void inctimer(Process* p) override;
	 void inctimer(int time) ;
	 void dectimer(Process* p) override;
	 void add_process(Process* p) override;
	 bool RandomKiller() ;
	 bool PrintRDY() override;
	 bool PrintRUN() override;

	// ana esmy eyad




};

