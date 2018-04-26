#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "HospitalPersonnelData.h"

using namespace std;

//just print the menu
void MenuPrint()
{
    cout<<"Press 0 to print all hospital personnel\n"
        <<"Press 1 to print only Doctors (MD)\n"
        <<"Press 2 to print only Nurse Practitioners (NP)\n"
        <<"Press 3 to print only Current Patients\n"
        <<"Press 4 to print only Past Patients\n"
        <<"Press 5 to print only Doctors/Nurse Practitioners based on DutyDay\n"
        <<"Press 6 to exit: "<<flush;
}

//open the TXT file, read the record number, return with the file opening
void DataRead (ifstream &inData, int &RecordNumber)
{
    inData.open("hospitalPersonnelData.txt");
    inData >> RecordNumber;
}

//read a single record to the struct variable
void RecordRead (int &StaffNumber, HospitalPersonnel &person, ifstream &inData)
{
    //read the first 4 fields of the record
    inData>>person.FirstName>>person.LastName>>person.ID>>person.Role;

    //distinguish the record is a doctor, nurse or patient
    if ((person.Role=="MD") || (person.Role=="NP"))
    {
        StaffNumber++;
        //read the rest fields of the record to the variable
        for (int i=0;i<3;i++)
        {
            inData>>person.DutyDay[i];
        }
    }
    else if (person.Role=="PT")
    {
        //read the next 2 fields of the record to the variable
        char c;
        inData>>person.ExitFlag>>person.AdmitDate.month>>c>>person.AdmitDate.day>>c>>person.AdmitDate.year;
        //distinguish the patient exit or not
        if (person.ExitFlag=='Y')
        //read the exit date of the record to the variable
        {
            inData>>person.OptionalExitDate.month>>c>>person.OptionalExitDate.day>>c>>person.OptionalExitDate.year;
        }
    }
}

//output the full name of the day of the week instead of the abbreviation
void DutyDayPrint(string DutyDay)
{
    if (DutyDay=="M")
    {
        cout<<"Mondays";
    }
    else if (DutyDay=="T")
    {
        cout<<"Tuesdays";
    }
    else if (DutyDay=="W")
    {
        cout<<"Wednesdays";
    }
    else if (DutyDay=="TH")
    {
        cout<<"Thursdays";
    }
    else if (DutyDay=="F")
    {
        cout<<"Fridays";
    }
    else if (DutyDay=="SA")
    {
        cout<<"Saturdays";
    }
    else if (DutyDay=="SU")
    {
        cout<<"Sundays";
    }
}

//print the date as mm:dd:yyyy
void DatePrint(const date &date)
{
    cout<<setw(2)<<setfill('0')<<right<<date.month<<':'<<setw(2)<<date.day<<':'<<setw(4)<<date.year<<setfill(' ');
}

//print a single record
void RecordPrint(const HospitalPersonnel &person)
{
    //output the first 4 fields of the record
    cout<<right<<person.FirstName<<", "<<person.LastName<<", "<<setw(5)<<setfill('0')<<person.ID<<", "<<person.Role<<' ';
    //if the record is a staff
    if ((person.Role=="MD") || (person.Role=="NP"))
    {
        //output DutyDay
        for (int j=0;j<3;j++)
        {
            DutyDayPrint(person.DutyDay[j]);
            if (j<2) cout<<'-';
        }
    }
    //if the record is a patient
    else if (person.Role=="PT")
    {
        //output ExitFlag and AdmitDate
        cout<<person.ExitFlag<<' ';
        DatePrint(person.AdmitDate);
        //distinguish the patient exit or not
        if (person.ExitFlag=='Y')
        {
            //output OptionalExitDate
            cout<<' ';
            DatePrint(person.OptionalExitDate);
        }
    }
    cout<<endl;
}

//compare two DutyDays
bool DutyDayCompare(const string DutyDay1[3], const string DutyDay2[3])
{
    return ((DutyDay1[0]>DutyDay2[0]) || ((DutyDay1[0]==DutyDay2[0]) && (DutyDay1[1]>DutyDay2[1])) || ((DutyDay1[0]==DutyDay2[0]) && (DutyDay1[1]==DutyDay2[1]) && (DutyDay1[2]>DutyDay2[2])));
}

//sort staff records
void SortPrint(int RecordNumber, int StaffNumber, const HospitalPersonnel person[])
{
    //create struct variables to store the sorted records
    HospitalPersonnel SortedStaff[StaffNumber];
    //n[i] for storing the rank of person[i]
    int n[RecordNumber];
    //initiate all n
    for (int i=0;i<RecordNumber;i++)
    {
        n[i]=0;
    }

    for (int i=0;i<RecordNumber;i++)
    {
        //sort staff records
        if ((person[i].Role=="MD") || (person[i].Role=="NP"))
        {
            //just compare the record with records after it
            for (int j=i+1;j<RecordNumber;j++)
            {
                //just compare the record with staff records
                if ((person[j].Role=="MD") || (person[j].Role=="NP"))
                {
                    //select the larger record and add 1 to its rank
                    if (DutyDayCompare(person[i].DutyDay, person[j].DutyDay))
                    {
                        n[i]++;
                    }
                    else
                    {
                        n[j]++;
                    }
                }
            }
            //person[i]'s rank should be n[i]
            SortedStaff[n[i]]=person[i];
        }
    }

    //print all sorted staff records
    for (int i=0;i<StaffNumber;i++)
    {
        RecordPrint(SortedStaff[i]);
    }
}

//print the records selected
void RecordPrint(int choice, int RecordNumber, int StaffNumber, const HospitalPersonnel person[])
{
    //print all records
    if (choice==0)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            RecordPrint(person[i]);
        }
    }
    //print all doctors
    else if (choice==1)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a doctor
            if (person[i].Role=="MD")
            {
                RecordPrint(person[i]);
            }
        }
    }
    //print all nurses
    else if (choice==2)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a nurse
            if (person[i].Role=="NP")
            {
                RecordPrint(person[i]);
            }
        }
    }
    //print all current patients
    else if (choice==3)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a non-exit patient
            if ((person[i].Role=="PT") && (person[i].ExitFlag=='N'))
            {
                RecordPrint(person[i]);
            }
        }
    }
    //print all past patients
    else if (choice==4)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is an exit patient
            if ((person[i].Role=="PT") && (person[i].ExitFlag=='Y'))
            {
                RecordPrint(person[i]);
            }
        }
    }
    //print Doctors/Nurse Practitioners based on DutyDay
    else if (choice==5)
    {
        SortPrint(RecordNumber, StaffNumber, person);
    }

    cout<<endl;
}
