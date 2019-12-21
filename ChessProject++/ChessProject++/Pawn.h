#pragma once
#include "Piece.h"
class Piece;
class Board;

class Pawn : public Piece
{
	Pawn(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter);
};