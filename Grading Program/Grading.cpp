
//This program converts a number grade (0-100) to a letter grade (A,B,C,D,F)


#include <iostream>
using namespace std;

int main() {
    
    //asks user for their letter grade
    int number_grade;
    cout << "Enter your grade (0-100): ";
    cin >> number_grade;
    
    //Every interval of 10, the letter grade changes
   
    /*
    100-90 = A
    89-80 = B
    79-70 = C
    69-60 = D
    59-0 = F
    */
    
    switch (number_grade / 10) {
        case 10:
            cout << "A" << endl;
            break;
        case 9:
            cout << "A" << endl;
            break;
        case 8:
            cout << "B" << endl;
            break;
        case 7:
            cout << "C" << endl;
            break;
        case 6:
            cout << "D" << endl;
            break;

        default:
            cout << "Grade F" << endl;
            break;
    }
    return 0;
}

