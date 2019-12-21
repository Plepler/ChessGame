#include "Knight.h"
#define WIDTH 2
#define LENGTH 2

Knight::Knight(char number, char letter, char sign): Piece(number, letter, sign) {}

bool Knight::isValidPieceMove(Board board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	bool flag = true;
	if (dstLetter == srcLetter + WIDTH && dstNum == srcNum + 1 || dstLetter == srcLetter - WIDTH && dstNum == srcNum + 1 ||
		dstLetter == srcLetter + WIDTH && dstNum == srcNum - 1 || dstLetter == srcLetter - WIDTH && dstNum == srcNum - 1 ||
		dstLetter == srcLetter + 1 && dstNum == srcNum + LENGTH || dstLetter == srcLetter - 1 && dstNum == srcNum + LENGTH ||
		dstLetter == srcLetter - 1 && dstNum == srcNum - LENGTH || dstLetter == srcLetter + 1 && dstNum == srcNum - LENGTH)
	{
		if (board(dstLetter, dstNum) != '#')
		{
			flag = false;
		}
	}
	return(flag);
}

