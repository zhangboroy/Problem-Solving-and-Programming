#include <cstdlib>
#include <iomanip>
#include "Club.h"
#include "GoalsGenerator.h"

//set the club empty
Club::Club()
{
    name="";
    points=0;
    formGuide="";
    historicWinPercent=0;
    historicLossPercent=0;
}

//input data from a file to the club object
void Club::ReadClubData(ifstream &inData)
{
    inData>>name>>historicWinPercent>>historicLossPercent;
}

//output the game summary to a file
void Club::printGameSummary(const Club &club2, int point, ofstream &outData) const
{
    outData<<name<<' ';
    //generate the goals of the match
    GoalsGenerator goals(point);
    //output the goals
    goals.PrintGoals(outData);
    outData<<' '<<club2.name<<endl;
}

//generate the result of a game with the away club
void Club::playGame(Club &club2, ofstream &outData)
{
    //generate the random number from 1-100 to decide the result
    int result=rand()%100+1;
    //if the home club win
    if (result<=historicWinPercent)
    {
        points+=3;
        formGuide=formGuide+'W';
        club2.formGuide=club2.formGuide+'L';
        //output the game summary
        printGameSummary(club2,3,outData);
    }
    //if the home club lose
    else if ((result>historicWinPercent) && (result<=historicWinPercent+historicLossPercent))
    {
        club2.points+=3;
        formGuide=formGuide+'L';
        club2.formGuide=club2.formGuide+'W';
        //output the game summary
        printGameSummary(club2,0,outData);
    }
    //if it is a draw
    else
    {
        points++;
        club2.points++;
        formGuide=formGuide+'D';
        club2.formGuide=club2.formGuide+'D';
        //output the game summary
        printGameSummary(club2,1,outData);
    }
}

//output the club information to a file
void Club::print(ofstream &outData) const
{
    outData<<left<<setw(12)<<name<<setw(2)<<points<<' '<<formGuide<<endl;
}
