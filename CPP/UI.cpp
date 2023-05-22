#include <iostream>
#include "../Headers/Process.h"
#include"../Headers/processor.h"
#include "../Headers/Schedular.h"
#include"../Headers/UI.h"
#include "../Headers/ProSJB.h"

#include <chrono>
#include <thread> 
#include <fstream>

  void UI::FirstMode(/*Schedular* schedular*/) {

        Queue<Process*> trmList = PS->getTRMList();
        Queue<Process*> blkList = PS->getBLKList();
        processor** processorList = PS->getProcessorList();
        int nFCFS = PS->getnFCFS();
        int nSJF = PS->getnSJF();
        int nRR = PS->getnRR();

        int npr = PS->getnprocess();



        cout << "the current Timestep  " << timestep;
        timestep++;
        cout << "---------- RDY Processes ------------ " << endl;
        for (int i = 0; i < nFCFS ; i++){
           /* Process* dd=new Process(1, 3, 4);
            ProSJB* pro = new ProSJB(schedular);
            pro->add_process(dd);*/
            
            //cout << "Processor " << i + 1 << " FCFS" << pro->PrintRDY();
            cout << "Processor " << i + 1 << " FCFS ";
            processorList[i]->PrintRDY();
}
        for (int i = nFCFS; i < nSJF+nFCFS; i++) {
            cout << "Processor " << i + 1 << " SJF " ;
            processorList[i]->PrintRDY();
        }
        for (int i = nSJF + nFCFS; i < nSJF + nFCFS+ nRR; i++) {
            cout << "Processor " << i + 1 << " RR ";
            processorList[i]->PrintRDY();
        }


        cout << "\n---------- RUN Processes ------------ " << endl;
        for (int i = 0; i < nFCFS; i++) {
            cout << "Processor " << i + 1 << " FCFS ";
            processorList[i]->PrintRUN();
                 cout << endl;
        }
        for (int i = nFCFS; i < nSJF + nFCFS; i++) {
            cout << "Processor " << i + 1 << " SJF ";
            processorList[i]->PrintRUN();
            cout << endl;
        }
        for (int i = nSJF + nFCFS; i < nSJF + nFCFS + nRR; i++) {
            cout << "Processor " << i + 1 << " RR ";
            processorList[i]->PrintRUN();
            cout << endl;
        }
        cout << "-------------- TRM Processes -------------" << endl;

        //trmList.PrintListid();
        Process* P;
        if
        (!trmList.dequeue(P))
            cout << "empty";
        else {
            cout << P->getId();
        }
        cout << "------------- BLK Processes ---------------" << endl;
       // for (int i = 0; i < blkList.size(); i++) {
            blkList.Printlistid();
        //}


            cout << "------------------------------------------------------------------------------------------------------" << endl;


   }
  void UI::ThirdMode()
  {
      cout << "simulation started....";
 
  
  }
  int UI:: gettimestep() {
      return timestep;
  }
  void UI:: writeInfoToFile() {
      int npr = PS->getnprocess();
      ofstream outputFile("info.txt");

      if (!outputFile) {
          std::cerr << "Error opening file." << std::endl;
          return;
      }

      
      outputFile << "TT PID AT CT IO_D WT RT TRT" << std::endl;

      for (int i = 0; i < npr; i++) {
          outputFile << std::endl;
      }
      // Write the second line of information
      outputFile << "50 10 9 22 10 19 6 41" << std::endl;

      // Close the file
      outputFile.close();

      std::cout << "Information written to file." << std::endl;
  }

