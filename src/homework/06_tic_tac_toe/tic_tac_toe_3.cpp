#include "tic_tac_toe_3.h"


bool TicTacToe3::check_column_win() {
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this, had to do it this way because we call set_next_player in mark_board
	// Check each columm if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[3] == previous_player) && (pegs[6] == previous_player)) {
		set_winner();
		return true;
	}
	if ((pegs[1] == previous_player) && (pegs[4] == previous_player) && (pegs[7] == previous_player)) {
		set_winner();
		return true;
	}
	if ((pegs[2] == previous_player) && (pegs[5] == previous_player) && (pegs[8] == previous_player)) {
		set_winner();
		return true;
	}
	return false;
}

bool TicTacToe3::check_row_win() {
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this
	// Check each row if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[1] == previous_player) && (pegs[2] == previous_player)) {
		TicTacToe3::set_winner();
		return true;
	}
	if ((pegs[3] == previous_player) && (pegs[4] == previous_player) && (pegs[5] == previous_player)) {
		TicTacToe3::set_winner();
		return true;
	}
	if ((pegs[6] == previous_player) && (pegs[7] == previous_player) && (pegs[8] == previous_player)) {
		TicTacToe3::set_winner();
		return true;
	}
	return false;
}

bool TicTacToe3::check_diagonal_win() {
	std::cout << "Debug: Player is " << this->get_player() << "\n";
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this
	// Check diagonal lines if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[4] == previous_player) && (pegs[8] == previous_player)) {
		TicTacToe3::set_winner();
		return true;
	}
	if ((pegs[2] == previous_player) && (pegs[4] == previous_player) && (pegs[6] == previous_player)) {
		TicTacToe3::set_winner();
		return true;
	}
	return false;
}

std::string TicTacToe3::get_pegs() {
	string result;
	for (unsigned int i = 0; i < pegs.size(); i++) {
		result += pegs[i];
	}
	return result;
}

void TicTacToe3::set_winner() {
	string previous_player = this->get_player() == "X" ? "O" : "X";
	winner = previous_player;
}


/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/



/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
