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

void TicTacToe::restart()
{
	TicTacToe();
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

void TicTacToe::makeMove(int player, int row, int col)
{
	if (move(row, col))// checks if it's a valid move
	{
		if (player == 1)
		{
			gameBoard[row][col] = 'X'; 
		}

		else if (player == 2) 
		{ 
			gameBoard[row][col] = 'O'; 
		} 
	}
}

bool TicTacToe::move(int row, int col)
{
	bool checkMove = 0;  
	if (((row < 3) && (col < 3)) && (gameBoard[row][col] == '-'))
	{
		checkMove = 1;
	}
	return checkMove;
};
