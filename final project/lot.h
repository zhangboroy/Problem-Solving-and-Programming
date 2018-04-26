#ifndef LOT_H_INCLUDED
#define LOT_H_INCLUDED

#include <fstream>
#include <cmath>
using namespace std;

//create a class for Parking Lot
class Lot
{
    char name;
    int positionX;
    int positionY;
    int capacity;
    int usedSpots;
public:
    //create a lot at the position of main entrance
    Lot();
    ~Lot(){}
    //read the data of the lots from a file and return the used spots number
    int setup(ifstream &inData);
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
    int GetCapacity() const
    {
        return capacity;
    }
    int GetUsedSpots() const
    {
        return usedSpots;
    }
    //set a spot for the visitor
    void FillUsedSpots()
    {
        usedSpots++;
    }
    //calculate the distance from another position
    template <class Destination>
    int DistanceFrom(const Destination &d) const
    {
        return (abs(positionX-d.GetPositionX())+abs(positionY-d.GetPositionY()));
    }
};

#endif // LOT_H_INCLUDED
