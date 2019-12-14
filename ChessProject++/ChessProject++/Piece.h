
#pragma once
#include <iostream>
#include "Board.h"
enum PIECES
{
	W_KING = 'k',
	W_QUEEN = 'Q',
	W_ROOK = 'R',
	W_KIGHT = 'N',
	W_BISHOP = 'B',
	W_PAWN = 'P',

	B_KING = 'k',
	B_QUEEN = 'q',
	B_ROOK = 'r',
	B_KIGHT = 'n',
	B_BISHOP = 'b',
	B_PAWN = 'p'
};
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


class Board;

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
	virtual bool isValidPieceMove(Board board,char srcNum, char srcLetter, char dstNum, char dstLetter) = 0;
	virtual char getSign();
};
