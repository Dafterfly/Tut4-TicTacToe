#include "TicTacToe.h"
#include <string>
#include <iostream>


TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = '-';
		}
	}
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::TicTacToe::print(){
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			cout << "|" << gameBoard[i][j] << "  " << "|";
		}
		cout << endl;
	}
}
