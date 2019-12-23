#pragma once
#include "Piece.h"
class Piece;
class Board;

class Bishop : public Piece
{
public:
	Bishop(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter);
};