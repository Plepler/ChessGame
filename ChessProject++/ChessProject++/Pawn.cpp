#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

Pawn::Pawn(char number, char letter, char sign) : Piece(number, letter, sign) {}

bool Pawn::isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	bool flag = true;
	char pawnSign = board.getPiece(srcLetter, srcNum)->getSign();
	
	//If white
	if (!isupper(this->_sign))
	{
		if (srcNum == '2')//if on second line
		{
			if (!(dstLetter == srcLetter && dstNum == srcNum + 2 || dstNum == srcNum + 1))
			{
				flag = false;
			}
		}
		else
		{
			if (!(dstNum == srcNum + 1))
			{
				flag = false;
			}
			else if ((dstLetter == srcLetter + 1) && board(dstLetter, dstNum) == EMPTY)
			{
				flag = false;
			}
			else if ((dstLetter == dstLetter - 1) && board(dstLetter, dstNum) == EMPTY)
			{
				flag = false;
			}
			else if (dstLetter != dstLetter)
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
			if (!(dstNum == dstNum - 1))
			{
				flag = false;
			}
			else if ((dstLetter == srcLetter + 1) && (board(dstLetter, dstNum)) == EMPTY)
			{
				flag = false;
			}
			else if (dstLetter == dstLetter - 1 && (board(dstLetter, dstNum)) == EMPTY)
			{
				flag = false;
			}
			else if (dstLetter != dstLetter)
			{
				flag = false;
			}
		}
	}
	
	return flag;
}