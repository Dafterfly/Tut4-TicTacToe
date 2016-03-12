#pragma once
#include<string>

using namespace std;

class TicTacToe
{

private:
	char gameBoard[3][3];  //Attribute to hold the gridbox values

public:
	TicTacToe(); //Default Constructor Declaration
	~TicTacToe();// Default Destructor Declaration
	void restart();
	bool move(int, int); //Move checking function prototype
	void print();
	int isWon();  //Return the player which one using an integer
	void over();
};
