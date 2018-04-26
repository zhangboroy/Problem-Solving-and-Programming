#include "openday.h"
using namespace std;

int main()
{
    //create a new open day
    OpenDay day;
    //start the new open day
    day.Start();
    //end the open day and output the information needed to a file
    day.End();
    return 0;
}
