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
#define CODE_2 "Invalid move, Didnt select valid square to move from"
#define CODE_3 "Invalid move, we are not cannibals, you can't eat yourself"
#define CODE_4 "You will only hurt yourself, (1-800-273-8255 for help)"
#define CODE_5	"Out of bounds"
#define CODE_6	"Illegal move, RTFM"
#define CODE_7	"Same destination and source tiles"
#define CODE_8	"Good job, you won!"

class King;
class Queen;
class Rook;
class Knight;
class Bishop;
class Piece;
class Pawn;



class Board
{

public:
	Board(char startingPlayer);
	~Board();
	Piece* getPiece(char letter, char number);
	void printBoard();
	char& operator()(const char letter, const char number);
	int isValidMove(char srcNum, char srcLetter, char dstNum, char dstLetter);
	int move(char srcNum, char srcLetter, char dstNum, char dstLetter);
	
	Piece* findPiece(char sign);

private:
	Piece* _pieces[NUM_OF_PIECES];
	char * _board;

	void createPieces();
	void getRidOf(Piece * p);
	bool checkIfCheck(Piece * king);
	bool rookCheck(Piece* king);//also queen since she is an hybrid of rook and bishop
	bool bishopCheck(Piece* king);//also queen since she is an hybrid of rook and bishop
	bool pawnCheck(Piece* king);
	bool knightCheck(Piece* king);

};
