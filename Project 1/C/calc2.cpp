/*
 Name: Shi Tao Luo
 course: csci-13600
 Instructio: Maryash
 Assignment: Project 1:C
 
This program create calculator using only addition and subtraction while also using input redirection with multiple formula
 */


#include <iostream>
using namespace std;

int main()
{
    int num;
    int total = 0;
    char op;
    
    cin >> total;

    while (cin >> op >> num)            //Read each character in txt file in a while loop
    {

        if (op == ';')                  //if operator is ;, then print out the sum, then set total to num
        {
            cout << total << endl;
            total = num;
        }
        else if (op == '+')             //if operator is +, then add the numbers together
        {
            total += num;
        }
        else if (op == '-')             //if operator is -, then subtract the numbers togehter

        {
            total -= num;
        }
        else                            //if there is no other operator, close the program
        {
            return 0;
        }
    }
    
    cout << total << endl;              //print the total then end program
    return 0;
}

