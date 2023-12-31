
// Class definition for four_in_a_row Board class
// Author:  Ziyad Mohammed Abdullah
// Date:    16/12/2023
// Version: 1

//----------------------

#include "bits/stdc++.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

//----------------------

// Set the board
four_in_a_row::four_in_a_row() {
    n_rows = 6;
    n_cols = 7;
//    step[1].second=-1;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
//        step[i].first=i;
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = 0;
//            if (j==0)
//            {
//                step[i].second=0;
//            }
        }
    }
    step.resize(n_cols);
    for (int i = 0; i < n_cols; ++i) {
        step[i]={i,0};
    }
//    }step[6].second=0;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool four_in_a_row::update_board (int x,int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 6 ) && (step[x].second >= 0 && step[x].second <=5 )) {
        board[5-step[x].second][x] = toupper(mark);
        step[x].second++;
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void four_in_a_row::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool four_in_a_row::is_winner(char c) {
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j]!=-1 && board[i][j]!=0)
            {
                if (j + 3 < 7 && //  checking horizontally
                    board[i][j] == board[i][j + 1]
                    && board[i][j] ==board[i][j + 2]
                    && board[i][j]==board[i][j + 3])
                {

                    return true;
                }
                else if (i + 3 < 6 && //  checking vertically
                           board[i][j] ==board[i + 1][j]
                           && board[i][j] ==board[i + 2][j]
                           && board[i][j] ==board[i + 3][j])
                {
                    return true;
                }
                else if (i < 3 && j <= 3 &&  // checking down right
                           board[i][j] ==board[i + 1][j + 1]
                           && board[i][j] ==board[i + 2][j + 2]
                           && board[i][j] ==board[i + 3][j + 3])
                {
                    return true;
                }
                else if (j >= 3 && i < 3 &&  // checking down left
                           board[i][j] == board[i + 1][j - 1]
                           && board[i][j] ==board[i + 2][j - 2]
                           && board[i][j] ==board[i + 3][j - 3] )
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool four_in_a_row::is_draw() {
    return (n_moves == 6*7 && !is_winner('0'));
}

bool four_in_a_row::game_is_over () {
    return n_moves >= 6*7;
}
int four_in_a_row::check_res()
{
    return res;
}
