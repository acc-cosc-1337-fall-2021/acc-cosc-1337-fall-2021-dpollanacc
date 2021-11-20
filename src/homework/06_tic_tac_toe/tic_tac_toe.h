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
	TicTacToe(int size) :pegs(size * size, " ") {}
	TicTacToe(vector<string> p, string win) {
		pegs = p; winner = win;
	}
	vector<string> get_pegs()const;
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player()const;
	std::string get_winner();
	void set_next_player();
	void set_winner();
	bool check_board_full();
	void clear_board();
	friend ostream& operator<<(ostream& out, const TicTacToe& game);
	friend istream& operator>>(istream& in, TicTacToe& game);

protected: 
	vector<string> pegs;

	//cheat function
	virtual string get_pegs();

	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win();


	
private:
	string player;
	std::string winner;
};

#endif
