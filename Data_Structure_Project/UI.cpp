#include <iostream>
#include "../Headers/Process.h"
#include"../Headers/processor.h"
#include "../Headers/Schedular.h"

class UI {
public:
    void printProcessIDs(Schedular* schedular) {
        LinkedList<Process*> trmList = schedular->getTRMList();
        Queue<Process*> blkList = schedular->getBLKList();
        processor** processorList = schedular->getProcessorList();
        int nFCFS = schedular->getnFCFS();
        int nSJF = schedular->getnSJF();
        int nRR = schedular->getnRR();

        cout << "---------- RDY Processes ------------ " << endl;
        for (int i = 0; i < nFCFS + nSJF + nRR; i++) {
            processorList[i]->PrintRDY();


        }cout << "---------- RUN Processes ------------ " << endl;
        for (int i = 0; i < nFCFS + nSJF + nRR; i++) {

            processorList[i]->PrintRUN();


        }
        cout << "-------------- TRM Processes -------------" << endl;
        for (int i = 0; i < trmList.size(); i++) {
            trmList.PrintListid();
        }

        cout << "------------- BLK Processes ---------------" << endl;
        for (int i = 0; i < blkList.count(); i++) {
            blkList.Printlistid();
        }




    }
};

