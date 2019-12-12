#pragma once
#include <iostream>

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



class Piece
{
protected:
	char _number;
	char _letter;
	char _sign;

	//Methods
	virtual bool isValidMove() = 0;//Helper function


public:
	Piece(char number, char letter, char sign); //C'Tor
	bool isBlack();
	virtual void move(char newNum, char newLetter) = 0;



};