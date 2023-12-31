/*

 File: A2_S17,S18_20221067_problem8.cpp
 Purpose: creating a 2^n star shape
 Author: Ziyad Mohammed Abdullah
 Section: S17, S18
 ID: 20221067
 TA: Dr.Rana Abdelkader
 Date: 3-November-2023

*/
//---------------------

#include <iostream>
#include<fstream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void pattern (int stars , int spaces)
{
    if(stars==1)
    {
        for (int i = 0; i < spaces; i++)
        {
            cout<<"  ";
        }
        cout<<" *\n";
    }
    else
    {
        pattern(stars/2,spaces);                   // reducing number of stars by half every iteration until finding zero
        for (int i = 0; i < spaces; i++)            // first half of the pattern
        {
            cout<<"  ";
        }
        for (int i = 0; i < stars; i++)
        {
            cout<<" *";
        }
        cout<<"\n";
        // second half of the pattern
        pattern(stars/2,spaces+stars/2);        // spaces+2 won't make difference in the first 6 iterationts but then
        // the spaces will be reduced


    }
}

int main(){

    int spaces,stars;
    cout<<"please enter your desired num of stars : \n";
    cin>>stars;
    cout<<"please enter the spaces : \n";
    cin>>spaces;
    pattern(stars,spaces);

}