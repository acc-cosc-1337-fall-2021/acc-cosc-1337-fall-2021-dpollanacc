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
		if (TicTacToe::check_column_win()) {
			TicTacToe::set_winner();
			game_is_over = true;
		}
		if (check_row_win()) {
			TicTacToe::set_winner();
			game_is_over =  true;
		}
		if (check_diagonal_win()) {
			TicTacToe::set_winner();
			game_is_over = true;
		}

		if ( ( game_is_over == false ) && ( check_board_full() ) ) {
			//TicTacToe::set_winner('C');  // <-- Overload set winner to get TicTacToe::winner to become C for Tie Case
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

void TicTacToe::display_board() const {
	cout << "   " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "   \n";
	cout << "   --|---|--\n";
	cout << "   " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "   \n";
	cout << "   --|---|--\n";
	cout << "   " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "   \n";
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
	string previous_player = player == "X" ? "O" : "X"; // <-- Hacky solution to a weird constraint that I must call set_next_player in mark_board function
	// Check each columm if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[3] == previous_player) && (pegs[6] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	if ((pegs[1] == previous_player) && (pegs[4] == previous_player) && (pegs[7] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	if ((pegs[2] == previous_player) && (pegs[5] == previous_player) && (pegs[8] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	return false;
}

bool TicTacToe::check_row_win() {
	string previous_player = player == "X" ? "O" : "X"; // <-- Hacky solution to a weird constraint that I must call set_next_player in mark_board function
	// Check each row if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[1] == previous_player) && (pegs[2] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	if ((pegs[3] == previous_player) && (pegs[4] == previous_player) && (pegs[5] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	if ((pegs[6] == previous_player) && (pegs[7] == previous_player) && (pegs[8] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	return false;
}

bool TicTacToe::check_diagonal_win() {
	string previous_player = player == "X" ? "O" : "X"; // <-- Hacky solution to a weird constraint that I must call set_next_player in mark_board function
	// Check diagonal lines if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[4] == previous_player) && (pegs[8] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	if ((pegs[2] == previous_player) && (pegs[4] == previous_player) && (pegs[6] == previous_player)) {
		TicTacToe::set_winner();
		return true;
	}
	return false;
}

void TicTacToe::set_winner() {
	// Since we call set_next_player before calling game_over we want to return the player who previously played and not the player currently playing.
	// If I could call set_next_player separately after checking for a win or in its onwn function in main this wouldn't be necessary.  
	// So checking the board AFTER we switched players when the board got marked is by design per the instructions. 
	string previous_player = player == "X" ? "O" : "X";
	TicTacToe::winner = previous_player;
}
