#include "HospitalPersonnelData.h"

//initiate the date with 00:00:0000
date::date()
{
    month=0;
    day=0;
    year=0;
}

//initiate all fields with empty string
HospitalPersonnel::HospitalPersonnel()
{
    FirstName="";
    LastName="";
    ID=0;
    Role="";
    for (int i=0;i<3;i++)
    {
        DutyDay[i]="";
    }
    ExitFlag=' ';
}
