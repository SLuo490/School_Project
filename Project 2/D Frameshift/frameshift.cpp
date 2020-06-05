/*
 Name: Shi Tao Luo
 Professor: Maryash
 Course: CSCI 135
 Assignment: Project 2: Task: D

 This program compares the result of task B with the mutated strands.
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


/*
 Function that compute the frameshift
 */

void frame_shift(ifstream &diction, string m_Rna, int index)
{
    int counter = 0;
    bool encode = false;

    for(int i = index; i < m_Rna.length(); i += 3)
    {

        if(counter <= 1)
        {

            if(dictionary_read(diction, m_Rna.substr(i , 3)) == "Met")
            {

                encode = true;
                counter += 1;

            }
            
            if((dictionary_read(diction, m_Rna.substr(i , 3)) == "Stop") || (counter > 1))
            {

                encode = false;

            }
            
            if(encode == true)
            {

                cout << dictionary_read(diction, m_Rna.substr(i , 3));
                
            }
            
            if((encode == true) && dictionary_read(diction, m_Rna.substr(( i + 3) , 3)) != "Stop")
            {

                cout << "-";

            }
            
        }
        
    }
    cout << endl;
    
}


int main ()
{

    //opens the txt file
    ifstream fin("frameshift_mutations.txt");

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

    
    //Compares the dna_strand 1 and 2 for the frameshift
    string dna_strand_1;
    string dna_strand_2;

    while (getline(fin,dna_strand_1))
    {
        getline(fin,dna_strand_2);
        
        string m_Rna = DNA_to_mRNA(dna_strand_1);
        string mutate_strand = DNA_to_mRNA(dna_strand_2);
        
        
        //compute the frameshift
        int start = mutate_strand.find("AUG",0);
        
        
        frame_shift(diction, m_Rna, 0);
        frame_shift(diction, mutate_strand, start);
        
    }
    diction.close();
    fin.close();
    return 0;
}

