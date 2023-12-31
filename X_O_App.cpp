// Application
// Author:  Abdulrahman Mohsen , Ziyad Mohammed , Omar Ahmed
// IDs:      20221093          , 20221067       , 20220231
// Date:    16/12/2023
// Version: 1

//------------------------

#include "bits/stdc++.h"
#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

//-----------------------

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Welcome to FCAI Game board. :)\n";

    while (true) {
        int game_task;
        cout << "Chose the game mode" << endl;
        cout << "*1- pyramedic tic-tac-toe" << endl;
        cout << "**2- four in a row" << endl;
        cout << "***3- 5 x 5 tic-tac-toe" << endl;
        cout << "****4- 3 x 3 tic-tac-toe\n";
        cout << "*****5- exit\n";
        cout << "- ";
        cin >> game_task;
        if (game_task>5 || game_task<1)
        {
            cout << "There is no such a game!\n";
            continue;
        }

        //-------------

        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else {
            //Player pointer points to child
            if (game_task==1)
            {
                players[1] = new RandomPlayer('o', 5);
            }
            else if (game_task==2)
            {
                players[1] = new RandomPlayer('o',7);
            }
            else if (game_task==3)
            {
                players[1] = new RandomPlayer('o',5);
            }
            else if (game_task==4)
            {
                players[1] = new RandomPlayer('o',3);
            }
        }
        //------------

        bool rule;
        cout << "Do you need to see the rule of the game? (1/0))" << endl;
        cin >> rule;
        if (rule) {
            if (game_task == 1) {
                cout
                        << "You will have a Pyramic board and you have to connect three cells with the same\nsymbol either horizontally"
                           "vertically or diagonally without the interruption of the other player in your sequence.\nEach one will have"
                           "one turn and the players will change turns.\nThe first to do so wins the game.\n";
            } else if (game_task == 2) {
                cout
                        << "There will be a 6x7 board and both players will choose the column number to put their token (X,Y). \n"
                           "Players will exchange turns until the board fills or one of the players create a vertical / horizontal"
                           " / diagonal sequence of 4 of his tokens.\n";
            } else if (game_task==3) {
                cout
                        << "THere will be a 5x5 board and both players will chose the row and column number to insert their symbol.\n"
                           "Players will exchange turns until the number of moves made be 24 then the game will check either if there"
                           " is a winner or not.\nTo win you must create a higher number of combinations than your opponent, and the combinations"
                           " a are calculated as a number of sequence of vertical / horizontal/ diagonal sequence of the player's symbol.\n";
            }
            else if (game_task==4)
            {
                cout<<"There will be a 3 x 3 game board and each player will have to chose the row and column to make a move and the \n first to get a sequence"
                      "of three symbols vertically/ horizontally/ diagonally wins.";
            }
        }

        //---------------

        if (game_task == 1) {
            GameManager x_o_game(new pyramdic_X_O_board(), players);
            x_o_game.run(game_task);// game task to choose the game conditions as in is winner and get move
        } else if (game_task == 2) {
            GameManager x_o_game(new four_in_a_row(), players);
            x_o_game.run(game_task);
        } else if (game_task == 3) {
            GameManager x_o_game(new five_X_O(), players);
            x_o_game.run(game_task);
        }
        else if (game_task==4)
        {
            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run(game_task);
        }
        else if (game_task==5)
        {
            cout<<"Thank you for playing :)\nHope you have enjoyed.\n";
            return false;
        }

        system("pause");
    }
}
