#pragma once

//#include "../Headers/Queue.h"
class Processor;
using namespace std;
template<typename T>
class Queue;        //forward declaration for both Queue and struct(IMP notes:-queue must be refrenced to with pointer or & to prevent memory ambiguity--Queue header should also be inlcuded in the cpp file
struct IO_R_D;

class Process {
private:
    int ID; //
    int AT; //
    int RT;
    int CT; //
    int TT;
    int TRT;
    int WT;
    int TWT;
    Queue<IO_R_D *>& IO_RD;
    int remainingtime; //time left to be processed by the cpu
    int NOIO; // number of IO
    //LinkedQueue<IO_R_D> IOList;
    int parentid = -1;


public:
    Process(Queue<IO_R_D*>& obj);
    Process(int id, int at/*, int rt*/, int ct/*, int tt, int trt, int wt, int twt, LinkedList io_rd*/, Queue<IO_R_D*>& obj);

    int getId() const;
    int getArrivalTime() const;
    int getResponseTime() const;
    int getCpuTime() const;
    int getTerminationTime() const;
    int getTurnaroundDuration() const;
    int getWaitingTime() const;
    int getTotalWaitingTime() const;
    /*VLinkedList getIO_RD() const;*/ //  malhash lazma
    void setId(int id);
    void setArrivalTime(int at);
    void setResponseTime(int rt);
    void setCpuTime(int ct);
    void setTerminationTime(int tt);
    void setTurnaroundDuration(int trt);
    void setWaitingTime(int wt);
    void setTotalWaitingTime(int twt);
 /*   void setIO_RD(VLinkedList io_rd);*/
    void setIOList(int IOR, int IOD);
    int calculateTurnaroundDuration() const;
    int calculateWaitingTime() const;
    void incrementTotalWaitingTime();
    int getremainingtime();
    void decremainingtime();
    void Add_To_IOList(IO_R_D* S);

    void peekIO(IO_R_D*& S);

    void DequeueIO(IO_R_D* S);

    // Khaled added 
    int getNOIO();
    void setNOIO(int NIO);

    int getparentid();
    void setparentid(int id);


};

