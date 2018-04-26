#include <string>
using namespace std;

#ifndef HOSPITALPERSONNELDATA_H_INCLUDED
#define HOSPITALPERSONNELDATA_H_INCLUDED

//set a struct for dates
struct date
{
    int month;
    int day;
    int year;
    date();
};

//set a struct for records
struct HospitalPersonnel
{
    string FirstName;
    string LastName;
    int ID;
    string Role;
    string DutyDay[3];
    char ExitFlag;
    date AdmitDate;
    date OptionalExitDate;
    HospitalPersonnel();
};

#endif // HOSPITALPERSONNELDATA_H_INCLUDED
