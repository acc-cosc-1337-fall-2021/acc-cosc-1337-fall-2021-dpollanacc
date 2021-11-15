//h
#include<iostream>
#include<string>
#include<vector>
#include"tic_tac_toe.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

#ifndef TIC_TAC_TOE3
#define TIC_TAC_TOE3

class TicTacToe3 : public TicTacToe 
{
public:
    TicTacToe3(): TicTacToe(3){}
    friend ostream& operator<<(ostream& out, const TicTacToe3& game);
	friend istream& operator>>(istream& in, TicTacToe3& game);

private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();
    string player;
    string winner;
};



#endif