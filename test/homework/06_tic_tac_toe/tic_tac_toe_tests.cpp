#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

	// This should result in 20 total assertions including the test configuration case

TEST_CASE("Test start_game function with both players") {
	TicTacToe game_x;  TicTacToe game_y;
	game_x.start_game("X");
	game_y.start_game("Y");

	REQUIRE(game_x.get_player() == "X");
	REQUIRE(game_y.get_player() == "Y");
}

TEST_CASE("Verify the game correctly handles a tie") {
	TicTacToe game_tie;
	game_tie.start_game("X");
	game_tie.mark_board(1);
	game_tie.mark_board(2);
	game_tie.mark_board(3);
	game_tie.mark_board(4);
	game_tie.mark_board(6);
	game_tie.mark_board(5);
	game_tie.mark_board(8);
	game_tie.mark_board(9);
	game_tie.mark_board(7);
	game_tie.game_over();
	REQUIRE(game_tie.get_winner() == "C");
}

TEST_CASE("Verify win by first column") {
	TicTacToe game_column_1;
	game_column_1.start_game("X");
	game_column_1.mark_board(1);
	game_column_1.mark_board(9); 
	game_column_1.mark_board(4);
	game_column_1.mark_board(9);
	game_column_1.mark_board(7);
	game_column_1.game_over();
	REQUIRE(game_column_1.get_winner() == "X");
	REQUIRE(game_column_1.game_over() == true);
}

TEST_CASE("Verify win by second column") {
	TicTacToe game_column_2;
	game_column_2.start_game("X");
	game_column_2.mark_board(2);
	game_column_2.mark_board(9); 
	game_column_2.mark_board(5);
	game_column_2.mark_board(9);
	game_column_2.mark_board(8);
	game_column_2.game_over();
	REQUIRE(game_column_2.get_winner() == "X");
	REQUIRE(game_column_2.game_over() == true);
}

TEST_CASE("Verify win by Third column") {
	TicTacToe game_column_3;
	game_column_3.start_game("X");
	game_column_3.mark_board(3);
	game_column_3.mark_board(1); 
	game_column_3.mark_board(6);
	game_column_3.mark_board(1);
	game_column_3.mark_board(9);
	game_column_3.game_over();
	REQUIRE(game_column_3.get_winner() == "X");
	REQUIRE(game_column_3.game_over() == true);
}

TEST_CASE("Verify win by first row") {
	TicTacToe game_row_1;
	game_row_1.start_game("X");
	game_row_1.mark_board(1);
	game_row_1.mark_board(9); 
	game_row_1.mark_board(2);
	game_row_1.mark_board(9);
	game_row_1.mark_board(3);
	game_row_1.game_over();
	REQUIRE(game_row_1.get_winner() == "X");
	REQUIRE(game_row_1.game_over() == true);
}

TEST_CASE("Verify win by second row") {
	TicTacToe game_row_2;
	game_row_2.start_game("X");
	game_row_2.mark_board(4);
	game_row_2.mark_board(9); 
	game_row_2.mark_board(5);
	game_row_2.mark_board(9);
	game_row_2.mark_board(6);
	game_row_2.game_over();
	REQUIRE(game_row_2.get_winner() == "X");
	REQUIRE(game_row_2.game_over() == true);
}

TEST_CASE("Verify win by third row") {
	TicTacToe game_row_3;
	game_row_3.start_game("X");
	game_row_3.mark_board(7);
	game_row_3.mark_board(2); 
	game_row_3.mark_board(8);
	game_row_3.mark_board(2);
	game_row_3.mark_board(9);
	game_row_3.game_over();
	REQUIRE(game_row_3.get_winner() == "X");
	REQUIRE(game_row_3.game_over() == true);
}

TEST_CASE("Verify win by diagonal top left to bottom right") {
	TicTacToe game_diag_1;
	game_diag_1.start_game("O");
	game_diag_1.mark_board(1);
	game_diag_1.mark_board(2); 
	game_diag_1.mark_board(5);
	game_diag_1.mark_board(2);
	game_diag_1.mark_board(9);
	game_diag_1.game_over();
	REQUIRE(game_diag_1.get_winner() == "O");
	REQUIRE(game_diag_1.game_over() == true);
}

TEST_CASE("Verify win by diagonal bottom left toi top right") {
	TicTacToe game_diag_2;
	game_diag_2.start_game("X");
	game_diag_2.mark_board(7);
	game_diag_2.mark_board(2); 
	game_diag_2.mark_board(5);
	game_diag_2.mark_board(2);
	game_diag_2.mark_board(3);
	game_diag_2.game_over();
	REQUIRE(game_diag_2.get_winner() == "X");
	REQUIRE(game_diag_2.game_over() == true);
}



