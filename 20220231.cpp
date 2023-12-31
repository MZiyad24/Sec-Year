/*
File:A3_Sheet2Pb1_20220231
Purpose:Giving labels
Author: Omar Mohamed Ahmed
ID:20220231
Section:s17
Date:3/12/2023
*/
//----------------
#include <iostream>
#include <string>
#include <sstream>
#include "fstream"
#include "../oooooooo.h"
using namespace std;
//constructor
LabelGenerator::LabelGenerator() :currentIndex(0){}
LabelGenerator::LabelGenerator(const string& prefix, int initialIndex)
        :prefix(prefix), currentIndex(initialIndex) {}

//Destructor
LabelGenerator::~LabelGenerator() {}


// Generates the next label in the sequence and returns it.
string LabelGenerator::nextLabel() {
    // Format the label using the prefix and current index.
    string label = formatLabel();

    // Increment the index for the next call.
    currentIndex++;

    return label;
}
// Private method to format the label based on the prefix and current index.
string LabelGenerator::formatLabel() {
    string currentIndexString = to_string(currentIndex);
    string oss = prefix + currentIndexString;
    return oss;
}
FileLabelGenerator::FileLabelGenerator( const string &prefix, int idx,string file)
        : pref(prefix), idx(idx), filename(file) {}

string FileLabelGenerator::nextLabel() {
    string label = formatLabel() ;
    idx++;
    count++;
    return label;
}
string FileLabelGenerator::formatLabel() {
    string currentIndexString = to_string(idx);
    ifstream file(filename);
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            file_lines.push_back(line);
        }
        string oss = pref +' '+currentIndexString+' '+file_lines[count]+'.';
        return oss;
    }
    else
    {
        cout<<"Check the entered file's validation!\n";
        exit(0);
    }

}


int main()
{
    string fname;
    cout<<"enter ur desired file: ";
    cin>>fname;
    LabelGenerator *k;
    LabelGenerator x("p",1);
    FileLabelGenerator obj("figure",0,fname);
    k=&obj;
    for (int i = 0; i < 3; ++i) {
        cout<<k->nextLabel()<<"\t\t";
        cout<<x.nextLabel()<<"\n";
    }

}

