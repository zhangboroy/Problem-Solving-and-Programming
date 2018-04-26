#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Contact
{
    string firstName;
    string lastName;
    int phone;
};

//print the whole int list
void Print(list<int> intList)
{
    cout<<"The integer list:"<<endl;
    for (list<int>::iterator current=intList.begin();current!=intList.end();current++)
    {
        cout<<*current<<endl;
    }
    cout<<endl;
}

//print the whole string list
void Print(list<string> stringList)
{
    cout<<"The string list:"<<endl;
    for (list<string>::iterator current=stringList.begin();current!=stringList.end();current++)
    {
        cout<<*current<<endl;
    }
    cout<<endl;
}

//print the whole double list
void Print(list<float> floatList)
{
    cout<<"The float list:"<<endl;
    for (list<float>::iterator current=floatList.begin();current!=floatList.end();current++)
    {
        cout<<*current<<endl;
    }
    cout<<endl;
}

//print the whole contact list
void Print(list<Contact> contactList)
{
    cout<<"The contact list:"<<endl;
    for (list<Contact>::iterator current=contactList.begin();current!=contactList.end();current++)
    {
        cout<<setw(15)<<setfill(' ')<<(*current).firstName<<' '<<setw(15)<<setfill(' ')<<(*current).lastName<<'\t'<<757<<setw(7)<<setfill('0')<<(*current).phone<<endl;
    }
    cout<<endl;
}

int main()
{
    srand(time(0));

    cout<<"Step 1: Create the integer and string lists as empty lists. Add 6 elements each to the lists.\n"<<endl;
    list<int> intList;
    list<int>::iterator intCurrent;
    list<string> stringList;
    list<string>::iterator stringCurrent;
    int newInt=0;
    int stringLength=0;
    string newString="";
    for (int i=0;i<6;i++)
    {
        newInt=rand()%10+1;
        intCurrent=intList.begin();
        while ((newInt>*intCurrent) && (intCurrent!=intList.end()))
        {
            intCurrent++;
        }
        intList.insert(intCurrent, newInt);

        newString="";
        stringLength=rand()%10+1;
        stringCurrent=stringList.begin();
        for (int j=0;j<stringLength;j++)
        {
            newString=newString+char(rand()%26+65);
        }
        while ((newString>*stringCurrent) && (stringCurrent!=stringList.end()))
        {
            stringCurrent++;
        }
        stringList.insert(stringCurrent, newString);
    }

    Print(intList);
    Print(stringList);

    cout<<"Step 2: Create one more list of 1000 elements, all of them with the value 78.15.\n"<<endl;
    list<float> floatList;
    floatList.insert(floatList.begin(),1000,78.15);
    //Print(floatList);

    cout<<"Step 3: \"Push\" 0 to the beginning and 15 to the end of the integer list.\n"<<endl;
    intList.push_front(0);
    intList.push_back(15);
    Print(intList);

    cout<<"Step 4: Insert your name to the middle of the string list (at location 4) using the insert() functions.\n"<<endl;
    stringCurrent=stringList.begin();
    stringList.insert(++++++stringCurrent,"Bo Zhang");
    Print(stringList);

    cout<<"Step 5: Add 2 to the first integer in the list and subtract 4 from the last integer in your integer list.\n"<<endl;
    intList.front()=intList.front()+2;
    intList.back()=intList.back()-4;
    Print(intList);

    cout<<"Step 6: Iterate thorough your string linked list to print the values in the list.\n"<<endl;
    Print(stringList);

    cout<<"Step 7: Create and fill the cellphone-contact list with 500 names.\n"<<endl;
    list<Contact> contactList;
    Contact temp;
    for (int k=0;k<500;k++)
    {
        temp.firstName="";
        temp.lastName="";
        stringLength=rand()%13+3;
        for (int l=0;l<stringLength;l++)
        {
            temp.firstName=temp.firstName+char(65+rand()%26);
        }
        stringLength=rand()%13+3;
        for (int l=0;l<stringLength;l++)
        {
            temp.lastName=temp.lastName+char(65+rand()%26);
        }
        temp.phone=(RAND_MAX*rand()+rand())%10000000;
        contactList.push_back(temp);
    }
    //Print(contactList);

    cout<<"Step 8: Sort the integer list and then reverse it.\n"<<endl;
    intList.sort();
    Print(intList);
    intList.reverse();
    Print(intList);
    return 0;
}
