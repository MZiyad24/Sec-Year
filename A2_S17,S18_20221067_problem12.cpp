/*

 File: A2_S17,S18_20221067_problem12.cpp
 Purpose: calculating thread score of a text file
 Author: Ziyad Mohammed Abdullah
 Section: S17, S18
 ID: 20221067
 TA: Dr.Rana Abdelkader
 Date: 1-November-2023

*/
//---------------------

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
    vector<string>words ={"new","urgent","have to","expenses","payment",        // words detected
                          "alert","Apple","NBK","Netflix","Yahoo","Microsoft",
                          "Chase","Paypal","Facebook","WhatsApp","eBay","Amazon",
                          "leaked","invoice","copy","file","message","required",
                          "scanned","suspicious"};

    vector<string>phrases = {"password expired","your account has been hacked",      // phrases detected
                             "your account has been limited","access failed","verify your information"};

    vector <int> nums = {1,2,1,3,3,2,3,3,2,2,2,2,3,2,2,1,1,3,3,3,1,2,1,3,3,1,1,3,3,2};   // score of each word or phrase

    vector <pair<string , int>>lest;     // holds the word and the initialed score
    vector <pair<string , int>>seeker;  // holds the word and num of repeatance
    ll final_score =0;
    for (int i = 0; i < 30; i++)
    {
        if (i<25)
        {
            lest.push_back(make_pair(words[i],nums[i]));
            seeker.push_back(make_pair(words[i],0));
        }
        else
        {
            lest.push_back(make_pair(phrases[i-25],nums[i]));
            seeker.push_back(make_pair(phrases[i-25],0));
        }
    }

    string word,filename,temp;
    cout<<"enter your destined file name : \n";
    cin>>filename;
    filename+=".txt";
    // auto *ptr;
    int score=0;
    ifstream file(filename);
    if (!file.is_open())
    {
        cout<<"error while opening the file";
    }
    else
    {
        while (getline(file,word))
        {
            for (auto& it : seeker)    // refrenced here to make sure that the int in the vector being incremented
            {
                if (word.find(it.first) != string::npos) // string :: npos is a null return val or an empty space in the memory
                {
                    it.second+=1;
                }
            }

        }
        for ( auto it : seeker)
        {
            if ( it.second > 0)   // if a word repeated or written in the file then you will compare the final score
            {
                for (auto itr : lest)
                {
                    if (it.first==itr.first)
                    {
                        cout<<it.first<<" has a threat rate of "<<itr.second<<" repeated "<<it.second<< " times and"<<
                            " has a score of : "<<it.second*itr.second<<"\n";
                        final_score+=itr.second*it.second;
                    }
                }
            }
        }
        cout<<"the total score is : "<<final_score;
        file.close();

    }


}