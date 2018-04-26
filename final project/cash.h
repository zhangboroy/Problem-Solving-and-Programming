#ifndef CASH_H_INCLUDED
#define CASH_H_INCLUDED

#include <string>
using namespace std;

//create a class for the acceptable cash type
class Cash
{
    string name;
    int number;
public:
    Cash();
    ~Cash(){}
    string GetName() const
    {
        return name;
    }
    int GetNumber() const
    {
        return number;
    }
    //read the data of the cash types from a file and return the amount of money
    float ReadParkingAccount(ifstream &inData);
};

#endif // CASH_H_INCLUDED
