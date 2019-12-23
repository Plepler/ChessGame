#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

//c'tor
Pawn::Pawn(char number, char letter, char sign) : Piece(number, letter, sign) {}

bool Pawn::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{

	bool flag = true;
	
	//If white
	if (isupper(this->_sign))
	{
		//if its the white pawns, in thier first line
		if (srcNum == '2')
		{
			if (!(dstLetter == srcLetter && dstNum == srcNum + 2 || dstNum == srcNum + 1))
			{
				flag = false;
			}
		}

		else
		{
			//check every illigel move
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
		//if its the black pawns, in thier first line
		if (srcNum == '7')
		{
			if (!(dstLetter == srcLetter && dstNum == srcNum - 2 || dstNum == srcNum - 1))
			{
				flag = false;
			}
		}
		else
		{
			//check every illigel move
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