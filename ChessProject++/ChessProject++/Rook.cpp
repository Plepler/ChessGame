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
	char temp = ' ';

	if (srcNum != dstNum && srcLetter != dstLetter)//Make sure he moved in a straight line
	{
		flag = false;
	}
	else if (srcNum != dstNum)//The rook moved vertically
	{
		if (dstNum < srcNum)//Make dst num always bigger
		{
			//Switch
			temp = dstNum;
			dstNum = srcNum;
			srcNum = temp;
		}

		for (i = srcNum + 1; i < dstNum && flag; i++)
		{
			if (board(srcLetter, i) != EMPTY)
			{
				flag = false;
			}
		}
	}
	else//the rook moved verically
	{
		if (dstLetter < srcLetter)//Make dst letter always bigger
		{
			//swap
			temp = dstLetter;
			dstLetter = srcLetter;
			srcLetter = temp;
		}

		for (i = srcLetter + 1; i < dstLetter && flag; i++)
		{
			if (board(i, srcNum) != EMPTY)
			{
				flag = false;
			}
		}
	}
	return flag;
}




