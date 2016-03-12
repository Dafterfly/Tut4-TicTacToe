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

void TicTacToe::reset()
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

void TicTacToe::print(){
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			cout <<" "<< gameBoard[i][j];
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
}

string comparePlayers(int countPlay1, int countPlay2)
{
	if (countPlay1 == 3){
		return "Player 1 wins";
	}
	if (countPlay2 == 3){
		return "Player 2 wins";
	}
	else
		return "";
}

string TicTacToe::over()
{
	int countPlay1 = 0, countPlay2 = 0, stillPlaying = 0; 

	//check rows
	for (int i = 0; i < 3; i++)
	{
		countPlay1 = 0;
		countPlay2 = 0;  

		for (int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == 'X'){ countPlay1++; }
			if (gameBoard[i][j] == 'O'){ countPlay2++; }
			if (gameBoard[i][j] == '-'){ stillPlaying = 1; }
		}
		return comparePlayers(countPlay1, countPlay2);
	}

	//Check columns
	for (int j = 0; j < 3; j++)
	{
		countPlay1 = 0;
		countPlay2 = 0;  //Reset control signals

		for (int i = 0; i < 3; i++)
		{
			if (gameBoard[i][j] == 'X'){ countPlay1++; }
			if (gameBoard[i][j] == 'O'){ countPlay2++; }
			if (gameBoard[i][j] == '-'){ stillPlaying = 1; }
		}
		return comparePlayers(countPlay1, countPlay2);
	}

	//Check diagonal from top left to bottom right
	countPlay1 = 0;
	countPlay2 = 0;  

	for (int i = 0; i < 3; i++)
	{
		if (gameBoard[i][i] == 'X'){ countPlay1++; }
		if (gameBoard[i][i] == 'O'){ countPlay2++; }
		if (gameBoard[i][i] == '-'){ stillPlaying = 1; }

		return comparePlayers(countPlay1, countPlay2);

	}

	//Check diagonal from top right to bottom left
	countPlay1 = 0;
	countPlay2 = 0;
	for (int i = 2; i >=0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (gameBoard[i][j] == 'X'){ countPlay1++; }
			if (gameBoard[i][j] == '0'){ countPlay2++; }
			if (gameBoard[i][j] == '-'){ stillPlaying = 1; }
		}
		return comparePlayers(countPlay1, countPlay2);
	
	}

	// Check for draw
	if ((countPlay1 == 3) && (countPlay2 == 3))
	{
		return "Draw";
	}

	// Check if game is still in progree
	else if (stillPlaying == 1)
	{
		return "Game is still in progress";
	}
	else
		reset();
}

int main()
{
	int player; 
	int x = 0, y = 0;

	TicTacToe game = TicTacToe(); // Created game object of class TicTacToe

	cout << "Welcome to TicTacToe console game" << endl;
	cout << "To play, please enter your move in the following format: " << endl;
	cout << " row number(0 to 2) column number(0 to 2) player number(1 or 2) " << endl;
	cout << "Player one uses X's and Player 2 uses 0's" << endl;

	cout << "Grid Layout: " << endl;
	cout << "00 01 02" << endl;
	cout << "10 11 12" << endl;
	cout << "20 21 22" << endl;

	//Game loop 

	for (int i = 0; i < 9; i++)
	{
		
		// alternates players
		if (i % 2 == 0)
		{
			player = 1;
		}
		else
		{
			player = 2;
		}

		cout <<"Player "<<player<< ", enter your move  " << endl;

		cin >> x >> y;

		if (game.move(x, y))
		{
			game.makeMove(player, x, y);
			game.print();
			cout<<game.over()<<endl;

			// restarts game if there's a winner
			if (((game.over()).compare("Player 1") == 0) || ((game.over()).compare("Player 2") == 0))
			{
				cout << "End game Restart" << endl;
				game.reset();
				i = 0;
				game.print();
			}
		}

		else
		{
			cout << "Invalid Input. Please try again " << endl;
			i--; //This move didn't count so revert the counter back to previous value
		}
	}
	cout << "End game" << endl;
	return 0;
}