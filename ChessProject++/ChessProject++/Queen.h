#pragma once
#include "Piece.h"

class Board;
class Piece;

class Queen : public Piece
{
public:
	Queen(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter);
};