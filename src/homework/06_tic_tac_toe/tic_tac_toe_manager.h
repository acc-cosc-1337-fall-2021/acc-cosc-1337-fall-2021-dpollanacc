//h
#include<string>
#include<vector>
#include<memory>
#include"tic_tac_toe.h"
#include"tic_tac_toe_data.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

#ifndef TIC_TAC_TOE_MANAGER
#define TIC_TAC_TOE_MANAGER

class TicTacToeManager {
public:
    TicTacToeManager() = default;
    TicTacToeManager(TicTacToeData d);
    TicTacToeManager(const TicTacToeManager &copy);
    ~TicTacToeManager();
    void save_game(std::unique_ptr<TicTacToe>& b);
    void get_winner_totals(int& x, int& o, int&t);
    friend ostream& operator<<(std::ostream& out, TicTacToeManager& manager);
    void update_winner_count(string winner);
private:
    TicTacToeData data;
    vector<std::unique_ptr<TicTacToe>> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
};

#endif