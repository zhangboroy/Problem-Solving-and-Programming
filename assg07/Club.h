#include <string>
using namespace std;

#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

//create a class for the soccer club
class Club
{
    string name;
    int points;
    string formGuide;
    int historicWinPercent;
    int historicLossPercent;
public:
    Club();
    //read the points of the club
    int GetPoints() const
    {
        return points;
    }
    //input data from a file to the club object
    void ReadClubData(ifstream &inData);
    //generate the result of a game with the away club
    void playGame(Club &club2, ofstream &outData);
    //output the game summary to a file
    void printGameSummary(const Club &club2, int point, ofstream &outData) const;
    //output the club information to a file
    void print(ofstream &outData) const;
};

#endif // CLUB_H_INCLUDED
