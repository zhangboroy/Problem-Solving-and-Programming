#ifndef PROCESSHOSPITALPERSONNELDATA_H_INCLUDED
#define PROCESSHOSPITALPERSONNELDATA_H_INCLUDED

//just print the menu
void MenuPrint();
//open the TXT file, read the record number, return with the file opening
void DataRead (ifstream &inData, int &RecordNumber);
//read a single record to the struct variable
void RecordRead (int &StaffNumber, HospitalPersonnel &person, ifstream &inData);
//print the records selected
void RecordPrint(int choice, int RecordNumber, int StaffNumber, const HospitalPersonnel person[]);

#endif // PROCESSHOSPITALPERSONNELDATA_H_INCLUDED
