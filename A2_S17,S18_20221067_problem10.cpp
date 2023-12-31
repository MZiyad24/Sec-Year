/*

 File: A2_S17,S18_20221067_problem10.cpp
 Purpose: changing detected words to their alternatives
 Author: Ziyad Mohammed Abdullah
 Section: S17, S18
 ID: 20221067
 TA: Dr.Rana Abdelkader
 Date: 3-November-2023

*/
//---------------------

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <locale>
using namespace std;
int main(){
    string filename,altfile,ansfile;
    cout<<"enter your file name : \n";
    cin>>filename;
    cout<<"enter your detected words and their alternatives file: \n";
    cin>>altfile;
    altfile+=".txt";
    filename+=".txt";
    wifstream file(filename);
    wifstream alt(altfile);
    wofstream temp ("ans.txt", ios ::trunc );
//    wofstream temp2 ("temp2.txt", ios::trunc);
    file.imbue(locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    alt.imbue(locale(alt.getloc(), new std::codecvt_utf8<wchar_t>));
    temp.imbue(locale(temp.getloc(), new std::codecvt_utf8<wchar_t>));
    wstring word,detect,sub;
    int count=0;
    vector<int> checkpoints;
    if (!file.is_open() || !alt.is_open())
    {
        cout<<"error while opening file!\n";
    }
    else
    {
        while (getline(file,word))
        {
            while (alt >> detect)
            {
                if (word.find(detect) != wstring::npos)
                {
                    for (wint_t i = 0; i < word.size(); ++i)
                    {
                        if (word.substr(i, detect.size()) == detect)
                        {
                            if (i + detect.size() < word.size())     // to not exceed the space using the substr fn
                            {
                                alt >> sub;   // even indexed words are the subs
                                word.insert(i, sub);
                                word.erase(i + sub.size(), detect.size());
                            }
                        }
                    }
                }
                else
                {
                    alt >> detect;  // to move to odd indexed word which is a detected word
                }
            }
            alt.clear();   // restarting reading from the beginning of the file
            alt.seekg(0,ios::beg);
            temp << word << "\n";   // typing down the edited string to the new file
        }
        cout<< "check your ans.txt file. ";
        // if (checkpoints.size()>0)
        // {
        // }
        file.close();
    }
}