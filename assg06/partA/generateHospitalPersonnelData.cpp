#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "generateHospitalPersonnelData.h"
#include "HospitalPersonnelData.h"
using namespace std;

//transfer number to Role string
string GenerateRole(int i)
{
    if (i==0) return "MD";
    else if (i==1) return "NP";
    else if (i==2) return "PT";
}

//transfer number to ExitFlag char
char GenerateExitFlag(int i)
{
    if (i==0) return 'N';
    else if (i==1) return 'Y';
}

//transfer number to DutyDay string
string GenerateDutyDay(int i)
{
    if (i==0) return "M";
    else if (i==1) return "T";
    else if (i==2) return "W";
    else if (i==3) return "TH";
    else if (i==4) return "F";
    else if (i==5) return "SA";
    else if (i==6) return "SU";
}

//check if the ID existed in former data
bool CheckID(HospitalPersonnel P[], int i)
{
    for (int j=0;j<i;j++)
    {
        if (P[i].ID==P[j].ID) return true;
    }
    return false;
}

//generate random HospitalPersonnel data
void GenerateHospitalPersonnelData(int RecordNumber)
{
    srand(time(0));
    ofstream outData;
    outData.open("hospitalPersonnelData.txt", ios::trunc);
    outData<<RecordNumber<<endl;

    //create variables for the length of FirstName and LastName
    int FirstNameLength;
    int LastNameLength;
    //create enough array for HospitalPersonnel records
    HospitalPersonnel P[RecordNumber];
    //create a variable for random letter generation
    char TempLetter=' ';

    for (int i=0;i<RecordNumber;i++)
    {
        //generate random length for FirstName and LastName
        FirstNameLength=rand()%15+6;
        LastNameLength=rand()%19+7;

        //generate random FirstName
        for (int j=0;j<FirstNameLength;j++)
        {
            //generate a random letter
            TempLetter='A'+rand()%26;
            //add the random letter to FirstName
            P[i].FirstName=P[i].FirstName+TempLetter;
        }

        //generate random LastName
        for (int j=0;j<LastNameLength;j++)
        {
            //generate a random letter
            TempLetter='A'+rand()%26;
            //add the random letter to LastName
            P[i].LastName=P[i].LastName+TempLetter;
        }

        //generate random ID
        do
        {
            P[i].ID=rand()%100000;
        }
        //check if the ID existed in former data
        while (CheckID(P, i));

        //generate random Role
        P[i].Role=GenerateRole(rand()%3);

        //output FirstName, LastName, ID and Role to the file
        outData<<P[i].FirstName<<' '<<P[i].LastName<<' '<<setw(5)<<setfill('0')<<P[i].ID<<' '<<P[i].Role<<' ';

        //if the record is patient
        if (P[i].Role=="PT")
        {
            //generate random ExitFlag
            P[i].ExitFlag=GenerateExitFlag(rand()%2);
            //generate random AdmitDate
            P[i].AdmitDate.month=rand()%12+1;
            P[i].AdmitDate.day=rand()%28+1;
            P[i].AdmitDate.year=2015;

            //output ExitFlag and AdmitDate to the file
            outData<<P[i].ExitFlag<<' '<<P[i].AdmitDate.month<<':'<<P[i].AdmitDate.day<<':'<<P[i].AdmitDate.year;
            //check if the ExitFlag is Y
            if (P[i].ExitFlag=='Y')
            {
                //generate random OptionalExitDate
                P[i].OptionalExitDate.month=rand()%12+1;
                P[i].OptionalExitDate.day=rand()%28+1;
                P[i].OptionalExitDate.year=2015;
                //output OptionalExitDate to the file
                outData<<' '<<P[i].OptionalExitDate.month<<':'<<P[i].OptionalExitDate.day<<':'<<P[i].OptionalExitDate.year;
            }
        }
        //if the record is staff
        else if ((P[i].Role=="MD") || (P[i].Role=="NP"))
        {
            //generate the first DutyDay
            P[i].DutyDay[0]=GenerateDutyDay(rand()%7);
            //generate the second DutyDay
            do
            {
                P[i].DutyDay[1]=GenerateDutyDay(rand()%7);
            }
            //check if the DutyDay existed
            while (P[i].DutyDay[1]==P[i].DutyDay[0]);

            //generate the third DutyDay
            do
            {
                P[i].DutyDay[2]=GenerateDutyDay(rand()%7);
            }
            //check if the DutyDay existed
            while ((P[i].DutyDay[2]==P[i].DutyDay[0]) || (P[i].DutyDay[2]==P[i].DutyDay[1]));
            //output DutyDay to the file
            outData<<P[i].DutyDay[0]<<' '<<P[i].DutyDay[1]<<' '<<P[i].DutyDay[2];
        }
        outData<<endl;
    }
    outData.close();
}
