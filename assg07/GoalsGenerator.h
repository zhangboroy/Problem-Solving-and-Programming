#include <fstream>
using namespace std;

#ifndef GOALSGENERATOR_H_INCLUDED
#define GOALSGENERATOR_H_INCLUDED

//create a class for the goals of a match
class GoalsGenerator
{
    int HomeGoal;
    int AwayGoal;
public:
    GoalsGenerator(int point);
    //output the goals to a file
    void PrintGoals(ofstream &outData) const
    {
        outData<<HomeGoal<<" - "<<AwayGoal;
    }
};

#endif // GOALSGENERATOR_H_INCLUDED
