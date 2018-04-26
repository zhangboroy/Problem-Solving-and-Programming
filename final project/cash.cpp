#include <fstream>
#include "cash.h"
using namespace std;

Cash::Cash()
{
    name="";
    number=0;
}

//read the data of the cash types from a file and return the amount of money
float Cash::ReadParkingAccount(ifstream &inData)
{
    inData>>name;
    inData>>number;
    if (name=="One") return number;
    else if (name=="Five") return 5*number;
    else if (name=="Ten") return 10*number;
    else if (name=="Twenty") return 20*number;
    else if (name=="Quarter") return 0.25*number;
}
