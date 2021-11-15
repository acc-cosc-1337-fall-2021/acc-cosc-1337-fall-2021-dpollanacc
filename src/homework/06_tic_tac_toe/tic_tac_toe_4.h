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

#ifndef TIC_TAC_TOE4
#define TIC_TAC_TOE4

class TicTacToe4 : public TicTacToe 
{
public:
    TicTacToe4(): TicTacToe(4){}
    friend ostream& operator<<(ostream& out, const TicTacToe4& game);
	friend istream& operator>>(istream& in, TicTacToe4& game);

private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
};

#endif