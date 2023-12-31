
// Class definition for five_X_O Board class
// Author:  Abdulrahman Mohsen Fared
// Date:    16/12/2023
// Version: 1

//---------------------

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

//---------------------

five_X_O::five_X_O(){
    n_rows =5;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j]=0;
        }
    }
}
bool five_X_O::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

}
void five_X_O::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool five_X_O::is_winner(char c){
    int res1=0;
    int res2=0;
    if (n_moves<24)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (j + 2 <= 4 &&  // skipping the impossible winning cell chains
                    board[i][j] == c &&   // checking validation
                    board[i][j] == board[i][j + 1] &&
                    board[i][j + 1]==board[i][j + 2])res1++;
                // Check vertically
                if (i + 2 <= 4 &&
                    board[i][j] == c &&
                    board[i][j] == board[i+1][j]
                    && board[i+1][j]==board[i+2][j])res1++;
                // Check diagonally (down-right)
                if (i + 2 <= 4 && j + 2 <= 4 &&
                    board[i][j] == c &&
                    board[i+1][j+1]== board[i][j] &&
                    board[i+1][j+1]==board[i+2][j+2])res1++;
                // Check diagonally (down-left)
                if (i + 2 <= 4 && j - 2 >= 0 &&
                    board[i][j] == c &&
                    board[i+1][j-1] ==board[i][j] &&
                    board[i+1][j-1]==board[i+2][j-2])res1++;
            }
        }
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (j + 2 <= 4 &&  // skipping the impossible winning cell chains
                    board[i][j] != c &&   // checking validation
                    board[i][j] == board[i][j + 1] &&
                    board[i][j + 1]==board[i][j + 2])res2++;
                // Check vertically
                if (i + 2 <= 4 &&
                    board[i][j] != c &&
                    board[i][j] == board[i+1][j]
                    && board[i+1][j]==board[i+2][j])res2++;
                // Check diagonally (down-right)
                if (i + 2 <= 4 && j + 2 <= 4 &&
                    board[i][j] != c &&
                    board[i+1][j+1]== board[i][j] &&
                    board[i+1][j+1]==board[i+2][j+2])res2++;
                // Check diagonally (down-left)
                if (i + 2 <= 4 && j - 2 >= 0 &&
                    board[i][j] != c &&
                    board[i+1][j-1] ==board[i][j] &&
                    board[i+1][j-1]==board[i+2][j-2])res2++;
            }
        }
    }if(res1>res2){res=1 ; return true;}
    else if(res1<res2){res=2; return true;}
    else return false;


}
int five_X_O::check_res()
{
    return res;
}
bool five_X_O::is_draw(){
    return (n_moves==24);

}
bool five_X_O::game_is_over(){
    return (n_moves == 24 &&!is_winner('x'));

}