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

TicTacToeManager::TicTacToeManager(TicTacToeData& initializer) {
    data = initializer;
    games = data.get_games();
    for (unsigned int i = 0; i < games.size(); i++) {
        TicTacToe single_game = *games[i];
        string winner = single_game.get_winner();
        update_winner_count(winner);
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

void TicTacToeManager::save_game(TicTacToe game) {
    std::unique_ptr<TicTacToe> game_ptr = make_unique<TicTacToe>(std::move(game));
    games.push_back(game_ptr);
    update_winner_count(game.get_winner());
    get_winner_totals(x_win, o_win, ties);
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




