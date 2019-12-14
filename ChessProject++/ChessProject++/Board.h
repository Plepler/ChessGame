#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include <string>

#define TWO 2
#define SIZE 66
#define CURR_PLAYER 64
#define NUM_OF_PIECES 32
#define SEVEN 7
#define EMPTY '#'

#define CODE_0 "Valid move"
#define CODE_1 "Valid move, opponent is now in check"
#define CODE_2 "Invalid move, Didnt select piece to move"
#define CODE_3 "Invalid move, we are not cannibals, you can't eat yourself"
#define CODE_4 "You will only hurt yourself, ()"
#define CODE_5	""
#define CODE_6	""
#define CODE_7	""
#define CODE_8	""



using namespace std;

class Piece;

class Board
{


public:
	Board(char startingPlayer);
	Piece* getPiece(char letter, char number);
	void printBoard();
	char& operator()(const char letter, const char number);
	int isValidMove(char srcNum, char srcLetter, char dstNum, char dstLetter);
	void move(char srcNum, char srcLetter, char dstNum, char dstLetter);

protected:
	std::vector<Piece*> _pieces;
	char * _board;

	
	char searchForPieces();
	void createPieces();
};