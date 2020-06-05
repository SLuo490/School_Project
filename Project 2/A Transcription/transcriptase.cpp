/*
Author: Shi Tao Luo
Course: CSCI 136
Instructor: Maryash
Assignment: Project 2:A

This program transcript a DNAbase to RNAbase
*/


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

char DNAbase_to_mRNAbase(char c);
string DNA_to_mRNA(string strand);

int main ()
{
    
    //opens the txt file
    ifstream fin("dna.txt");
    
    //if it fails print file cannot read/open/dne
    if (fin.fail())
    {
       cerr << "File cannot be read, opened, or does not exist.\n";
       exit(1);
    }
    
    string strand;
    
    while(getline(fin, strand)) {
       cout << DNA_to_mRNA(strand) << endl;
    }
    
    fin.close();
    return 0;
}


//A function to convert DNAbase characters to MRAbase
char DNAbase_to_mRNAbase(char c)
{
    char upper_c = toupper(c);
    if (upper_c == 'A')
    {
        return 'U';
    }
    if (upper_c == 'T')
    {
        return 'A';
    }
    if (upper_c == 'C')
    {
        return 'G';
    }
    if (upper_c == 'G')
    {
        return 'C';
    }
    return 0;
}



//function to convert a whole DNA base strand to RNA base strand usiing previus function
string DNA_to_mRNA(string strand)
{
    string new_strand;
    
    //loops through each character to transcript the DNA base
    for (int i = 0; i < strand.length(); i++)
    {
        new_strand += DNAbase_to_mRNAbase(strand[i]);
    }
    return new_strand;
}



