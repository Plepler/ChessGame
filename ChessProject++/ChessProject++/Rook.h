#pragma once
#include "Piece.h"
class Rook : public Piece
{

protected:
	virtual bool isValidMove();//Helper function

public:
	Rook(char number, char letter, char sign);
	virtual void move(char newNum, char newLetter);


};