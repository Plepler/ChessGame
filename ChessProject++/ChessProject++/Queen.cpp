#include "Queen.h"
#include "Piece.h"
#include "Board.h"


Queen::Queen(char number, char letter, char sign) : Piece(number, letter, sign)
{

}

bool Queen::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	char k = ' ';
	char i = ' ';
	bool flag = true;
	char temp = ' ';
	if (dstNum < srcNum)//Make dst num always bigger
	{
		//Switch
		temp = dstNum;
		dstNum = srcNum;
		srcNum = temp;
	}
	if (dstLetter < srcLetter)//Make dst letter always bigger
	{
		//swap
		temp = dstLetter;
		dstLetter = srcLetter;
		srcLetter = temp;
	}

	if (dstLetter > srcLetter && dstNum == srcNum)//Moves horizontally
	{
		for (i = srcLetter + 1; i < dstLetter && flag; i++)
		{
			if (EMPTY != board(i, srcNum))
			{
				flag = false;
			}
		}
	}
	else if (dstLetter == srcLetter&& dstNum > srcNum)//moves Verticlly
	{
		for (i = srcNum + 1; i < dstNum && flag; i++)
		{
			if (EMPTY != board(srcLetter, i))
			{
				flag = false;
			}
		}
	}
	else if(dstLetter - srcLetter == dstNum - srcNum)//if moves diagonal line
	{
		for (i = srcNum + 1, k = srcLetter + 1; k <dstLetter &&  i < dstNum && flag; k++, i++)
		{
			if (EMPTY != board(k, i))
			{
				flag = false;
			}
		}
	}
	else
	{
		flag = false;
	}

	return flag;
}