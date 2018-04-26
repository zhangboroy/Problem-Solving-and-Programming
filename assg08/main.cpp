#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int number=5000;

//generate a random number in 0-99999 to each number of the list
void GenerateRandomList(int list0[])
{
    for (int i=0;i<number;i++)
    {
        list0[i]=(rand()%100000);
    }
}

//swap 2 numbers
void Swap(int &a, int &b, int &itemAssignment)
{
    int temp=a;
    a=b;
    b=temp;
    itemAssignment+=3;
}

//sort the list with bubble sort method
void BubbleSort(int list0[])
{
    int comparison=0;
    int itemAssignment=0;
    for (int i=0;i<number-1;i++)
    {
        //make list0[i]=min(list0[i],list0[i+1],...,list0[n])
        for (int j=number-1;j>i;j--)
        {
            comparison++;
            //make list0[j-1]<=list0[j]
            if (list0[j]<list0[j-1])
            {
                Swap(list0[j],list0[j-1],itemAssignment);
            }
        }
    }
    cout<<"Bubble sort comparison number: "<<comparison<<endl;
    cout<<"Bubble sort item assignment number: "<<itemAssignment<<endl<<endl;;
}

//sort the list with selection sort method
void SelectionSort(int list0[])
{
    int comparison=0;
    int itemAssignment=0;
    int minimum;
    for (int i=0;i<number-1;i++)
    {
        //make list0[i]=min(list0[i],list0[i+1],...,list0[n])
        minimum=i;
        for (int j=i+1;j<number;j++)
        {
            comparison++;
            //select the minimum from list0[i] to list0[n]
            if (list0[j]<list0[minimum])
            {
                minimum=j;
            }
        }

        if (minimum!=i) Swap(list0[minimum],list0[i],itemAssignment);
    }
    cout<<"Selection sort comparison number: "<<comparison<<endl;
    cout<<"Selection sort item assignment number: "<<itemAssignment<<endl;
}

int main()
{
    srand(time(0));
    int list1[number];
    int list2[number];

    GenerateRandomList(list1);
    //make list2 and list1 identical arrays
    for (int i=0;i<number;i++)
    {
        list2[i]=list1[i];
    }

    BubbleSort(list1);
    SelectionSort(list2);

    return 0;
}
