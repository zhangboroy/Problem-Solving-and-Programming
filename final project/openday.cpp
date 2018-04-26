#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "openday.h"

OpenDay::OpenDay()
{
    srand(time(0));
    //initiate total emergency car number and initial money
    emergencyCars=0;
    initialMoney=0;

    //open the file to read the lots information
    inData.open("lots.txt");
    inData>>lotsNumber;
    //create enough lots
    lot=new Lot[lotsNumber];
    //read the lot information 1 by 1 and update the total emergency car number
    for (int i=0;i<lotsNumber;i++)
    {
        emergencyCars+=lot[i].setup(inData);
    }
    inData.close();

    //open the file to read the parking account information
    inData.open("parking_account.txt");
    inData>>cashNumber;
    //create enough cash types
    cash=new Cash[cashNumber];
    //read the cash type information 1 by 1 and update the initial money
    for (int i=0;i<cashNumber;i++)
    {
        initialMoney+=cash[i].ReadParkingAccount(inData);
    }
    inData.close();

    //open the file to read the gates information
    inData.open("gates.txt");
    inData>>gateNumber;
    //create enough gates
    gate=new Gate[gateNumber];
    //read the gate information 1 by 1
    for (int i=0;i<gateNumber;i++)
    {
        gate[i].Setup(lotsNumber,lot,cashNumber,cash,inData);
    }
    inData.close();
}

//start a new open day
void OpenDay::Start()
{
    cout<<fixed<<showpoint<<setprecision(2);
    string choice;
    //serve the visitors 1 by 1 until exit is chosen
    do
    {
        //output the account detail
        Gate::PrintAccount();

        //output the available Gates list and ask the visitor to choose until the choice is valid
        do
        {
            choice="";
            cout<<"\nPlease choose Gate:\n";
            for (int i=0;i<gateNumber;i++)
            {
                cout<<i+1<<": Gate-"<<gate[i].GetName()<<'\n';
            }
            cout<<gateNumber+1<<": Exit\n"
                <<"Your Choice: "<<flush;
            getline(cin,choice);
        }
        while ((atoi(choice.c_str())<1) || (atoi(choice.c_str())>gateNumber+1));

        //ask the visitor to choose the Parking Lot
        if (atoi(choice.c_str())!=gateNumber+1) gate[atoi(choice.c_str())-1].ChooseParkingLot(lotsNumber);
    }
    while (atoi(choice.c_str())!=gateNumber+1);
}

//end the open day and output the information needed to a file
void OpenDay::End()
{
    //initiate the visitor car number
    int visitorCars=-emergencyCars;
    //calculate the visitor car number
    for (int i=0;i<lotsNumber;i++)
    {
        visitorCars+=lot[i].GetUsedSpots();
    }
    //calculate the total money left
    float totalMoney=0.25*Gate::GetQuarter()+Gate::GetDollar1()+5*Gate::GetDollar5()+10*Gate::GetDollar10()+20*Gate::GetDollar20();
    ofstream outData;
    outData.open("parking_information.txt",ios::trunc);
    outData<<"Total Visited Cars: "<<visitorCars<<endl
           <<"Total Emergency Cars: "<<emergencyCars<<endl
           <<"Total Cash at the End of Day: $"<<fixed<<showpoint<<setprecision(2)<<totalMoney<<endl
           <<"Total Amount Earned by the Parking Machine: $"<<totalMoney-initialMoney<<endl;
    outData.close();
}
