#include <fstream>
#include "Competition.h"

#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

//create a class for the Tournament Table
class Table
{
    ofstream outData;
    Competition PremierLeague;
public:
    Table();
    //Sort all the clubs after the tournament, and output the Tournament Table to a file
    void PrintSortedTable();
};

#endif // TABLE_H_INCLUDED
