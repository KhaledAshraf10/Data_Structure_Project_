#include <iostream>
#include "../Headers/Process.h"
#include"../Headers/processor.h"
#include "../Headers/Schedular.h"
#include"../Headers/UI.h"
#include "../Headers/ProSJB.h"


  void UI:: printProcessIDs(/*Schedular* schedular*/) {
        Queue<Process*> trmList = PS->getTRMList();
        Queue<Process*> blkList = PS->getBLKList();
        processor** processorList = PS->getProcessorList();
        int nFCFS = PS->getnFCFS();
        int nSJF = PS->getnSJF();
        int nRR = PS->getnRR();


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




    }