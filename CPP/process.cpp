#include "Process.h"

Process::Process(int id, int at, int rt, int ct, int tt, int trt, int wt, int twt, LinkedList io_rd) {
    ID = id;
    AT = at;
    RT = rt;
    CT = ct;
    TT = tt;
    TRT = trt;
    WT = wt;
    TWT = twt;
    IO_RD = io_rd;
}
int Process::getId() const {
    return ID;
}
int Process::getArrivalTime() const {
    return AT;
}
int Process::getResponseTime() const {
    return RT;
}
int Process::getCpuTime() const {
    return CT;
}
int Process::getTerminationTime() const {
    return TT;
}
int Process::getTurnaroundDuration() const {
    return TRT;
}
int Process::getWaitingTime() const {
    return WT;
}
int Process::getTotalWaitingTime() const {
    return TWT;
}
LinkedList Process::getIO_RD() const {
    return IO_RD;
}
void Process::setId(int id) {
    ID = id;
}
void Process::setArrivalTime(int at) {
    AT = at;
}
void Process::setResponseTime(int rt) {
    RT = rt;
}
void Process::setCpuTime(int ct) {
    CT = ct;
}
void Process::setTerminationTime(int tt) {
    TT = tt;
}
void Process::setTurnaroundDuration(int trt) {
    TRT = trt;
}
void Process::setWaitingTime(int wt) {
    WT = wt;
}
void Process::setTotalWaitingTime(int twt) {
    TWT = twt;
}
void Process::setIO_RD(LinkedList io_rd) {
    IO_RD = io_rd;
}
int Process::calculateTurnaroundDuration() const {
    return TT - AT;
}
int Process::calculateWaitingTime() const {
    return TRT - CT;
}
void Process::incrementTotalWaitingTime() {
    TWT++;
}
