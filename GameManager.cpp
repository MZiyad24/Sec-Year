// Class definition for GameManager class
// Author:  Abdulrahman Mohsen , Ziyad Mohammed , Omar Ahmed
// IDs:      20221093          , 20221067       , 20220231
// Date:    16/12/2023
// Version: 1

//------------------------

#include "bits/stdc++.h"
#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

//------------------------

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run(int game) {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y,game);

            while (!boardPtr->update_board(x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y,game);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner(players[i]->get_symbol())){
                if(boardPtr->check_res()==0 ||boardPtr->check_res()==1 )
                    cout  << players[i]->to_string() << " wins\n";
                else
                {
                    if(i==0)cout  << players[i+1]->to_string() << " wins\n";
                    else cout  << players[i-1]->to_string() << " wins\n";
                }
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
