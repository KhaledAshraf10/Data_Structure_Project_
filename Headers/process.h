#pragma once

#include "../Headers/VLinkedList.h"
class Processor;
using namespace std;

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
    VLinkedList IO_RD;
    int remainingtime; //time left to be processed by the cpu
    int NOIO; // number of IO

public:
    Process();
    Process(int id, int at/*, int rt*/, int ct/*, int tt, int trt, int wt, int twt, LinkedList io_rd*/);

    int getId() const;
    int getArrivalTime() const;
    int getResponseTime() const;
    int getCpuTime() const;
    int getTerminationTime() const;
    int getTurnaroundDuration() const;
    int getWaitingTime() const;
    int getTotalWaitingTime() const;
    VLinkedList getIO_RD() const;
    void setId(int id);
    void setArrivalTime(int at);
    void setResponseTime(int rt);
    void setCpuTime(int ct);
    void setTerminationTime(int tt);
    void setTurnaroundDuration(int trt);
    void setWaitingTime(int wt);
    void setTotalWaitingTime(int twt);
    void setIO_RD(VLinkedList io_rd);
    int calculateTurnaroundDuration() const;
    int calculateWaitingTime() const;
    void incrementTotalWaitingTime();
    int getremainingtime();
    void decremainingtime();
    void Add_To_IOList(int IO_R, int IO_D);

    // Khaled added 
    int getNOIO();
    void setNOIO(int NIO);
};

