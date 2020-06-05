/*
  Name: Shi Tao Luo
  course: csci-13600
  Instructio: Maryash
  Assignment: Project 1:B
  
 This program create calculator using only addition and subtraction while also using input redirection
  */
 
#include <iostream>

using namespace std;

int main()
{
    int sum;
    cin >> sum;
    char op;
    int total = sum;
    
    while (cin >> op >> sum)
    {
        
        if (op == '+')                //adds the total if there is an addition sign
        {
            total += sum;
        }
        else if (op == '-')        //subtract the total if there is an subtraction sign
        {
            total -= sum;
        }
        else
        {
            return 0;
        }
    
    }
    cout << total << endl;    
    return 0;
}
