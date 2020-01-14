/*
Ryan Mitchell
COP 2334
Prof. Pittman
Assignment 3
3/8/2018
Chap 11 Problem 8 (I think, sorry it's 11:20PM)

*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Soda //Creates a structure named Soda
{
    string SodaName;
    double SodaCost;
    int SodaAmount;
};

double MoneyInsert(double, int, Soda *, double); //List of function prototypes. This one allows us to return a double for money
void SodaArray(Soda *); //Puts the soda into the array
void SodaMachine(Soda *); //Simulates a machine

int main()
{
    const int Size = 5; //Size 5 constant.
    Soda Soda[Size]; //Creates a data type structure and creates the array of 5 elements
    SodaArray(Soda); //Calls for the function
    SodaMachine(Soda);

    return 0;
}

void SodaArray(Soda *Soda) //Puts info into soda array
{
    Soda[0].SodaName = {"Cola"};
    Soda[0].SodaCost = .75;
    Soda[0].SodaAmount = 20;

    Soda[1].SodaName = {"Root Beer"};
    Soda[1].SodaCost = .75;
    Soda[1].SodaAmount = 20;

    Soda[2].SodaName = {"Lemon Lime"};
    Soda[2].SodaCost = .75;
    Soda[2].SodaAmount = 20;

    Soda[3].SodaName = {"Grape Soda"};
    Soda[3].SodaCost = .8;
    Soda[3].SodaAmount = 20;

    Soda[4].SodaName = {"Cream Soda"};
    Soda[4].SodaCost = .8;
    Soda[4].SodaAmount = 20;

}

void SodaMachine(Soda* Soda)
{
    int choice;
    double MachineEarnings =0;
    const int Size = 5;
    double Money;

    do
    {
        cout << "Welcome to the Drink Machine simulator,\nWhat would you like to drink?"<<endl;
        cout << "Drink" << setw(15) << "Price" << setw(15) << "Amount Left" << endl;
        for (int i = 0; i < Size; i++)
        {
            cout << i+1 << " "<< setprecision(2) << fixed << Soda[i].SodaName << setw(15) << "$" << setw(5)<< left << Soda[i].SodaCost << right << setw(15) << Soda[i].SodaAmount<<endl;
        }
        cout << "Choose between 1 and 5 or press 6 to quit." << endl;
        cin >> choice;

        switch(choice) //Creates the menu
        {
        case 1:
            {
                cout << "The cost for a " << Soda[choice-1].SodaName << " is " << Soda[choice-1].SodaCost << endl; //[choice-1] was the easiest way to access the element w/ the choice
               if (Soda[choice-1].SodaAmount > 0)
               {
                MachineEarnings = MoneyInsert(Money, choice, Soda, MachineEarnings); //Totals up machine earnings AND runs the function.
               }
               else
               {
                   cout << "Sorry, we're currently sold out!" << endl; //Else we're sold out of soda.
                   system("CLS");
               }

                break;
            }
        case 2:
            {
                cout << "The cost for a " << Soda[choice-1].SodaName << " is " << Soda[choice-1].SodaCost << endl;
                             if (Soda[choice-1].SodaAmount > 0)
               {
                MachineEarnings = MoneyInsert(Money, choice, Soda, MachineEarnings);
               }
               else
               {
                   cout << "Sorry, we're currently sold out!" << endl;
                   system("CLS");
               }
                break;
            }
        case 3:
            {
                cout << "The cost for a " << Soda[choice-1].SodaName << " is " << Soda[choice-1].SodaCost << endl;
                               if (Soda[choice-1].SodaAmount > 0)
               {
                MachineEarnings = MoneyInsert(Money, choice, Soda, MachineEarnings);
               }
               else
               {
                   cout << "Sorry, we're currently sold out!" << endl;
                   system("CLS");
               }
                break;
            }
        case 4:
            {
                cout << "The cost for a " << Soda[choice-1].SodaName << " is " << Soda[choice-1].SodaCost << endl;
                              if (Soda[choice-1].SodaAmount > 0)
               {
                MachineEarnings = MoneyInsert(Money, choice, Soda, MachineEarnings);
               }
               else
               {
                   cout << "Sorry, we're currently sold out!" << endl;
                   system("CLS");
               }
                break;
            }
        case 5:
            {
                cout << "The cost for a " << Soda[choice-1].SodaName << " is " << Soda[choice-1].SodaCost << endl;
                              if (Soda[choice-1].SodaAmount > 0)
               {
                MachineEarnings = MoneyInsert(Money, choice, Soda, MachineEarnings);
               }
               else
               {
                   cout << "Sorry, we're currently sold out!" << endl;
                   system("CLS");
               }
                break;
            }
        case 6:
            {
                cout << "This machine has earned $" << MachineEarnings << endl;
                cout << "Quitting the program..." << endl;
                exit(0); //exits the program
                break;
            }
        default:
            {

                while (choice < 1 || choice >6)
                {
                    cout << "Please enter in a valid number 1 through 6." << endl;
                    cin >> choice;
                }
            }
        }
    }
    while(choice != 6);


}

double MoneyInsert(double Money, int choice, Soda* Soda, double Earnings)
{
    Money=0;
    double ChangeBack = 0;
    double MoneyInserted = 0;

    do
    {
        cout << "Please insert $" << Soda[choice-1].SodaCost-MoneyInserted << "\nWe only accept $1 bills and change." << endl;
        cin >> Money;
        MoneyInserted = MoneyInserted + Money;
    }
    while (Money <0 || Money > 1 || MoneyInserted < Soda[choice-1].SodaCost);
    ChangeBack=MoneyInserted-Soda[choice-1].SodaCost;    //Calculates change back
    cout << "Your change back is $" << ChangeBack << endl;
    system("PAUSE");
    system("CLS");
    Earnings = Earnings + Soda[choice-1].SodaCost;
    Soda[choice-1].SodaAmount--; //deducts soda amount
    return Earnings;// Soda[choice-1].SodaAmount; //returns two variables to us.

}
