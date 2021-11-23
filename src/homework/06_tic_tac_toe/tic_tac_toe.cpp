//cpp

#include <iostream>
#include <string>
#include <vector>
#include"tic_tac_toe.h"

using std::string;
using std::vector;
using std::cout;

bool TicTacToe::game_over() {

		bool game_is_over = false;

		// Add checks for all the win conditions
		if (this->check_column_win()) {
			this->set_winner();
			game_is_over = true;
		}
		if (this->check_row_win()) {
			this->set_winner();
			game_is_over =  true;
		}
		if (this->check_diagonal_win()) {
			this->set_winner();
			game_is_over = true;
		}

		if ( ( game_is_over == false ) && ( check_board_full() ) ) {
			TicTacToe::winner = "C";
			game_is_over = true;
		}
		return game_is_over;
	}

void TicTacToe::start_game(std::string first_player) {
	TicTacToe::player = first_player;
	clear_board();
}


void TicTacToe::mark_board(int position) {
	pegs[position - 1] = TicTacToe::player;
	set_next_player();
}

string TicTacToe::get_player() const {
	return TicTacToe::player;
}

void TicTacToe::set_next_player() {
	TicTacToe::player = TicTacToe::player == "X" ? "O" : "X";
}

bool TicTacToe::check_board_full() {
	bool result = true;
	for (unsigned int i = 0; i < pegs.size(); i++) {
		if (pegs[i] == " ") {
			result = false;
		}
	}
	return result; 
}

void TicTacToe::clear_board() {
	for (unsigned int i = 0; i < pegs.size(); i++) {
		pegs[i] = " ";
	}
}

string TicTacToe::get_winner() {
	return winner;
}

bool TicTacToe::check_column_win() {
	return false;
}

bool TicTacToe::check_row_win() {
	return false;
}

bool TicTacToe::check_diagonal_win() {
	return false;
}

void TicTacToe::set_winner() {
	string previous_player = this->get_player() == "X" ? "O" : "X";
	this->winner = previous_player;
}

ostream& operator<<(ostream& out, const TicTacToe& game) {
	if (game.pegs.size() == 9) {
		cout << "   " << game.pegs[0] << " | " << game.pegs[1] << " | " << game.pegs[2] << "   \n";
		cout << "   --|---|--\n";
		cout << "   " << game.pegs[3] << " | " << game.pegs[4] << " | " << game.pegs[5] << "   \n";
		cout << "   --|---|--\n";
		cout << "   " << game.pegs[6] << " | " << game.pegs[7] << " | " << game.pegs[8] << "   \n";
		return out;
	}
	if (game.pegs.size() == 16) {
			cout << "   " << game.pegs[0] << " | " << game.pegs[1] << " | " << game.pegs[2] << " | "  << game.pegs[3] << "   \n";
		cout << "   --|---|---|--\n";
		cout << "   " << game.pegs[4] << " | " << game.pegs[5] << " | " << game.pegs[6] << " | "  << game.pegs[7] << "   \n";
		cout << "   --|---|---|--\n";
		cout << "   " << game.pegs[8] << " | " << game.pegs[9] << " | " << game.pegs[10] << " | "  << game.pegs[11] << "   \n";
		cout << "   --|---|---|--\n";
		cout << "   " << game.pegs[12] << " | " << game.pegs[13] << " | " << game.pegs[14] << " | " << game.pegs[15] << "   \n";
		return out;
	}
	return out;
}

istream& operator>>(istream& in, TicTacToe& game) {
	int pos;
	cout << "\nPlayer " << game.player << "'s Turn\nEnter Position: "; 
	cin >> pos;
	game.mark_board(pos);
	return in;
}
