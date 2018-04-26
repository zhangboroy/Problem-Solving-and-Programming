#include <cstdlib>
#include "lot.h"

//create a lot at the position of main entrance
Lot::Lot()
{
    name=' ';
    positionX=2;
    positionY=0;
    capacity=0;
    usedSpots=0;
}

//read the data of the lots from a file and return the used spots number
int Lot::setup(ifstream &inData)
{
    inData>>name;
    inData>>positionX;
    inData>>positionY;
    inData>>capacity;
    usedSpots=rand()%(capacity/10+1);
    return usedSpots;
}

