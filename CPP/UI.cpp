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
      cout << "Simulation Started...." << endl;

      cout << "Simulation Ended.....";
 
  
  }
  int UI:: gettimestep() {
      return timestep;
  }
  void UI::writeInfoToFile() {
      Queue<Process*> blkList = PS->getBLKList();
      processor** processorList = PS->getProcessorList();
      int nFCFS = PS->getnFCFS();
      int nSJF = PS->getnSJF();
      int nRR = PS->getnRR();
      Queue<Process*> trmList = PS->getTRMList();
      int npr = PS->getnprocess();
      ofstream outputFile("info.txt");
      int wt, rt, trt;
      if (!outputFile) {
          cout << "Error opening file." << endl;
          return;
      }

      outputFile << "TT PID AT CT IO_D WT RT TRT" << endl;

      for (int i = 0; i < npr; i++) {
          outputFile << (trmList.getProcessAtPosition(trmList, i)->getTerminationTime()) << " " << trmList.getProcessAtPosition(trmList, i)->getId() << " " << trmList.getProcessAtPosition(trmList, i)->getArrivalTime() << " " << trmList.getProcessAtPosition(trmList, i)->getCpuTime() << " " << trmList.getProcessAtPosition(trmList, i)->calculateWaitingTime() << " " << trmList.getProcessAtPosition(trmList, i)->getResponseTime() << " " << trmList.getProcessAtPosition(trmList, i)->getId() << " " << trmList.getProcessAtPosition(trmList, i)->calculateTurnaroundDuration() << endl;
      }
      // Write the second line of information
      outputFile << npr << endl;

      int wt_sum = 0;
      for (int i = 0; i < trmList.count(); i++) {
          wt_sum += trmList.getProcessAtPosition(trmList, i)->calculateWaitingTime();
      }
      double avg_wt = static_cast<double>(wt_sum) / npr;

      // Write the average waiting time to the output file
      outputFile << "Average WT= " << avg_wt << endl;
      /////////////////////////////////////////////////////////////////
      int rt_sum = 0;
      for (int i = 0; i < trmList.count(); i++) {
          rt_sum += trmList.getProcessAtPosition(trmList, i)->getResponseTime();
      }
      double avg_rt = (rt_sum) / npr;
      outputFile << "Average RT= " << avg_rt << endl;
      //////////////////////////////////////////////////////////////// // Close the file
      int trt_sum = 0;
      for (int i = 0; i < trmList.count(); i++) {
          trt_sum += trmList.getProcessAtPosition(trmList, i)->calculateTurnaroundDuration();
      }
      double avg_trt = (trt_sum) / npr;
      outputFile << "Average TRT= " << avg_trt << endl;
      ///////////////////////////////////////////////////////////////
      int load = 0;
      for (int i = 0; i < nFCFS+nRR+nSJF; i++) {
          load = processorList[i]->getBusyTime()/trt_sum;
          outputFile << "Processor#" << i << "Load" << load;
      }
      outputFile << endl;
      int uti = 0;
      for (int i = 0; i < nFCFS + nRR + nSJF; i++) {
          uti = processorList[i]->getBusyTime() / (processorList[i]->getBusyTime() + processorList[i]->getIDLETime());
          outputFile << "Processor#" << i << "Utilization" << uti;
      }
   
      
      outputFile.close();

      std::cout << "Information written to file." << std::endl;
  }