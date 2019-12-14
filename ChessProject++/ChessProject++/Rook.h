#pragma once
#include "Piece.h"
#define EIGHT 8

class Rook : public Piece
{

private:
	virtual int isValidMove(Board board, char newNum, char newLetter);//Helper function


public:
	Rook(char number, char letter, char sign);
	virtual void move(Board board, char newNum, char newLetter);

};