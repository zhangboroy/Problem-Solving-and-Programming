#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//set a struct for dates
struct date
{
    int month;
    int day;
    int year;
    bool DateCompare(date date1);
    date();
};

//initiate the date with 00:00:0000
date::date()
{
    month=0;
    day=0;
    year=0;
}

//set a struct for doctors and nurses
struct MedicalPersonnel
{
    string FirstName;
    string LastName;
    string ID;
    string Role;
    string DutyDay[3];
    MedicalPersonnel();
};

//initiate all fields with empty string
MedicalPersonnel::MedicalPersonnel()
{
    FirstName="";
    LastName="";
    ID="";
    Role="";
    for (int i=0;i<3;i++)
    {
        DutyDay[i]="";
    }
}

//set a struct for patients
struct PatientsPersonnel
{
    string FirstName;
    string LastName;
    string ID;
    string Role;
    char ExitFlag;
    date AdmitDate;
    date OptionalExitDate;
    PatientsPersonnel();
};

//initiate all fields with empty or 0
PatientsPersonnel::PatientsPersonnel()
{
    FirstName="";
    LastName="";
    ID="";
    Role="";
    ExitFlag=' ';
}

//Print 2 lines of *
void PrintStar()
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<79;j++)
        {
            cout<<'*';
        }
        cout<<endl;
    }
}

//just print the menu
void MenuPrint()
{
    cout<<"Press 0 to print all Hospital Personnel\n"
        <<"Press 1 to print only Patients\n"
        <<"Press 2 to print only Doctors\n"
        <<"Press 3 to print only Nurse Practitioners\n"
        <<"Press 4 to print only Admitted Patients\n"
        <<"Press 5 to print only non-Admitted Patients\n"
        <<"Press 6 to print all Personnel sort based on admitDate\n"
        <<"Press 7 to exit: "<<flush;
}

//open the TXT file, read the record number and print it on the screen, return with the file opening
void DataRead (ifstream &inData, int &RecordNumber)
{
    inData.open("hospitalPersonnel.txt");
    inData >> RecordNumber;
    cout<<"Success opening hospitalPersonnel.txt"<<endl
        <<"totalHospitalPersonnels: "<<RecordNumber<<endl;
}

//read a single record to the struct variable
void RecordRead (int &PatientNumber, MedicalPersonnel &staff, PatientsPersonnel &patient, ifstream &inData)
{
    //create temporary variables for the first 4 fields of the record
    string tempFirstName;
    string tempLastName;
    string tempID;
    string tempRole;
    inData>>tempFirstName>>tempLastName>>tempID>>tempRole;

    //distinguish the record is a doctor, nurse or patient
    if ((tempRole=="MD") || (tempRole=="NP"))
    {
        //transfer the data from temporary variables to MedicalPersonnel variable
        staff.FirstName=tempFirstName;
        staff.LastName=tempLastName;
        staff.ID=tempID;
        staff.Role=tempRole;
        //read the rest fields of the record to the MedicalPersonnel variable
        for (int i=0;i<3;i++)
        {
            inData>>staff.DutyDay[i];
        }
        /*//delete the corresponding PatientsPersonnel variable
        patient.FirstName="";
        patient.LastName="";
        patient.ID="";
        patient.Role="";
        patient.ExitFlag=' ';
        patient.AdmitDate.month=0;
        patient.AdmitDate.day=0;
        patient.AdmitDate.year=0;
        patient.OptionalExitDate.month=0;
        patient.OptionalExitDate.day=0;
        patient.OptionalExitDate.year=0;*/
    }
    else if (tempRole=="PT")
    {
        PatientNumber++;
        //transfer the data from temporary variables to PatientsPersonnel variable
        patient.FirstName=tempFirstName;
        patient.LastName=tempLastName;
        patient.ID=tempID;
        patient.Role=tempRole;
        //read the next 2 fields of the record to the PatientsPersonnel variable
        char c;
        inData>>patient.ExitFlag>>patient.AdmitDate.month>>c>>patient.AdmitDate.day>>c>>patient.AdmitDate.year;
        //distinguish the patient exit or not
        if (patient.ExitFlag=='Y')
        //read the exit date of the record to the PatientsPersonnel variable
        {
            inData>>patient.OptionalExitDate.month>>c>>patient.OptionalExitDate.day>>c>>patient.OptionalExitDate.year;
        }
        /*//delete the corresponding MedicalPersonnel variable
        staff.FirstName="";
        staff.LastName="";
        staff.ID="";
        staff.Role="";
        for (int i=0;i<3;i++)
        {
            staff.DutyDay[i]="";
        }*/
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
void DatePrint(date date)
{
    cout<<setw(2)<<setfill('0')<<right<<date.month<<':'<<setw(2)<<date.day<<':'<<setw(4)<<date.year<<left<<setfill(' ');
}

//print the record of a doctor or a nurse
void StaffPrint(int i, MedicalPersonnel staff)
{
    cout<<left<<setw(3)<<i<<setw(10)<<staff.FirstName<<setw(10)<<staff.LastName<<setw(15)<<staff.ID<<setw(7)<<staff.Role;
    for (int j=0;j<3;j++)
    {
        DutyDayPrint(staff.DutyDay[j]);
        if (j<2) cout<<'-';
    }
    cout<<endl;
}

//print the record of a patient
void PatientPrint(int i, PatientsPersonnel patient)
{
    cout<<left<<setw(3)<<i<<setw(10)<<patient.FirstName<<setw(10)<<patient.LastName<<setw(15)<<patient.ID<<setw(7)<<patient.Role<<setw(6)<<patient.ExitFlag;
    DatePrint(patient.AdmitDate);
    //distinguish the patient exit or not
    if (patient.ExitFlag=='Y')
    {
        cout<<"      ";
        DatePrint(patient.OptionalExitDate);
    }
    cout<<endl;
}

//compare two dates
bool date::DateCompare(date date1)
{
    return ((year>date1.year) || ((year==date1.year) && (month>date1.month)) || ((year==date1.year) && (month==date1.month) && (day>date1.day)));
}

//sort all records
void SortPrint(int RecordNumber, int PatientNumber, MedicalPersonnel staff[], PatientsPersonnel patient[])
{
    //create struct variables to store the sorted records
    MedicalPersonnel SortedStaff[RecordNumber-PatientNumber];
    PatientsPersonnel SortedPatient[PatientNumber];
    //m for marking the index of staff record, n[i] for storing the rank of patient[i]
    int m=0, n[RecordNumber];
    //initiate all n
    for (int i=0;i<RecordNumber;i++)
    {
        n[i]=0;
    }

    for (int i=0;i<RecordNumber;i++)
    {
        //store staff records 1 by 1 as the same sequence
        if ((staff[i].Role=="MD") || (staff[i].Role=="NP"))
        {
            SortedStaff[m]=staff[i];
            //move the index to next one
            m++;
        }
        //sort patient records
        else if (patient[i].Role=="PT")
        {
            //just compare the record with records after it
            for (int j=i+1;j<RecordNumber;j++)
            {
                if (patient[j].Role=="PT")
                {
                    //select the larger record and add 1 to its rank
                    if (patient[i].AdmitDate.DateCompare(patient[j].AdmitDate))
                    {
                        n[i]++;
                    }
                    else
                    {
                        n[j]++;
                    }
                }
            }
            //patient[i]'s rank should be n[i]
            SortedPatient[n[i]]=patient[i];
        }
    }

    //print all sorted records, patients first
    for (int i=0;i<RecordNumber;i++)
    {
        if (i<PatientNumber)
        {
            PatientPrint(i, SortedPatient[i]);
        }
        else
        {
            StaffPrint(i, SortedStaff[i-PatientNumber]);
        }
    }
}

//print the records selected
void RecordPrint(int choice, int RecordNumber, int PatientNumber, MedicalPersonnel staff[], PatientsPersonnel patient[])
{
    cout<<endl;
    PrintStar();

    //print all records
    if (choice==0)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish the record is a doctor, nurse or a patient
            if ((staff[i].Role=="MD") || (staff[i].Role=="NP"))
            //print the staff(doctor or nurse) record
            {
                StaffPrint(i, staff[i]);
            }
            else if (patient[i].Role=="PT")
            //print the patient record
            {
                PatientPrint(i, patient[i]);
            }
        }
    }
    //print all patients
    else if (choice==1)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a patient
            if (patient[i].Role=="PT")
            {
                PatientPrint(i, patient[i]);
            }
        }
    }
    //print all doctors
    else if (choice==2)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a doctor
            if (staff[i].Role=="MD")
            {
                StaffPrint(i, staff[i]);
            }
        }
    }
    //print all nurses
    else if (choice==3)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a nurse
            if (staff[i].Role=="NP")
            {
                StaffPrint(i, staff[i]);
            }
        }
    }
    //print all non-exit patients
    else if (choice==4)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is a non-exit patient
            if ((patient[i].Role=="PT") && (patient[i].ExitFlag=='N'))
            {
                PatientPrint(i, patient[i]);
            }
        }
    }
    //print all exit patients
    else if (choice==5)
    {
        for (int i=0;i<RecordNumber;i++)
        {
            //distinguish if the record is an exit patient
            if ((patient[i].Role=="PT") && (patient[i].ExitFlag=='Y'))
            {
                PatientPrint(i, patient[i]);
            }
        }
    }
    //print all sorted records
    else if (choice==6)
    {
        SortPrint(RecordNumber, PatientNumber, staff, patient);
    }

    PrintStar();
    cout<<endl;
}

int main()
{
    ifstream inData;
    int PatientNumber=0;
    int RecordNumber;
    DataRead(inData, RecordNumber);

    //set enough arrays for doctors, nurses and patients, maybe more than needed
    MedicalPersonnel staff[RecordNumber];
    PatientsPersonnel patient[RecordNumber];

    //read the records 1 by 1
    for (int i=0;i<RecordNumber;i++)
    {
        RecordRead(PatientNumber,staff[i],patient[i],inData);
    }

    inData.close();
    //print all records
    RecordPrint(0, RecordNumber, PatientNumber, staff, patient);

    int choice;
    string garbage;
    do
    {
        MenuPrint();
        cin>>choice;
        if ((cin) && (choice>-1) && (choice<7))
        {
            RecordPrint(choice, RecordNumber, PatientNumber, staff, patient);
        }

        //restore cin when input is invalid
        if (!cin)
        {
            cin.clear();
        }

        //discard the other inputs
        getline(cin, garbage);
    }
    while (choice!=7);

    return 0;
}
