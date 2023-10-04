/*
Write a program that uses a structure to store the following information
for a particular month at the local airport:
Total number of planes that landed
Total number of planes that departed
Greatest number of planes that landed in a given day that month
Least number of planes that landed in a given day that month

The program should have an array of twelve structures to hold travel
information for the entire year. The program should prompt the user to
enter data for each month. Once all data is entered, the program should
calculate and output the average monthly number of landing planes, the
average monthly number of departing planes, the total number of
landing and departing planes for the year, and the greatest and least
number of planes that landed on any one day (and which month it
occurred in). */

#include <iostream>

using namespace std;

int main()
{
    struct data
    {
        int planesLanded, planesDeparted, planesGreatest, planesLeast;
    };
    data airportdata[12];

    for (int i=0; i<12; i++)
    {
       cout<<"Enter total amount of planes that landed for month "<<(i+1)<<": ";
       cin>>airportdata[i].planesLanded;

       cout<<"Enter total amount of planes that departed for month "<<(i+1)<<": ";
       cin>>airportdata[i].planesDeparted;

       cout<<"Enter greatest amount of planes that landed in a given day for month "<<(i+1)<<": ";
       cin>>airportdata[i].planesGreatest;

       cout<<"Enter least amount of planes that landed in a given day for month "<<(i+1)<<": ";
       cin>>airportdata[i].planesLeast;
    }
    cout<<"\n\n\n"<<endl;

    int total=0;
    for (int i=0; i<12; i++)
    {
        total+=airportdata[i].planesLanded;
    }
    int averagelanded=total/12;
    cout<<"Average monthly amount of landing planes: "<<averagelanded<<endl;



    total=0;
    for (int i=0; i<12; i++)
    {
        total+=airportdata[i].planesDeparted;
    }
    int averagedeparting=total/12;
    cout<<"Average monthly amount of departing planes: "<<averagedeparting<<endl;



    total=0;
    for (int i=0; i<12; i++)
    {
        total+=airportdata[i].planesLanded+airportdata[i].planesDeparted;
        
    }
    cout<<"Total amount of departing and landing planes for the year: "<<total<<endl;



    int greatest=airportdata[0].planesGreatest;
    int greatestmonth=1;
    for (int i=1; i<12; i++)
    {
        if (airportdata[i].planesGreatest>greatest)
        {
            greatest=airportdata[i].planesGreatest;
            greatestmonth=i+1;
        }
    }
    cout<<"Greatest amount of landing planes ("<<greatest<<") occurred in month "<< greatestmonth<<endl;

    int least=airportdata[0].planesLeast;
    int leastmonth=1;
    for (int i=1; i<12; i++)
    {
        if (airportdata[i].planesLeast<least)
        {
            least=airportdata[i].planesLeast;
            leastmonth=i+1;
        }
    }
    cout<<"Least amount of landing planes ("<<least<<") occurred in month: "<< leastmonth<<endl;

    return 0;
}