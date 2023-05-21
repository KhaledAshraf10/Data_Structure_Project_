#pragma once
#include "../Headers/Schedular.h"
//#include "../Headers/processor.h"
#include "LinkedList.h"
#include"processor.h"
//class processor;
// struct to add to queue 
struct MyStruct {
	int ID;
	int KillTime;
};
class Schedular;
class Process;
class ProFCFS : public processor 
{
private:
	LinkedList<Process*> Plist;
	int noP; //no of processes in RDY LIST
	

public:
<<<<<<< HEAD

	ProFCFS(Schedular* p,int overheatT) ;
=======
	
	ProFCFS(Schedular* p) ;
>>>>>>> 30e0de58619aa1c2afcc98d42ec784b945680fa4

	virtual ~ProFCFS();

	  int gettimer() const override ;

	 void ScheduleAlgo() ;

	void  forkingrequest(Process* p);

	 void inctimer(Process* p) override;
	 void inctimer(int time) ;
	 void dectimer(Process* p) override;
	 void add_process(Process* p) override;
	 bool RandomKiller() ;
	 void PrintRDY() override;
	 bool PrintRUN() override;
	 Process* getRUNList()override;
	 Process* getprocess(Schedular* S) {
		 if (RUNLIST != nullptr) {
			 return RUNLIST;



		 }
		 else {
			 return nullptr;
		 }
	 }
	 void KillSig();
	 static void EnqueuEelements(const MyStruct& element);
	 static Queue<MyStruct> KillSigList;

	// ana esmy eyad
	 bool IsInRDY(int id) override;
	 bool IsInRUN(int id) override;
	 string getType() override;
	 Process* getRdyProcess(int id) override;
};



