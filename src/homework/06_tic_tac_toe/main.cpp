#include<iostream>
#include<vector>
#include<string>
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe.h"

using std::cout; using std::cin; using std::string; using std::vector; using std::endl;

int main() 
{
	bool continue_game = true;
	std::string starting_player;
	string current_player;
	int position_selection;
	int continue_exit_selection;

	// Initialize game and game manager
	TicTacToeManager manager;

	//Initialize game
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
			cin >> game;
			cout << game;
		}
		//Announce game over
		cout << "\n\nGame Over.\n\n";

		manager.save_game(game);

		//Draw the board
		cout << game;

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

	cout << manager;

	return 0;
}
