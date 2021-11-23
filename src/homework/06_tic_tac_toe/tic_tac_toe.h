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
	TicTacToe(std::vector<std::string> p, std::string win) : pegs(p), winner(win){}
	std::vector<std::string> get_pegs()const{return pegs;}
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player()const;
	std::string get_winner();
	void set_next_player();
	void set_winner();
	bool check_board_full();
	std::string get_pegs();
	void clear_board();
	friend ostream& operator<<(ostream& out, const TicTacToe& game);
	friend istream& operator>>(istream& in, TicTacToe& game);

protected: 
	std::vector<std::string> pegs;
	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win();


	
private:
	std::string player;
	std::string winner;
};

#endif
