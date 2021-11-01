#include<iostream>
#include<string>
#include"tic_tac_toe.h"

using std::cout;

int main() 
{
	bool continue_game = true;
	std::string starting_player;
	string current_player;
	int position_selection;
	int continue_exit_selection;

	TicTacToe game;
	cout << "\nWelcome to Tic Tac Toe\nWho is playing first (X or O)?  ";
	cin >> starting_player;

	//Draw the board for the player to reference
	    cout << "\n\n   " << "1" << " | " << "2" << " | " << "3" << "   \n";
		cout << "   --|---|--\n";
		cout << "   " << "4" << " | " << "5" << " | " << "6" << "   \n";
		cout << "   --|---|--\n";
		cout << "   " << "7" << " | " << "8" << " | " << "9" << "   \n";

	//initialize the game
	game.start_game(starting_player);

	while (continue_game) {
		while (game.game_over() == false) {
			current_player = game.get_player(); 
			cout << "\nPlayer " << current_player << " select position: ";
			cin >> position_selection;
			game.mark_board(position_selection);
			game.display_board();
		}
		//Announce game over
		if (game.get_winner() == "C") {
			cout << "The game is a tie.\n";
		} else {
			cout << "The winner is " << game.get_winner() << ".\n";
		}

		//Draw the board
		game.display_board();

		//clear the game
		game.clear_board();

		cout << "\n\n1 - Continue\n2 - Exit\n\nPlease enter your selection: ";
		cin >> continue_exit_selection;
		if (continue_exit_selection == 2) {
			continue_game = false;
		} else {
			//start a new game
			cout << "\nStarting new game.\nWho is playing first (X or O)?  ";
			cin >> starting_player;
			game.start_game(starting_player);
		}
	}

	return 0;
}