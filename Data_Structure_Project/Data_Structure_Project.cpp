#include <iostream>
#include <fstream>
#include "../Headers/Process.h"
#include "../Headers/proFCFS.h"

#include"../Headers/UI.h"
#include"../Headers/ProRoundRobin.h"
#include"../Headers/ProSJB.h"

using namespace std;
//int main()
//{
//	fstream inputfile;
//	inputfile.open("File_1.txt"); // it can use function from UI to enter file name and then i should make check if file name exist or not 
//	if (inputfile)
//	{
//		int nFCFS, nSJF, nRR, TS, RTF, MaxW, STL, FP, nProcess/*,process dataType,kill datatype*/;
//		int AT, PID, CT, NIO; // data of process taken form file 
//		//Process** arr = new Process*;
//		inputfile >> nFCFS >> nSJF >> nRR >> TS >> RTF >> MaxW >> STL >> FP >> nProcess;
//		cout << nFCFS << nSJF << nRR << TS << RTF << MaxW << STL << FP << nProcess;
//		for (int i = 0; i < nProcess; i++)
//		{
//			inputfile >> AT >> PID >> CT >> NIO;
//			cout << AT << PID << CT << NIO;
//			//arr[i] = new Process(AT, PID, CT);
//			for (int i = 0; i < NIO; i++)
//			{
//				char garbage;
//				int IO_R, IO_D;
//				inputfile >> garbage >> IO_R >> garbage >> IO_D >> garbage >> garbage;
//				cout << IO_R << IO_D;
//				//arr[i]->Add_To_IOList(IO_R, IO_D);
//			}
//		}
//		inputfile.close();
//	}
//	else
//	{
//		cout << "error";
//	}
//	
//}


   



int main() {
	

	/*Queue<Process*> BLK;
	Process* p = new Process(10, 10, 20);
	BLK.enqueue(p);
	BLK.Printlistid();*/



	//Process* p = new Process(10, 10, 10);
	//LinkedList < Process*> list;
	//list.PrintListid();
	//list.InsertBeg(p);
	//list.PrintListid();
	//list.PrintListid();














	Schedular S;
	
	string T;
	T = "s";
	


	while (T!="X") {
		
		S.Phase_1_Simulation();
		cin >> T;
	}

	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();
	//S.Phase_1_Simulation();


	//
	

	



	//Schedular* S = new Schedular();
	//Process* p1=new Process (20, 20, 20);
	//Process* p2 = new Process(18, 18, 18);
	//Process* p3 = new Process(30, 30, 30);


	//ProSJB* pro = new ProSJB(S);
	//ProRoundRobin* proR = new ProRoundRobin(S);
	//pro->add_process(p1);
	//	pro->add_process(p2);
	//	pro->add_process(p3);
	//	pro->add_process(p1);
	//	pro->add_process(p2);
	//	pro->add_process(p3);
	//	pro->PrintRDY();
		//proR->add_process(p1);
		//proR->add_process(p2);
		//proR->add_process(p3);
		//proR->PrintRDY();


	//pro->add_process(p1);
	//pro->PrintRDY();
	//pro->ScheduleAlgo();
	//pro->PrintRDY();
	//pro->PrintRUN();
	/*ProSJB * SJ = new ProSJB(S);
	SJ->add_process(p1);
	SJ->add_process(p2);
	SJ->add_process(p3);
	SJ->PrintRDY();*/
	//RR->PrintRUN();
	//RR->ScheduleAlgo();
	//RR->PrintRDY();
	//RR->PrintRUN();
	//RR->ScheduleAlgo();
	//RR->PrintRDY();
	//RR->PrintRUN();
	//RR->ScheduleAlgo();
	//RR->PrintRDY();
	//RR->PrintRUN();
	//RR->ScheduleAlgo();
	//




	







}





	







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
