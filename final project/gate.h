#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#include "cash.h"
#include "lot.h"
using namespace std;

//create a class for the Gate
class Gate
{
    char name;
    int positionX;
    int positionY;
    static int quarter;
    static int dollar1;
    static int dollar5;
    static int dollar10;
    static int dollar20;
    int capacity;
    //the displayed information of lots
    Lot **lot;
public:
    Gate();
    ~Gate()
    {
        delete []lot;
    }
    //read the data of the gates from a file
    void Setup(int lotsNumber, Lot *lot1, int cashNumber, const Cash *cash1, ifstream &inData);
    char GetName() const
    {
        return name;
    }
    int GetPositionX() const
    {
        return positionX;
    }
    int GetPositionY() const
    {
        return positionY;
    }
    int static GetQuarter()
    {
        return quarter;
    }
    int static GetDollar1()
    {
        return dollar1;
    }
    int static GetDollar5()
    {
        return dollar5;
    }
    int static GetDollar10()
    {
        return dollar10;
    }
    int static GetDollar20()
    {
        return dollar20;
    }
    int GetCapacity() const
    {
        return capacity;
    }
    Lot** GetLot() const
    {
        return lot;
    }
    //output the account detail
    void static PrintAccount();
    //calculate the cost of the chosen lot
    float Cost(int i, int totalSpots) const;
    //output the information of all Parking Lots
    void DisplayLots(int lotsNumber, int totalSpots);
    //charge the visitor for the parking fee
    void Charge(char lotName, float cost);
    //ask the visitor to choose the Parking Lot
    void ChooseParkingLot(int lotsNumber);
};

#endif // GATE_H_INCLUDED
