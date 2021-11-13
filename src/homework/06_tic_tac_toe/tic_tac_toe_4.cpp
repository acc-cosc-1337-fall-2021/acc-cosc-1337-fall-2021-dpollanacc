#include "tic_tac_toe_4.h"

bool TicTacToe4::check_column_win() {
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this, had to do it this way because we call set_next_player in mark_board
	// Check each columm if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[4] == previous_player) && (pegs[8] == previous_player) && (pegs[12] == previous_player)) {
		set_winner();
		return true;
	}
	if ((pegs[1] == previous_player) && (pegs[5] == previous_player) && (pegs[9] == previous_player) && (pegs[13] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
	if ((pegs[2] == previous_player) && (pegs[6] == previous_player) && (pegs[10] == previous_player) && (pegs[14] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
    if ((pegs[3] == previous_player) && (pegs[7] == previous_player) && (pegs[11] == previous_player) && (pegs[15] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}

	return false;
}

bool TicTacToe4::check_row_win() {
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this
	// Check each row if Player has marked all 3 board locations
	if ((pegs[0] == previous_player) && (pegs[1] == previous_player) && (pegs[2] == previous_player) && (pegs[3] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
	if ((pegs[4] == previous_player) && (pegs[5] == previous_player) && (pegs[6] == previous_player) && (pegs[7] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
	if ((pegs[8] == previous_player) && (pegs[9] == previous_player) && (pegs[10] == previous_player) && (pegs[11] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
    if ((pegs[12] == previous_player) && (pegs[13] == previous_player) && (pegs[14] == previous_player) && (pegs[15] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
	return false;
}

bool TicTacToe4::check_diagonal_win() {
	string previous_player = this->get_player() == "X" ? "O" : "X"; // <-- TODO: Try to find a better way of handling this
	// Check diagonal lines if Player has marked all 3 board locations
    if ((pegs[0] == previous_player) && (pegs[5] == previous_player) && (pegs[10] == previous_player) && (pegs[15] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
    if ((pegs[3] == previous_player) && (pegs[6] == previous_player) && (pegs[9] == previous_player) && (pegs[12] == previous_player)) {
		TicTacToe4::set_winner();
		return true;
	}
	return false;
}




// /*
// class function check_column_win
// Win by column if and return true if (each column index)
// 0, 1,  2,  3 
// 4, 5,  6,  7 
// 8, 9, 10, 11 
// 12,13,14, 15 
// else
// false
// */




// /*
// class function check_row_win
// Win by row if
// 0, 1,  2,  3 are equal
// 4, 5,  6,  7 are equal
// 8, 9, 10, 11 are equal 
// 12,13,14, 15 are equal
// */



// /*
// class function check_diagonal_win
// Win diagonally
// 0, 1,  2,  3
// 4, 5,  6,  7
// 8, 9, 10, 11
// 12,13,14, 15

// */
