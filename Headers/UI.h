#pragma once
#include "../Headers/Schedular.h"
class Schedular;

class UI {
private:
    UI* ptU;
    Schedular* PS;
    int timestep=0;
public:
    UI(Schedular* P) { PS = P; }


    void FirstMode(/*Schedular* schedular*/);
    void ThirdMode();
    void SecondMode();

    int gettimestep();

    void writeInfoToFile();



};
