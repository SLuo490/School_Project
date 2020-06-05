/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 135
 Assignment: Project 2: Task: C

 This program calculates the hamming distance between two strings.
  */

#include <iostream>
#include <fstream>
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


//function to convert mrna strand to amino acid by reading the codon file
string amino_acid (ifstream &diction, string m_RNA)
{
    bool encode = false;
    string amino_acid;

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
            amino_acid = amino_acid + dictionary_read(diction, m_RNA.substr(i , 3));
        }
    }
    return amino_acid;
}



//function to measure the hamming distance
int hamming (string dna1, string dna2)
{
    int counter = 0;
    for (int i = 0; i < dna1.length(); i++)
    {
        if (dna1[i] != dna2[i])
        {
            counter += 1;
        }
    }
    return counter;
}


int main ()
{

    //opens the txt file
    ifstream fin("mutations.txt");

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


    
    /*
     converts both dna_strand to m_rna to amino
     then compares the amino strands
     if the first amino strand is not equal to the second amino strand,
     print the hammind distance and yes
     if not, then print the hammind distance and no
     */
    string dna_strand_1;
    string dna_strand_2;

    while (getline(fin,dna_strand_1))
    {
        getline(fin,dna_strand_2);
        
        string m_RNA_strand_1 = DNA_to_mRNA(dna_strand_1);
        string m_RNA_strand_2 = DNA_to_mRNA(dna_strand_2);

        string amino_strand_1 = amino_acid(diction, m_RNA_strand_1);
        string amino_strand_2 = amino_acid(diction, m_RNA_strand_2);

        if (amino_strand_1 != amino_strand_2)
        {
            cout << hamming (dna_strand_1, dna_strand_2) << " " << "yes" << endl;
        }
        if (amino_strand_1 == amino_strand_2)
        {
            cout << hamming (dna_strand_1, dna_strand_2) << " " << "no" << endl;
        }
    }
    
    diction.close();
    fin.close();
    return 0;
}




