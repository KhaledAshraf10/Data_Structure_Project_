#pragma once

#include "LinkedList.h"
using namespace std;

class Process {
private:
    int ID;
    int AT;
    int RT;
    int CT;
    int TT;
    int TRT;
    int WT;
    int TWT;
    LinkedList IO_RD;

public:
    Process(int id, int at, int rt, int ct, int tt, int trt, int wt, int twt, LinkedList io_rd);
    int getId() const;
    int getArrivalTime() const;
    int getResponseTime() const;
    int getCpuTime() const;
    int getTerminationTime() const;
    int getTurnaroundDuration() const;
    int getWaitingTime() const;
    int getTotalWaitingTime() const;
    LinkedList getIO_RD() const;
    void setId(int id);
    void setArrivalTime(int at);
    void setResponseTime(int rt);
    void setCpuTime(int ct);
    void setTerminationTime(int tt);
    void setTurnaroundDuration(int trt);
    void setWaitingTime(int wt);
    void setTotalWaitingTime(int twt);
    void setIO_RD(LinkedList io_rd);
    int calculateTurnaroundDuration() const;
    int calculateWaitingTime() const;
    void incrementTotalWaitingTime();
};

