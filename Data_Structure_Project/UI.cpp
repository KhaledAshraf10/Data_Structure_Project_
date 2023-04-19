#include <iostream>
#include "../Headers/Process.h"
#include"../Headers/processor.h"
#include "../Headers/Schedular.h"
#include"UI.h"



  void UI:: printProcessIDs(Schedular* schedular) {
        LinkedList<Process*> trmList = schedular->getTRMList();
        LinkedList<Process*> blkList = schedular->getBLKList();
        processor** processorList = schedular->getProcessorList();
        int nFCFS = schedular->getnFCFS();
        int nSJF = schedular->getnSJF();
        int nRR = schedular->getnRR();
        cout << "CurrentTimeStep" << schedular->gettimestep() << endl;
        cout << "---------- RDY Processes ------------ " << endl;
        for (int i = 0; i < nFCFS ; i++){
            cout << "Processor " << i + 1 << "FCFS" << processorList[i]->PrintRDY();
}
        for (int i = nFCFS; i < nSJF+nFCFS; i++) {
            cout << "Processor " << i + 1 << "SJF" << processorList[i]->PrintRDY();
        }
        for (int i = nSJF + nFCFS; i < nSJF + nFCFS+ nRR; i++) {
            cout << "Processor " << i + 1 << "SJF" << processorList[i]->PrintRDY();
        }


        cout << "---------- RUN Processes ------------ " << endl;
        for (int i = 0; i < nFCFS; i++) {
            cout << "Processor " << i + 1 << "FCFS" << processorList[i]->PrintRUN() << endl;
        }
        for (int i = nFCFS; i < nSJF + nFCFS; i++) {
            cout << "Processor " << i + 1 << "SJF" << processorList[i]->PrintRUN() << endl;
        }
        for (int i = nSJF + nFCFS; i < nSJF + nFCFS + nRR; i++) {
            cout << "Processor " << i + 1 << "SJF" << processorList[i]->PrintRUN() << endl;
        }
        cout << "-------------- TRM Processes -------------" << endl;
        /*for (int i = 0; i < trmList.size(); i++) {
            trmList.PrintListid();
        }*/
        trmList.PrintListid();
        cout << "------------- BLK Processes ---------------" << endl;
       // for (int i = 0; i < blkList.size(); i++) {
            blkList.Printlistid();
        //}




    }