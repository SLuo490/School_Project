/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 135
 Assignment: Project 2: Task: B
 
 This program conducts a translation from a DNA strand to the corresponding amino-acid chain.
  */


#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

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

string dictionary_read(ifstream &diction, string base) {
    string key, value;
    diction.clear(); // reset error state
    diction.seekg(0); // return file pointer to the beginning
    while (diction >> key >> value) {
        if (key == base)
        {
            return value;
        }
    }
    return 0;
}

int main ()
{
    
    //opens the txt file
    ifstream fin("dna2b.txt");
    
    //if it fails print file cannot read/open/dne
    if (fin.fail())
    {
       cerr << "File cannot be read, opened, or does not exist.\n";
       exit(1);
    }
    
    //opens the txt file
    ifstream diction("codons.tsv");
    
    //if it fails print file cannot read/open/dne
    if (fin.fail())
    {
      cerr << "File cannot be read, opened, or does not exist.\n";
      exit(1);
    }
    
    string strand;
    
    while(getline(fin, strand))
    {
        string m_RNA = DNA_to_mRNA(strand);
        bool encode = false;
        
        for (int i = 0; i < m_RNA.length(); i += 3)
        {
            if (dictionary_read(diction, m_RNA.substr(i, 3)) == "Stop")
            {
                encode = false;
            }
            if (dictionary_read(diction, m_RNA.substr(i, 3)) == "Met")
            {
                encode = true;
            }
            if (encode == true)
            {
                cout << dictionary_read(diction, m_RNA.substr(i , 3));
            }
            if ((encode == true) && dictionary_read(diction, m_RNA.substr(( i + 3) , 3)) != "Stop")
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    diction.close();
    fin.close();
    return 0;
}



