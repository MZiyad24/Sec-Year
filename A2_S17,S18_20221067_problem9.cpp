/*

 File: A2_S17,S18_20221067_problem9.cpp
 Purpose: Teddy bear game
 Author: Ziyad Mohammed Abdullah
 Section: S17, S18
 ID: 20221067
 TA: Dr.Rana Abdelkader
 Date: 29-October-2023

*/
//---------------------

#include "iostream"
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll   long long
using namespace std;

/*
 game rules:
 1. if n is even u will return the half
 2. if n is divisible by 3 or 4 you will return the product of the last 2 digits
 3. if n is divisible by 5 then you will return 42

 the goal is to end with 42 bears
 */
bool bears(int n)
{
    if (n>=42)
    {
        if (n==42)
        {
            return true;
        }
        if(n%5==0)
        {
            bears(n-42);
        }
        else if (n%2==0)
        {
            bears(n/2);
        }
        else if (n%4==0 || n%3==0)
        {
            bears(n-(n%10)*((n%100)-10));
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
};
int main() {
    int n;
    cout<<"enter no. of bears: ";
    cin>>n;
    if (bears(n))
    {
        cout<<"\n"<<"Congrats you have won!";
    }
    else
        cout<<"\nSadly you have lost";
}