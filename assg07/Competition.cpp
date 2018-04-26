#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Competition.h"
using namespace std;

//input data from a file to the competition object
Competition::Competition()
{
    ifstream inData;
    inData.open("clubs.txt");
    inData>>ClubNumber;
    //create enough club records
    club=new Club[ClubNumber];
    //input data to the club objects 1 by 1
    for (int i=0;i<ClubNumber;i++)
    {
        club[i].ReadClubData(inData);
    }
    inData.close();
}

//set the tournament with the clubs and start it
void Competition::SetupTournament(ofstream &outData)
{
    srand(time(0));
    for (int i=0;i<ClubNumber;i++)
    {
        for (int j=0;j<ClubNumber;j++)
        {
            if (i!=j)
            {
                club[i].playGame(club[j], outData);
            }
        }
    }
}

//delete the club pointer
void Competition::clean()
{
    delete []club;
    club=0;
}
