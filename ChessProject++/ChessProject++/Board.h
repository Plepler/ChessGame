#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



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
#define CODE_4 "You will only hurt yourself, (1-800-273-8255 - for help)"
#define CODE_5	""
#define CODE_6	""
#define CODE_7	""
#define CODE_8	""

class King;
class Queen;
class Rook;
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
	void createPieces();

private:
	Piece* _pieces[NUM_OF_PIECES];
	char * _board;
	void getRidOf(Piece * p);
	bool checkIfCheck(Piece * king);

};
