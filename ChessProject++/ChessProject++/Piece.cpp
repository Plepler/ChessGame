#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"

// C'Tor
Piece::Piece(char number, char letter, char sign)
{
	this->_letter = letter;
	this->_number = number;
	this->_sign = sign;
}

char Piece::getLetter()
{
	return _letter;
}
char Piece::getNumber()
{
	return _number;
}



/*
This function checks if a piece is black or white
Out: true if white, false if black
*/
bool Piece::isBlack()
{
	return (isupper(_sign));
}

char Piece::getSign()
{
	return _sign;
}

