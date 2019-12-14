#pragma once
#include "Piece.h"
#define EIGHT 8

class Rook : public Piece
{

public:
	Rook(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter);
};