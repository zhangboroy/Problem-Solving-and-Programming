#include "Club.h"

#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

//create a class for the competition
class Competition
{
    int ClubNumber;
    Club *club;
public:
    Competition();
    //set the tournament with the clubs and start it
    void SetupTournament(ofstream &outData);
    //read the number of clubs in the competition
    int GetClubNumber() const
    {
        return ClubNumber;
    }
    //read the club information of the competition
    Club* GetClub() const
    {
        return club;
    }
    //delete the club pointer
    void clean();
};

#endif // COMPETITION_H_INCLUDED
