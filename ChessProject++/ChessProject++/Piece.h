#pragma once
#include <iostream>
class Board;
class Rook;
class Queen;
class King;

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
	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter) = 0;
	char getSign();
};
