//cpp
#include<iostream>
#include<fstream>
#include<memory>
#include"tic_tac_toe_data.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"

using std::ios; using std::unique_ptr; using std::ofstream; using std::ifstream; using std::make_unique;

vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games() {
        vector<unique_ptr<TicTacToe>> games;
        ifstream in_file;
        in_file.open(file_name);
        string line;
        vector<string> pegs;

        while(getline(in_file, line)) {
            for (unsigned int i=0; i < line.size(); i++) {
                pegs.push_back(string(1, line[i]));
            }
            string winner = pegs[pegs.size() - 1];
            unique_ptr<TicTacToe>game(pegs,winner);

            if (pegs.size() == 9) {
                game = make_unique<TicTacToe3>(pegs, winner);
            } else if (pegs.size() == 16) {
                game = make_unique<TicTacToe4>(pegs,winner);
            }

            games.push_back(std::move(game));
            pegs.clear();
    }
    return games;
}

    
void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games) {
    ofstream out_file;
    out_file.open(file_name);

    for (auto&game: games) {
        for (auto peg: game->get_pegs()) {
            out_file<<peg;
        }
        out_file<<game->get_winner()<<std::endl;
    }

}

