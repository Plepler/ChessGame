#pragma once
#include "Piece.h"
class Piece;
class Board;

class Knight : public Piece
{
public:
	Knight(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter);
};