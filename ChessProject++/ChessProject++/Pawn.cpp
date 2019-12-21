#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

Pawn::Pawn(char number, char letter, char sign) : Piece(number, letter, sign) {}

bool Pawn::isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	bool flag = true;
	
	//need to change signs!!
	if (isupper(this->_sign))
	{
		if (srcNum == '2')
		{
			if (!(dstLetter == srcLetter && dstNum == srcNum + 2 || dstNum == srcNum + 1))
			{
				flag = false;
			}
		}
		else
		{
			if (!((dstLetter == srcLetter + 1 || dstLetter == srcLetter - 1) && dstNum == srcNum + 1 && !isupper(board(dstLetter, dstNum))))
			{
				flag = false;
			}
			else if (!(dstLetter == srcLetter && dstNum == srcNum + 1))
			{
				flag = false;
			}
		}
	}
	else
	{
		if (srcNum == '7')
		{
			if (!(dstLetter == srcLetter && dstNum == srcNum - 2 || dstNum == srcNum - 1))
			{
				flag = false;
			}
		}
		else
		{
			if (!((dstLetter == srcLetter - 1 || dstLetter == srcLetter + 1) && dstNum == srcNum - 1 && isupper(board(dstLetter, dstNum))))
			{
				flag = false;
			}
			else if (!(dstLetter == srcLetter && dstNum == srcNum - 1))
			{
				flag = false;
			}
		}
	}
	
	return flag;
}