//h
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
class TicTacToe {
public:
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player()const;
	std::string get_winner();
	void set_next_player();
	bool check_board_full();
	void clear_board();

	friend ostream& operator<<(ostream& out, const TicTacToe& game);
	friend istream& operator>>(istream& in, TicTacToe& game);
	

private:
	string player;
	vector<string> pegs{ " ", " ", " ", " ", " ", " ", " ", " ", " " };
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void set_winner();
	std::string winner;
};

#endif
