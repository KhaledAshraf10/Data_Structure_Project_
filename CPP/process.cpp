#include "../Headers/VLinkedList.h"
#include "../Headers/Process.h"



Process::Process()
{
}

Process::Process(int id, int at,/* int rt,*/ int ct/*, int tt, int trt, int wt, int twt,LinkedList io_rd*/) {
    ID = id;
    AT = at;
    //RT = rt;
    CT = ct;
    /*TT = tt;
    TRT = trt;
    WT = wt;
    TWT = twt;*/

    //IO_RD = io_rd;
    remainingtime = ct;



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
VLinkedList Process::getIO_RD() const {
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
void Process::setIO_RD(VLinkedList io_rd) {
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

int Process::getremainingtime() {

    return remainingtime;

};
void Process::decremainingtime() {


    remainingtime--;

}
void Process::Add_To_IOList(int IO_R, int IO_D)
{
    IO_RD.insert(IO_R, IO_D);
}
int Process::getNOIO()
{
    return NOIO;
}
void Process::setNOIO(int NIO)
{
    NOIO = NIO;
}

