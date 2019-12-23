#pragma once
#include <iostream>
class Board;
class Rook;
class Queen;
class King;
class Knight;
class Bishop;
class Pawn;

enum MOVE_CODES
{
	VAL = 0,
	CHECK,
	MISS,
	OCCUPIED,
	SUICIDE,
	OUT,
	INVALID,
	SAME,
	CHECKMATE
};




class Piece
{
protected:
	char _number;
	char _letter;
	char _sign;


public:
	Piece(char number, char letter, char sign); //C'Tor
	char getLetter();
	char getNumber();
	bool isBlack();
	void setPos(char let, char num);
	char getSign();	

	virtual bool isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter) = 0;
	//This function check if the piece moved correctly with skipping over other pieces (except knight)
	//In: the board, the src index and the dest index of the piece
	//Out: true if the move is valid, false otherwise
};
