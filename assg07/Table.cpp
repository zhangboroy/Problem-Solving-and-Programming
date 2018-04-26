#include <iomanip>
#include "Table.h"

//Output 2 lines of * to the file
void PrintStar(ofstream &outData)
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<36;j++)
        {
            outData<<"*";
        }
        outData<<endl;
    }
}

//open the output file for the table
Table::Table()
{
    outData.open("Output.txt", ios::trunc);
}

//Sort all the clubs after the tournament, and output the Tournament Table to a file
void Table::PrintSortedTable()
{
    //set the tournament with the clubs and start it
    PremierLeague.SetupTournament(outData);

    //create an array for the sorted clubs
    Club SortedClub[PremierLeague.GetClubNumber()];
    //n[i] for storing the rank of club[i]
    int n[PremierLeague.GetClubNumber()];

    //initiate all n
    for (int i=0;i<PremierLeague.GetClubNumber();i++)
    {
        n[i]=0;
    }

    for (int i=0;i<PremierLeague.GetClubNumber();i++)
    {
        //just compare the record with records after it
        for (int j=i+1;j<PremierLeague.GetClubNumber();j++)
        {
            //select the larger record and add 1 to its rank
            if (PremierLeague.GetClub()[i].GetPoints()<PremierLeague.GetClub()[j].GetPoints())
            {
                n[i]++;
            }
            else
            {
                n[j]++;
            }
        }
        //club[i]'s rank should be n[i]
        SortedClub[n[i]]=PremierLeague.GetClub()[i];
    }

    outData<<"\n\n"<<endl;
    PrintStar(outData);
    outData<<endl;

    //print the table
    for (int i=0;i<PremierLeague.GetClubNumber();i++)
    {
        outData<<left<<setw(2)<<i+1<<' ';
        SortedClub[i].print(outData);
    }

    outData<<endl;
    PrintStar(outData);
    outData.close();

    PremierLeague.clean();
}
