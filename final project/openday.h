#ifndef OPENDAY_H_INCLUDED
#define OPENDAY_H_INCLUDED

#include "gate.h"

//create a class for the open day
class OpenDay
{
    ifstream inData;
    int emergencyCars;
    float initialMoney;
    int lotsNumber;
    Lot *lot;
    int cashNumber;
    Cash *cash;
    int gateNumber;
    Gate *gate;
public:
    OpenDay();
    ~OpenDay()
    {
        delete []gate;
        delete []cash;
        delete []lot;
    }
    //start a new open day
    void Start();
    //end the open day and output the information needed to a file
    void End();
};

#endif // OPENDAY_H_INCLUDED
