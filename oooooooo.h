#include "bits/stdc++.h"
#include <cstdlib>
#include <cstring>
#ifndef LABEL_GENERTOR_H
#define LABEL_GENERTOR_H
#include <string>
using namespace std ;
class LabelGenerator {
protected:
    string prefix ;  // // Prefix for the label (e.g., "Figure " or "P").
    int currentIndex ;
    string formatble ();
public:
    //Empty constructor to not rewrite or initialize the parameterized constructor in the child class.
    LabelGenerator();
    // Constructor: Initializes the LabelGenerator with a prefix string and an initial index.
    LabelGenerator(const string& prefix, int initialIndex);

    // Destructor: Cleans up any resources if needed.
    ~LabelGenerator();

    // Generates the next label in the sequence and returns it.
    virtual string nextLabel();

    string formatLabel();
};
class FileLabelGenerator:public LabelGenerator
{
private:
    string pref;
    int idx;
    static int count;
    string filename;
    vector<string>file_lines;
public:
    FileLabelGenerator( const string &prefix, int idx,string file);
    string nextLabel();
    string formatLabel();

};
int FileLabelGenerator::count=0;
#endif