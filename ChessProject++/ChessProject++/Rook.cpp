#include "Rook.h"

enum MOVE_CODES
{
	VAL	= 0,
	CHECK,
	MISS,
	OCCUPIED,
	SUICIDE,
	OUT,
	INVALID,
	SAME,
	CHECKMATE
};

Rook::Rook(char number, char letter, char sign) : Piece(number, letter, sign)
{

}



void Rook::move(Board board, char newNum, char newLetter)
{
	if (isValidMove(board, newNum, newLetter))
	{

	}
}

int Rook::isValidMove(Board board, char newNum, char newLetter)
{
	int i = 0;
	int flag = 0;
	if ()
	{

	}
	else if ((newLetter > _letter || newLetter < _letter) && (newNum < _number || newNum > _number))
	{
		flag = INVALID;
	}
	else if(_number > EIGHT || _number < 0 || newLetter > 'h' || newLetter < 'a')//If in valid range
	{
		flag = OUT;
	}
	else
	{
		
	}
	return flag;
}


