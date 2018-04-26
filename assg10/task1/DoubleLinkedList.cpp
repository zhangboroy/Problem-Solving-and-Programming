#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
// creating a structure which will hold all the student records.
struct StudentRecord
{
    string firstName;
    string lastName;
    int oduUin;
    string dateOfBirth;
    double gpa;
    StudentRecord *next;
    StudentRecord *prev;
};

StudentRecord *head = NULL;
StudentRecord *last = NULL;

void free_list()
{
    // We will create a current node and assign head to it, then we will iterate the node through the linked list and delete all the records stored in the linked list
    StudentRecord *current = head;
    while(current!=NULL) // as I am considering tail->next = NULL
    {
        head->next = current->next;
        current->next = NULL;
        current->prev = NULL;
        free(current);
        current = head->next;
    }

    head = NULL;
    last = NULL;
}


void display_data()
{
    cout << endl << endl << "Listing all student records: " << endl;
    cout << "---------------------------" << endl;
    // We will create a node named start and will iterate it through the whole linked list and display the data
    StudentRecord *start = head;
    if (!start)
    {
        cout << "No Data!" << endl;
        return;
    }

    while(start)
    {
        cout << start -> firstName << endl;
        cout << start -> lastName << endl;
        cout << setw(8)<<setfill('0')<<start -> oduUin << endl;
        cout << start -> dateOfBirth << endl;
        cout << start -> gpa << endl << endl;
        start = start -> next;
    }
}

void backDisplay_data()
{
    cout << endl << endl << "Back listing all student records: " << endl;
    cout << "---------------------------" << endl;
    // We will create a node named start and will iterate it backward through the whole linked list and display the data
    StudentRecord *start = last;
    if (!start)
    {
        cout << "No Data!" << endl;
        return;
    }

    while(start)
    {
        cout << start -> firstName << endl;
        cout << start -> lastName << endl;
        cout << setw(8)<<setfill('0')<<start -> oduUin << endl;
        cout << start -> dateOfBirth << endl;
        cout << start -> gpa << endl << endl;
        start=start->prev;
    }
}

StudentRecord *get_data(char choice)
{
    //creating a temporary node in which we will store all the student records and return the temporary node in the end of the function
    StudentRecord *rec = new StudentRecord;
    cout << endl;
    cout << "You chose option #"<<choice<<"." << endl;
    cout << "What is the student's first name?: ";
    cin >> rec->firstName;
    cout << "What is the student's last name?: ";
    cin >> rec->lastName;
    cout << "What is the student's uin?: ";
    cin >> rec->oduUin;
    cout << "What is the student's date of birth?: ";
    cin >> rec->dateOfBirth;
    cout << "What is the student's GPA?: ";
    cin >> rec->gpa;
    return rec;
}

void add_data(StudentRecord *current)
{
    // We will store the address of the present head node in the next field of the current node and later we will make the current node as head node
    current->next=head;  // store the address of the pointer head(second field)
    if (head) head->prev=current;
    else last=current;
    current->prev=NULL;
    head = current;
}

void add_data(int position)
{
    if (position==1)
    {
        StudentRecord *current = get_data('2');
        add_data(current);
        return;
    }
    else if (position<1)
    {
        cout<<"\nInvalid position!"<<endl;
        return;
    }
    else
    {
        StudentRecord *start = head;
        for (int i=0;i<position-2;i++)
        {
            if ((start) && (start->next))
            {
                start=start->next;
            }
            else
            {
                cout<<"\nInvalid position!"<<endl;
                return;
            }
        }
        if (start)
        {
            StudentRecord *current = get_data('2');
            current->next=start->next;
            current->prev=start;
            start->next=current;
            if (current->next) current->next->prev=current;
            else last=current;
        }
        else
        {
            cout<<"\nInvalid position!"<<endl;
            return;
        }
    }
}

void search(int key)
{
    StudentRecord *current = head;
    // We will iterate the head through the linked list until it finds the required variable or until the end of linked list
    while (current != NULL)
    {
        if (current->oduUin == key)
        {
            cout<<"key found"<<endl;
            cout<<"first name = "<<current->firstName<<endl;
            cout<<"last name = "<<current->lastName<<endl;
            cout<<"date of birth = "<<current->dateOfBirth<<endl;
            cout<<"gpa = "<<current->gpa<<endl;
            return;
        }
        current = current->next;
    }
    cout<<"Key not found"<<endl;
}

void processMenu()
{
    // creating current node for StudentRecord struct
    StudentRecord *current = NULL;
    int ser;
    int position;
    char choice = 0;
    while(true)
    {
        cout << endl <<"What would you like to do?" << endl;
        cout <<"==========================" << endl;
        cout << "1. Enter a student record. " << endl;
        cout << "2. Insert a student record at a particular position. " << endl;
        cout << "3. List all student records. " << endl;
        cout << "4. Exit program. " <<endl;
        cout << "5. Search. " << endl;

        cin >> choice;
        while(cin.get() != '\n');
        if(choice == '1')
        {
            current = get_data(choice);
            add_data(current);
        }
        else if(choice == '2')
        {
            cout << "Enter the position at which you want to insert your record :"<<flush;
            cin >> position;
            add_data(position);
        }
        else if(choice == '3')
        {
            display_data();
            //backDisplay_data();
        }
        else if (choice == '4')
        {
            free_list();
            return;
        }
        else if (choice == '5')
        {
            cout<<"Enter student uin to search for records"<<endl;
            cin>>ser;
            search(ser);
        }
        else
        {
            cout << "Allowed Selections are 1, 2, 3, 4 and 5!" << endl;
        }
    }
}

int main()
{
    // Program starts execution from main block
    cout << "Student Record Program." << endl << endl;
    processMenu();
    // calling process function which inturn calls create and display functions
    system("pause");
    return 0;
}
