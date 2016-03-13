#pragma once
/*
	Eustacia Rajman
	214514354
	ENEL3CC - Computer Methods 3
	Tut4-TicTacToe
*/

#include<string>

using namespace std;

class TicTacToe
{
	
	private:
	char gameBoard[3][3];  //Creates a gameboard
	
	public:
	TicTacToe(); 
	~TicTacToe();
	void reset();
	void makeMove(int, int, int);
	bool move(int, int); 
	void print();
	string over();
};

