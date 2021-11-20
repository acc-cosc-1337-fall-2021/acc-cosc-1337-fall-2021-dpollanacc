//cpp
#include<iostream>
#include<fstream>
#include<memory>
#include"tic_tac_toe_data.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"

using std::ios; using std::unique_ptr; using std::fstream;

vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games() {
        vector<unique_ptr<TicTacToe>> boards;
        fstream game_history;
        game_history.open("history.txt", ios::in);
        string line;

        while(getline(game_history, line)) {
            vector<string> pegs;
            int board_size = line.size() - 1;
            for (unsigned int i = 0; i<board_size; i++) {
               pegs[i] = line[i];
            }
            string winner(1,line[board_size]); // Explicit coercion from char to string

            unique_ptr<TicTacToe> board;

            if(board_size == 9) {
                board = make_unique<TicTacToe3>(pegs, winner);
            }
            if(board_size==17) {
                board = make_unique<TicTacToe4>(pegs, winner);
            }
            boards.push_back(board);
        }
        game_history.close();
        return boards;
    }

    
void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games) {
    fstream game_history;
    game_history.open("history.txt", ios::out);
    for (unsigned int i = 0; i < games.size(); i++) {
        TicTacToe this_game = *games[i];
        string this_game_to_string;
        this_game_to_string = this->get_pegs();
    }
}

