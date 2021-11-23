//cpp
#include<string>
#include<vector>
#include<memory>
#include"tic_tac_toe.h"
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe_data.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

TicTacToeManager::TicTacToeManager(TicTacToeData d) : data(d) {
    games = data.get_games();

    for (auto&game : games) {
        update_winner_count(game->get_winner()); 
    }
}

TicTacToeManager::TicTacToeManager(const TicTacToeManager &copy) {
    data = copy.data;
    games = copy.games;
    x_win = copy.x_win;
    o_win = copy.o_win;
    ties = copy.ties;
}

TicTacToeManager::~TicTacToeManager() {
    data.save_games(games);
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_totals(int& x, int& o, int&t) {
    cout << "X Wins: " << x_win << "\nO Wins: " << o_win << "\nTies:   " << ties << " \n\n";
}

void TicTacToeManager::update_winner_count(string winner) {
    if (winner == "X") {
        x_win++;
    }
    if (winner == "O") {
        o_win++;
    }
    if (winner == "C") {
        ties++;
    }
}

ostream& operator<<(std::ostream& out, TicTacToeManager& manager) {
    for (unsigned int i = 0; i < manager.games.size(); i++) {
        cout << "\n\nGame Number " << i + 1 << ":  \n\n";
        cout << *manager.games[i];
    }
    return out;
}




