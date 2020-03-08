/*
 This program makes a calculator that reads addition/subtraction/and squared number
 from a txt file and calculate the total.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int total = 0;
    int num;
    char op;
    char pending_Op = '+';
    cin >> num;
    
    //read each character
    while (cin >> op)
    {
         //if operator is ^ then just read the number and save it
        if (op == '^')
        {
            num = num * num;
            cin >> op;
        }
        //if next operator is + then add to total
        if (pending_Op == '+')
        {
            total += num;
        }
        //if next operator is - then subtract to total
        else if (pending_Op == '-')
        {
            total -= num;
        }
        
        //if op is + then add with the saved squared number else subtract
        if ((op == '+') || (op == '-'))
        {
            pending_Op = op;
            cin >> num;
        }
        //skip to the next formula
        if (op == ';')
        {
            cout << total << endl;
            total = 0;
            cin >> num;
            pending_Op = '+';
        }
    }
    return 0;
}


