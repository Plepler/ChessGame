#include "Bishop.h"
#include "Board.h"
#include "Piece.h"

Bishop::Bishop(char number, char letter, char sign) : Piece(number, letter, sign) {}


bool Bishop::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	char i = ' ', k = ' ';
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
	
	if (dstLetter - srcLetter == dstNum - srcNum)//if moves diagonal line
	{
		for (i = srcNum + 1, k = srcLetter + 1; k < dstLetter && i < dstNum && flag; i++ && k++)
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
	
	return(flag);
}