#include "Pawn.h"
#include "Piece.h"
#include "Board.h"

//c'tor
Pawn::Pawn(char number, char letter, char sign) : Piece(number, letter, sign) {}

bool Pawn::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{

	bool flag = false;
	
	// Check if moved at all
	if (dstNum != srcNum)
	{
		//If white
		if (isupper(this->_sign))
		{
			//if its the white pawns, in their first line
			if (srcNum == '2')
			{
				//Check every legal move
				if (dstLetter == srcLetter && (dstNum == srcNum + TWO || dstNum == srcNum + 1))
				{
					flag = true;
				}
				if (dstNum == srcNum + 1 && ((dstLetter == srcLetter + 1) && board(dstLetter, dstNum) != EMPTY))
				{
					flag = true;
				}
				if (dstNum == srcNum + 1 && ((dstLetter == srcLetter - 1) && board(dstLetter, dstNum) != EMPTY))
				{
					flag = true;
				}

			}
			else // Not from their line
			{
				//Check every legal move
				if (dstLetter == srcLetter && dstNum == srcNum + 1 && board(dstLetter, dstNum) == EMPTY )
				{
					flag = true;
				}
				if (dstNum == srcNum + 1 && ((dstLetter == srcLetter + 1) && board(dstLetter, dstNum) != EMPTY))//illegal move
				{
					flag = true;
				}
				if (dstNum == srcNum + 1 && ((dstLetter == dstLetter - 1) && board(dstLetter, dstNum) != EMPTY))//illegal move
				{
					flag = true;
				}
			}
		}
		else
		{
			//if its the black pawns, in thier first line
			if (srcNum == '7')
			{
				//Check every legal move
				if (dstLetter == srcLetter && (dstNum == srcNum - TWO || dstNum == srcNum - 1))
				{
					flag = true;
				}
				if (dstNum == srcNum - 1 && ((dstLetter == srcLetter + 1) && (board(dstLetter, dstNum)) != EMPTY))
				{
					flag = true;
				}
				if (dstNum == srcNum - 1 && ((dstLetter == srcLetter - 1) && (board(dstLetter, dstNum)) != EMPTY))
				{
					flag = true;
				}
			}
			else//Check every legal move
			{
				if (srcLetter == dstLetter && dstNum == srcNum - 1 && board(dstLetter, dstNum) == EMPTY)
				{
					flag = true;
				}
				if (dstNum == srcNum - 1 && ((dstLetter == srcLetter + 1) && (board(dstLetter, dstNum)) != EMPTY))
				{
					flag = true;
				}
				if (dstNum == srcNum - 1 && ((dstLetter == srcLetter - 1) && (board(dstLetter, dstNum)) != EMPTY))
				{
					flag = true;
				}
			}
		}
	}
	else//didnt move forward
	{
		flag = false;
	}
	
	
	return flag;
}