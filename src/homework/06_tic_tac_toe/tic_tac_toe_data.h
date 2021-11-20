//h
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<memory>
#include"tic_tac_toe.h"

using std::string; using std::make_unique;

#ifndef TIC_TAC_TOE_DATA
#define TIC_TAC_TOE_DATA
class TicTacToeData {
public:
    void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
    vector<std::unique_ptr<TicTacToe>> get_games();
};
#endif