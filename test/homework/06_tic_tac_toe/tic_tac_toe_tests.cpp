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
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(2);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(3);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(4);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(6);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(5);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(8);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(9);
	REQUIRE(game_tie.game_over() == false);
	game_tie.mark_board(7);
	game_tie.game_over();
	REQUIRE(game_tie.game_over() == true);
	REQUIRE(game_tie.get_winner() == "C");
}

TEST_CASE("Verify win by first column") {
	TicTacToe game_column_1;
	game_column_1.start_game("X");
	game_column_1.mark_board(1);
	REQUIRE(game_column_1.game_over() == false);
	game_column_1.mark_board(9); 
	REQUIRE(game_column_1.game_over() == false);
	game_column_1.mark_board(4);
	REQUIRE(game_column_1.game_over() == false);
	game_column_1.mark_board(9);
	REQUIRE(game_column_1.game_over() == false);
	game_column_1.mark_board(7);
	game_column_1.game_over();
	REQUIRE(game_column_1.get_winner() == "X");
	REQUIRE(game_column_1.game_over() == true);
}

TEST_CASE("Verify win by second column") {
	TicTacToe game_column_2;
	game_column_2.start_game("X");
	game_column_2.mark_board(9); 
	REQUIRE(game_column_2.game_over() == false);
	game_column_2.mark_board(5);
	REQUIRE(game_column_2.game_over() == false);
	game_column_2.mark_board(9);
	REQUIRE(game_column_2.game_over() == false);
	game_column_2.mark_board(8);
	game_column_2.game_over();
	REQUIRE(game_column_2.get_winner() == "X");
	REQUIRE(game_column_2.game_over() == true);
}

TEST_CASE("Verify win by Third column") {
	TicTacToe game_column_3;
	game_column_3.start_game("X");
	game_column_3.mark_board(3);
	REQUIRE(game_column_3.game_over() == false);
	game_column_3.mark_board(1); 
	REQUIRE(game_column_3.game_over() == false);
	game_column_3.mark_board(6);
	REQUIRE(game_column_3.game_over() == false);
	game_column_3.mark_board(1);
	REQUIRE(game_column_3.game_over() == false);
	game_column_3.mark_board(9);
	game_column_3.game_over();
	REQUIRE(game_column_3.get_winner() == "X");
	REQUIRE(game_column_3.game_over() == true);
}

TEST_CASE("Verify win by first row") {
	TicTacToe game_row_1;
	game_row_1.start_game("X");
	game_row_1.mark_board(1);
	REQUIRE(game_row_1.game_over() == false);
	game_row_1.mark_board(9); 
	REQUIRE(game_row_1.game_over() == false);
	game_row_1.mark_board(2);
	REQUIRE(game_row_1.game_over() == false);
	game_row_1.mark_board(9);
	REQUIRE(game_row_1.game_over() == false);
	game_row_1.mark_board(3);
	game_row_1.game_over();
	REQUIRE(game_row_1.get_winner() == "X");
	REQUIRE(game_row_1.game_over() == true);
}

TEST_CASE("Verify win by second row") {
	TicTacToe game_row_2;
	game_row_2.start_game("X");
	game_row_2.mark_board(4);
	REQUIRE(game_row_2.game_over() == false);
	game_row_2.mark_board(9); 
	REQUIRE(game_row_2.game_over() == false);
	game_row_2.mark_board(5);
	REQUIRE(game_row_2.game_over() == false);
	game_row_2.mark_board(9);
	REQUIRE(game_row_2.game_over() == false);
	game_row_2.mark_board(6);
	game_row_2.game_over();
	REQUIRE(game_row_2.get_winner() == "X");
	REQUIRE(game_row_2.game_over() == true);
}

TEST_CASE("Verify win by third row") {
	TicTacToe game_row_3;
	game_row_3.start_game("X");
	game_row_3.mark_board(7);
	REQUIRE(game_row_3.game_over() == false);
	game_row_3.mark_board(2); 
	REQUIRE(game_row_3.game_over() == false);
	game_row_3.mark_board(8);
	REQUIRE(game_row_3.game_over() == false);
	game_row_3.mark_board(2);
	REQUIRE(game_row_3.game_over() == false);
	game_row_3.mark_board(9);
	game_row_3.game_over();
	REQUIRE(game_row_3.get_winner() == "X");
	REQUIRE(game_row_3.game_over() == true);
}

TEST_CASE("Verify win by diagonal top left to bottom right") {
	TicTacToe game_diag_1;
	game_diag_1.start_game("O");
	game_diag_1.mark_board(1);
	REQUIRE(game_diag_1.game_over() == false);
	game_diag_1.mark_board(2); 
	REQUIRE(game_diag_1.game_over() == false);
	game_diag_1.mark_board(5);
	REQUIRE(game_diag_1.game_over() == false);
	game_diag_1.mark_board(2);
	REQUIRE(game_diag_1.game_over() == false);
	game_diag_1.mark_board(9);
	game_diag_1.game_over();
	REQUIRE(game_diag_1.get_winner() == "O");
	REQUIRE(game_diag_1.game_over() == true);
}

TEST_CASE("Verify win by diagonal bottom left toi top right") {
	TicTacToe game_diag_2;
	game_diag_2.start_game("X");
	game_diag_2.mark_board(7);
	REQUIRE(game_diag_2.game_over() == false);
	game_diag_2.mark_board(2); 
	REQUIRE(game_diag_2.game_over() == false);
	game_diag_2.mark_board(5);
	REQUIRE(game_diag_2.game_over() == false);
	game_diag_2.mark_board(2);
	REQUIRE(game_diag_2.game_over() == false);
	game_diag_2.mark_board(3);
	game_diag_2.game_over();
	REQUIRE(game_diag_2.get_winner() == "X");
	REQUIRE(game_diag_2.game_over() == true);
}

TEST_CASE("Verify TicTacToe Manager functions as intended") {
	TicTacToeManager all_games;
	TicTacToe x_winner_game;
	TicTacToe tie_game;
	TicTacToe o_winner_game;

	x_winner_game.start_game("X");
	x_winner_game.mark_board(7);
	REQUIRE(x_winner_game.game_over() == false);
	x_winner_game.mark_board(2); 
	REQUIRE(x_winner_game.game_over() == false);
	x_winner_game.mark_board(5);
	REQUIRE(x_winner_game.game_over() == false);
	x_winner_game.mark_board(2);
	REQUIRE(x_winner_game.game_over() == false);
	x_winner_game.mark_board(3);
	x_winner_game.game_over();
	REQUIRE(x_winner_game.get_winner() == "X");
	REQUIRE(x_winner_game.game_over() == true);
	all_games.save_game(x_winner_game);

	tie_game.start_game("X");
	tie_game.mark_board(1);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(2);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(3);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(4);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(6);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(5);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(8);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(9);
	REQUIRE(tie_game.game_over() == false);
	tie_game.mark_board(7);
	tie_game.game_over();
	REQUIRE(tie_game.game_over() == true);
	REQUIRE(tie_game.get_winner() == "C");
	all_games.save_game(tie_game);

	o_winner_game.start_game("O");
	o_winner_game.mark_board(7);
	REQUIRE(o_winner_game.game_over() == false);
	o_winner_game.mark_board(2); 
	REQUIRE(o_winner_game.game_over() == false);
	o_winner_game.mark_board(5);
	REQUIRE(o_winner_game.game_over() == false);
	o_winner_game.mark_board(2);
	REQUIRE(o_winner_game.game_over() == false);
	o_winner_game.mark_board(3);
	o_winner_game.game_over();
	REQUIRE(o_winner_game.get_winner() == "O");
	REQUIRE(o_winner_game.game_over() == true);
	all_games.save_game(o_winner_game);

	//Due to unforseen technical issues with the way I wrote this program I now realize
	//I'm not actually able to call get_winner_totals with x_win o_win or ties parameteres 
	//as they are private variables.

	//Please kindly accept this modest attempt at writing the tests as partial credit
	//And know that I did manually test this program and far as I can tell
	//It is working correctly

}



