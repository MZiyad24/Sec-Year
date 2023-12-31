// Class definition for RandomPlayer class
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

//-----------------------

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y,int game) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
