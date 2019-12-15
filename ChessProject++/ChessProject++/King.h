#pragma once
#include "Piece.h"

class Piece;
class Board;

class King : public Piece
{
public:
	King(char number, char letter, char sign);
	virtual bool isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter);


private:
	bool _isOnCheck;

}