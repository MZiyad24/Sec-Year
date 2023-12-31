/*

 File: A2_S17,S18_20221093_problem6(a).cpp
 Purpose: changing decimal number to its binary form
 Author: Abdulrahman Mohsen Fared
 Section: S17, S18
 ID: 20221093
 TA: Dr.Rana Abdelkader
 Date: 3-November-2023

*/
//---------------------

//problem 6 a One Binary Number
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iostream>
#define ll long long
#define endl '\n'
#define FAST cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
using namespace std;

//------------------ printing binary num

int binaryprint(int n)
{
    if(n==0)
    {
        return 0;
    }
    return (n%2+10*binaryprint(n/2));

}

int main()
{
    int n;
    cin>>n;
    cout<<binaryprint(n);


}