
// Class definition for Pyramedic x_0 class
// Author:   Omar Ahmed
// IDs:      20220231
// Date:    16/12/2023
// Version: 1

//------------------------

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

//--------------------------

pyramdic_X_O_board::pyramdic_X_O_board()
{
    n_rows =3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            if((i==0&&j==2)|| (i==1&&j==1) || (i==1&&j==2)|| (i==1&&j==3))board[i][j] = 0;
            else if(i==2)board[i][j] = 0;
            else board[i][j]=-1;

        }
    }
}
bool pyramdic_X_O_board::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;

}
void pyramdic_X_O_board::display_board(){
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            if(board [i][j]!=-1)
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) <<board [i][j] << " |";
            }
            else
            {
                cout << setw(2) <<board [i][j] << " |";
            }
        }
        cout << "\n-----------------------------";
    }
    cout << endl;

}
bool pyramdic_X_O_board::is_winner(char c){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j)
        {
            if(board [i][j]!=-1 && board[i][j]!=0)
            {
                if (j + 2 < 5 &&  // skipping the impossible winning cell chains
                    board[i][j] == board[i][j+1] &&  // checking validation
                    board[i][j+1] ==board[i][j+2])return true;
                if (i + 2 < 3 &&
                    board[i][j] ==board[i+1][j] &&
                    board[i+1][j] == board[i+2][j])return true;
                if (i + 2 < 3 && j + 2 < 5 &&
                    board[i][j] == board[i+1][j+1]&&
                    board[i+1][j+1] == board[i+2][j+2])return true;
                if (i + 2 < 3 && j - 2 >= 0 &&
                    board[i][j] == board[i+1][j-1] &&
                    board[i+1][j-1] == board[i+2][j-2])return true;
            }
        }
    }
    return false;
}
bool pyramdic_X_O_board::is_draw(){
    return (n_moves == 9 && !is_winner('0'));

}
bool pyramdic_X_O_board::game_is_over(){
    return n_moves >= 9;

}
int pyramdic_X_O_board::check_res()
{
    return res;
}