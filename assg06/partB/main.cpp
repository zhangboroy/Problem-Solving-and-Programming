#include <iostream>
#include <fstream>
#include "HospitalPersonnelData.h"
#include "processHospitalPersonnelData.h"

int main()
{
    ifstream inData;
    int StaffNumber=0;
    int RecordNumber;
    DataRead(inData, RecordNumber);

    //set enough arrays for doctors, nurses and patients
    HospitalPersonnel person[RecordNumber];

    //read the records 1 by 1
    for (int i=0;i<RecordNumber;i++)
    {
        RecordRead(StaffNumber,person[i],inData);
    }

    inData.close();

    int choice;
    string garbage;
    do
    {
        MenuPrint();
        cin>>choice;
        if ((cin) && (choice>-1) && (choice<6))
        {
            RecordPrint(choice, RecordNumber, StaffNumber, person);
        }

        //restore cin when input is invalid
        if (!cin)
        {
            cin.clear();
        }

        //discard the other inputs
        getline(cin, garbage);
    }
    while (choice!=6);

    return 0;
}
