//h
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
class TicTacToe {
public:
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player()const;
	std::string get_winner();
	void display_board()const;
	void set_next_player();
	bool check_board_full();
	void clear_board();

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
