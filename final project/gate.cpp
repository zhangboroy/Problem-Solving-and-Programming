#include <iostream>
#include <iomanip>
#include "gate.h"

//the main entrance
const Lot entrance;
//initiate the accounts
int Gate::dollar1=0;
int Gate::dollar5=0;
int Gate::dollar10=0;
int Gate::dollar20=0;
int Gate::quarter=0;

Gate::Gate()
{
    name=' ';
    positionX=0;
    positionY=0;
    lot=0;
    capacity=0;
}

//read the data of the gates from a file
void Gate::Setup(int lotsNumber, Lot *lot1, int cashNumber, const Cash *cash1, ifstream &inData)
{
    inData>>name;
    inData>>positionX;
    inData>>positionY;
    for (int i=0;i<cashNumber;i++)
    {
        if (cash1[i].GetName()=="One") dollar1=cash1[i].GetNumber();
        else if (cash1[i].GetName()=="Five") dollar5=cash1[i].GetNumber();
        else if (cash1[i].GetName()=="Ten") dollar10=cash1[i].GetNumber();
        else if (cash1[i].GetName()=="Twenty") dollar20=cash1[i].GetNumber();
        else if (cash1[i].GetName()=="Quarter") quarter=cash1[i].GetNumber();
    }
    //create an array for the displayed information of lots
    lot=new Lot*[lotsNumber];
    for (int i=0;i<lotsNumber;i++)
    {
        //the displayed information of lots only hold the memory address of the lots and shares the same information with the lots
        lot[i]=&lot1[i];
        capacity+=lot1[i].GetCapacity();
    }
}

//output the account detail
void Gate::PrintAccount()
{
    cout<<'\n'<<setw(34)<<"Parking Machine Accounts\n"
        <<setw(3)<<"No."<<setw(12)<<"Bill Name"<<setw(13)<<"Bill Count"<<setw(14)<<"Cost(in $)\n"
        <<setw(2)<<1<<setw(13)<<"1 Dollar"<<setw(9)<<dollar1<<setw(15)<<1.0*dollar1<<'\n'
        <<setw(2)<<2<<setw(13)<<"5 Dollar"<<setw(9)<<dollar5<<setw(15)<<5.0*dollar5<<'\n'
        <<setw(2)<<3<<setw(13)<<"10 Dollar"<<setw(9)<<dollar10<<setw(15)<<10.0*dollar10<<'\n'
        <<setw(2)<<4<<setw(13)<<"20 Dollar"<<setw(9)<<dollar20<<setw(15)<<20.0*dollar20<<'\n'
        <<setw(2)<<5<<setw(13)<<"1 Quarter"<<setw(9)<<quarter<<setw(15)<<0.25*quarter<<endl;
}

//calculate the cost of the chosen lot
float Gate::Cost(int i, int totalSpots) const
{
    float cost=25;
    cost-=(*lot[i]).DistanceFrom(entrance)*2.5;
    if (totalSpots<50) cost+=5.75;
    if (totalSpots<25) cost+=7.25;
    return cost;
}

//output the information of all Parking Lots
void Gate::DisplayLots(int lotsNumber, int totalSpots)
{
    cout<<'\n'<<setw(32)<<"Gate-"<<name<<": Lot Information\n"
        <<"Parking Lot   Maximum Capacity   Available spots   Cost   Distance in meters\n"
        <<"                                                  $DD.CC   from current Gate"<<endl;
    Lot *tempLot=0;
    for (int i=0;i<lotsNumber;i++)
    {
        for (int j=lotsNumber-1;j>i;j--)
        {
            //check if the distance from the gate to lot[j] less than to lot[j-1]
            if ((*lot[j]).DistanceFrom(*this)<(*lot[j-1]).DistanceFrom(*this))
            {
                //swap lot[j] and lot[j-1], which means changing the display sequence of lot[j] and lot[j-1]
                tempLot=lot[j];
                lot[j]=lot[j-1];
                lot[j-1]=tempLot;
            }
        }
        //output the information of lot[i]
        cout<<setw(6)<<(*lot[i]).GetName()<<setw(17)<<(*lot[i]).GetCapacity()<<setw(18)<<(*lot[i]).GetCapacity()-(*lot[i]).GetUsedSpots()<<setw(15)<<Cost(i,totalSpots)<<setw(12)<<(*lot[i]).DistanceFrom(*this)*10<<endl;
    }

    cout<<setw(8)<<"Total"<<setw(15)<<capacity<<setw(18)<<totalSpots<<endl;
}

//charge the visitor for the parking fee
void Gate::Charge(char lotName, float cost)
{
    //initiate the money paid by visitor
    float money=0;
    //initiate the bill type chosen by visitor
    string bill="";
    cout<<"\nLot-"<<lotName<<" is chosen and the cost is: $"<<cost<<endl;
    //output the total money received and the acceptable cash type list, ask the visitor to pay, until enough money is received
    do
    {
        cout<<"\nTotal cash received: $"<<money<<'\n'
            <<"0:  1 dollar bill\n"
            <<"1:  5 dollar bill\n"
            <<"2: 10 dollar bill\n"
            <<"3: 20 dollar bill\n"
            <<"4:  1 quarter coin\n"
            <<"Please insert cash: "<<flush;
        getline(cin,bill);
        //update the money received and the account, then output the account
        if (bill=="0")
        {
            money+=1;
            dollar1++;
            Gate::PrintAccount();
        }
        else if (bill=="1")
        {
            money+=5;
            dollar5++;
            Gate::PrintAccount();
        }
        else if (bill=="2")
        {
            money+=10;
            dollar10++;
            Gate::PrintAccount();
        }
        else if (bill=="3")
        {
            money+=20;
            dollar20++;
            Gate::PrintAccount();
        }
        else if (bill=="4")
        {
            money+=0.25;
            quarter++;
            Gate::PrintAccount();
        }
    }
    while (money<cost);

    if (money==cost) cout<<"Thank you - Gate is now open"<<endl;
    else
    {
        //give change to the visitor and update the account
        float change=money-cost;
        cout<<"Thank you - Gate is now open, your change is: $"<<change<<endl;
        int dollar20Number=int(change/20);
        dollar20-=dollar20Number;
        int dollar10Number=int((change-20*dollar20Number)/10);
        dollar10-=dollar10Number;
        int dollar5Number=int((change-20*dollar20Number-10*dollar10Number)/5);
        dollar5-=dollar5Number;
        int dollar1Number=int(change-20*dollar20Number-10*dollar10Number-5*dollar5Number);
        dollar1-=dollar1Number;
        int quarterNumber=(change-20*dollar20Number-10*dollar10Number-5*dollar5Number-dollar1Number)*4;
        quarter-=quarterNumber;
    }
}

//ask the visitor to choose the Parking Lot
void Gate::ChooseParkingLot(int lotsNumber)
{
    //initiate the present total available spots
    int totalSpots=0;
    //calculate the present total available spots
    for (int i=0;i<lotsNumber;i++)
    {
        totalSpots+=(*lot[i]).GetCapacity()-(*lot[i]).GetUsedSpots();
    }
    if (totalSpots==0)
    {
        cout<<"\nAll parking Lots are full - Sorry!!"<<endl;
        return;
    }

    //output the information of all Parking Lots
    DisplayLots(lotsNumber, totalSpots);
    //initiate the Parking Lot choosing criteria selected by visitor
    string choice="";
    //output the available Parking Lot choosing criteria and ask the visitor to choose until the choice is valid
    do
    {
        cout<<"\nPlease enter your choice of Parking Lot:\n"
            <<"0: Choose the nearest Parking Lot from here\n"
            <<"1: Choose the cheapest Parking Lot\n"
            <<"Your Choice: "<<flush;
        getline(cin,choice);
    }
    while ((choice!="0") && (choice!="1"));

    if (choice=="0")
    {
        for (int i=0;i<lotsNumber;i++)
        {
            //select the first non-full lot from the top
            if ((*lot[i]).GetCapacity()>(*lot[i]).GetUsedSpots())
            {
                //charge the visitor for the parking fee
                Charge((*lot[i]).GetName(),Cost(i,totalSpots));
                //set a spot for the visitor
                (*lot[i]).FillUsedSpots();
                //output the information of all Parking Lots
                DisplayLots(lotsNumber, totalSpots-1);
                return;
            }
        }
    }

    if (choice=="1")
    {
        //initiate the cost, name and serial for the selected Parking Lot
        float cost=999;
        char lotName=127;
        int serial;
        for (int i=0;i<lotsNumber;i++)
        {
            //check if lot[i] is not full and its cost is less or its cost is the same as present selected one but its name is at the front
            if (((*lot[i]).GetCapacity()>(*lot[i]).GetUsedSpots()) && ((Cost(i,totalSpots)<cost) || ((Cost(i,totalSpots)==cost) && ((*lot[i]).GetName()<lotName))))
            {
                //update the cost, name and serial for the selected Parking Lot
                cost=Cost(i,totalSpots);
                lotName=(*lot[i]).GetName();
                serial=i;
            }
        }
        //charge the visitor for the parking fee
        Charge(lotName,cost);
        //set a spot for the visitor
        (*lot[serial]).FillUsedSpots();
        //output the information of all Parking Lots
        DisplayLots(lotsNumber, totalSpots-1);
    }
}
