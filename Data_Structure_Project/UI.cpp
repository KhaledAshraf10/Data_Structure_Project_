#include <iostream>
#include "../Headers/Process.h"
#include"../Headers/processor.h"
#include "../Headers/Schedular.h"
#include"UI.h"
#include "../Headers/ProSJB.h"


  void UI:: printProcessIDs(Schedular* schedular) {
        LinkedList<Process*> trmList = schedular->getTRMList();
        Queue<Process*> blkList = schedular->getBLKList();
        processor** processorList = schedular->getProcessorList();
        int nFCFS = schedular->getnFCFS();
        int nSJF = schedular->getnSJF();
        int nRR = schedular->getnRR();
        cout << "CurrentTimeStep : " << schedular->getTimeStep() << endl;
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
            cout << processorList[i]->PrintRUN() << endl;
        }
        for (int i = nFCFS; i < nSJF + nFCFS; i++) {
            cout << "Processor " << i + 1 << " SJF ";
            cout << processorList[i]->PrintRUN() << endl;
        }
        for (int i = nSJF + nFCFS; i < nSJF + nFCFS + nRR; i++) {
            cout << "Processor " << i + 1 << " RR ";
            cout << processorList[i]->PrintRUN() << endl;
        }
        cout << "-------------- TRM Processes -------------" << endl;

        trmList.PrintListid();
        cout << "------------- BLK Processes ---------------" << endl;
       // for (int i = 0; i < blkList.size(); i++) {
            blkList.Printlistid();
        //}




    }