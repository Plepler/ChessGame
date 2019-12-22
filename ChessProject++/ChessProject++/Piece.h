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

	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter) = 0;
	//the function checks if the rook is moving correctly without friendly fire or passing over pieces
	//In: the board, the src index and the dest index of the piece
	//Out: based on the piece, true or false based on the move, if its valid
};
