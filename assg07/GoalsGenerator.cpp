#include <cstdlib>
#include "GoalsGenerator.h"

//generate the winning goal
int GenerateWinningGoal()
{
    //generate the random number from 1-100 to decide the number of goals
    int a=rand()%100;
    if (a<20) return 1;
    else if ((a>19) && (a<45)) return 2;
    else if ((a>44) && (a<60)) return 3;
    else if ((a>59) && (a<75)) return 4;
    else if ((a>74) && (a<88)) return 5;
    else if ((a>87) && (a<94)) return 6;
    else if (a>93) return 7;
}

//generate the losing goal
int GenerateLosingGoal(int WinningGoal)
{
    //generate the random number to decide the number of goals
    int a;
    if (WinningGoal==7) a=rand()%100;
    else if (WinningGoal==6) a=rand()%94;
    else if (WinningGoal==5) a=rand()%88;
    else if (WinningGoal==4) a=rand()%75;
    else if (WinningGoal==3) a=rand()%60;
    else if (WinningGoal==2) a=rand()%45;
    else if (WinningGoal==1) a=rand()%20;

    if (a<20) return 0;
    else if ((a>19) && (a<45)) return 1;
    else if ((a>44) && (a<60)) return 2;
    else if ((a>59) && (a<75)) return 3;
    else if ((a>74) && (a<88)) return 4;
    else if ((a>87) && (a<94)) return 5;
    else if (a>93) return 6;
}

//generate the home goal and away goal
GoalsGenerator::GoalsGenerator(int point)
{
    if (point==3)
    {
        //generate the winning goal for home club
        HomeGoal=GenerateWinningGoal();
        //generate the losing goal for away club
        AwayGoal=GenerateLosingGoal(HomeGoal);
    }
    else if (point==0)
    {
        //generate the winning goal for away club
        AwayGoal=GenerateWinningGoal();
        //generate the losing goal for home club
        HomeGoal=GenerateLosingGoal(AwayGoal);
    }
    else if (point==1)
    {
        //generate the winning goal -1 for both home and away club
        HomeGoal=GenerateWinningGoal()-1;
        AwayGoal=HomeGoal;
    }
}
