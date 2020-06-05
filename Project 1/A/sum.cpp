/*
 Name: Shi Tao Luo
 course: csci-13500
 Assignment: project 1 A
 
 This program uses input redirection and add the sum of the integers in the txt file.
 */






#include <iostream>
using namespace std;


int main() {
    
    int s;
    int total = 0;
    
    while(cin >> s)   // While the reading operation is a success
    {
        total += s;  // add the sum of integers in txt file
    }
    cout << total << endl;  // print the total
}



