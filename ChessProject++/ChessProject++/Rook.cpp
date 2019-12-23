#include "Rook.h"
#include "Piece.h"
#include "Board.h"




//C'Tor
Rook::Rook(char number, char letter, char sign) : Piece(number, letter, sign)
{

}
bool Rook::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	char i = 0;
	bool flag = true;
	if (srcNum != dstNum && srcLetter != dstLetter)//Make sure he moved in a straight line
	{
		flag = false;
	}
	else if (srcNum != dstNum)//The rook moved
	{
		if (dstNum < srcNum)//Make dst num always bigger
		{
			//Switch
			dstNum = srcNum + dstNum;
			srcNum = dstLetter - srcNum;
			dstNum = dstNum - srcNum;
		}

		for (i = srcNum + 1; i < dstNum && flag; i++)
		{
			if (board(srcLetter, i) != EMPTY)
			{
				flag = false;
			}
		}
	}
	else
	{
		if (dstLetter < srcLetter)//Make dst letter always bigger
		{
			//swap
			dstLetter = srcLetter + dstLetter;
			srcLetter = dstLetter - srcLetter;
			dstLetter = dstLetter - srcLetter;
		}

		for (i = srcLetter + 1; i < dstLetter && flag; i++)
		{
			if (board(srcLetter, dstLetter) != EMPTY)
			{
				flag = false;
			}
		}
	}
	return flag;
}




