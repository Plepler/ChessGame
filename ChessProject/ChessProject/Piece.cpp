#include "Piece.h"



// C'Tor
Piece::Piece(char number, char letter, char sign)
{
	this->_letter = letter;
	this->_number = number;
	this->_sign = sign;
}


/*
This function checks if a piece is black or white
Out: true if white, false if black
*/
bool Piece::isBlack()
{
	return (isupper(_sign));
}