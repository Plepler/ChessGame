#pragma once
#include <iostream>
#include <vector>
#include "Piece.h"

#define SIZE 66
using namespace std;



class Board
{


public:
	Board(char startingPlayer);


protected:
	vector<Piece> _pieces;
	char _board[SIZE];
	char _currPlayer;

};