//h
#include<string>
#include<vector>
#include"tic_tac_toe.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

#ifndef TIC_TAC_TOE_MANAGER
#define TIC_TAC_TOE_MANAGER

class TicTacToeManager {
public:
    void save_game(TicTacToe b);
    void get_winner_totals(int& x, int& o, int&t);
    friend ostream& operator<<(std::ostream& out, TicTacToeManager& manager);
private:
    vector<TicTacToe> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(string winner);
};

#endif