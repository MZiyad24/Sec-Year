// Class definition for player class
// Author:  Abdulrahman Mohsen , Ziyad Mohammed , Omar Ahmed
// IDs:      20221093          , 20221067       , 20220231
// Date:    16/12/2023
// Version: 1

//------------------------

#include "bits/stdc++.h"
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

//------------------------

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move (int& x, int& y, int game)
{
    if (game==1)
    {
        cout << "\nPlease enter your move x and y separated by spaces: ";
        cin >> x >> y;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter your move x and y separated by spaces: ";
            cin >> x >> y;
        }
    }
    else if (game==2)
    {
        cout << "\nPlease enter your move : ";
        cin >> x;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter your move : ";
            cin >> x;
        }
    }
    else if (game==3)
    {
        cout << "\nPlease enter your move x and y separated by spaces: ";
        cin >> x >> y;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter your move x and y separated by spaces: ";
            cin >> x >> y;
        }
    }
    else if (game ==4)
    {
        cout << "\nPlease enter your move x and y separated by spaces: ";
        cin >> x >> y;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter your move x and y separated by spaces: ";
            cin >> x >> y;
        }
    }
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}
