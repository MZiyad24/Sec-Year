/*

 File: A2_S17,S18_20221093_problem5.cpp
 Purpose: handling a list of 10 players with a score
 Author: Abdulrahman Mohsen Fared
 Section: S17, S18
 ID: 20221093
 TA: Dr.Rana Abdelkader
 Date: 30-October-2023

*/
//---------------------

#include "iostream"
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define ll   long long
using namespace std;

int main() {
    int choose,score,count=0;
    string name;
    vector<pair<int ,string>>data;  // player and score container
    cout<<"please choose the operation you want : \n1)Add a player and score \n"
          "2)inform about a player \n3)final score \n 4)exit";
    cin>>choose;
    while (choose<4) {  // while the user didnt choose to exit
        if (choose == 1) {  // adding a player and their score
            cin >> name >> score;

            if (data.size() >= 10) {  // checking if memory is full
                if (data.back() < make_pair(score, name)) {  // checking if the sorted list's last element's score
                    data.pop_back();                        // is higher than replace them else dont add the player
                    data.push_back(make_pair(score, name));
                    std::sort(data.rbegin(), data.rend());
                }
            } else {
                data.push_back(make_pair(score, name));
                std::sort(data.rbegin(), data.rend());
            }

        }
        else if (choose==2)
        {
            cin>>name;
            for (auto it :data) {
                if (it.second==name)  // it.second -> player's name
                {
                    cout<<"the score is : "<<it.first<<"\n";
                    break;
                }
                count++;  // list's border
                if (count==10)
                {
                    cout<<"player not found! ";
                }
            }
        }
        else if (choose==3)
        {
            for (auto it:data) {
                cout<<it.second<<"   "<<it.first<<"\n";
            }
        }
        cout<<"please choose the operation you want : \n1)Add a player and score \n"
              "2)inform about a player \n3)final score \n 4)exit :\n";
        cin>>choose;
    }
}
