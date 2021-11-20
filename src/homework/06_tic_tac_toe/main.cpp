#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"

using std::cout; using std::cin; using std::string; using std::vector; using std::endl; using std::unique_ptr;

int main() 
{
	bool continue_game = true;
	int user_game_selection;
	std::string starting_player;
	string current_player;
	int position_selection;
	int continue_exit_selection;

	// Initialize game manager
	TicTacToeData d;
	TicTacToeManager manager(d);
	unique_ptr<TicTacToe> game;

	//Initialize game
	cout << "Welcome to Tic Tac Toe\nWould you like to play TicTacToe3 or TicTacToe4\n1)TicTacToe3\n2)TicTacToe4\nEnter Selection: ";
	cin >> user_game_selection;
	if (user_game_selection == 1) {
		cout << "Playing TicTacToe3\n";
		game = std::make_unique<TicTacToe3>();
	}
	if (user_game_selection == 2) {
		cout << "Playing TicTacToe4\n";
		game = std::make_unique<TicTacToe4>();
	}

	cout << "\nWelcome to Tic Tac Toe\nWho is playing first (X or O)?  ";
	cin >> starting_player;

	//initialize the game
	game->start_game(starting_player);

	while (continue_game) {
		while (game->game_over() == false) {
			cin >> *game;
			cout << *game;
		}
		//Announce game over
		cout << "\n\nGame Over.\n\n";

		manager.save_game(*game);

		//Draw the board
		cout << *game;

		//clear the game
		game->clear_board();

		cout << "\n\n1 - Continue\n2 - Exit\n\nPlease enter your selection: ";
		cin >> continue_exit_selection;
		if (continue_exit_selection == 2) {
			continue_game = false;
		} else {
			//start a new game
			cout << "\nStarting new game.\nWho is playing first (X or O)?  ";
			cin >> starting_player;
			game->start_game(starting_player);
		}
	}

	cout << manager;

	return 0;
}
