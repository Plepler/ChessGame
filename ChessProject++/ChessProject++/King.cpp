#include <cmath>
#include "King.h"
#include "Board.h"
#include "Piece.h"

#define SQURED 2
#define DIFF 48

King::King(char number, char letter, char sign) : Piece(number, letter, sign)
{
	_isOnCheck = false;
}

bool King::isValidPieceMove(Board& board, char srcNum, char srcLetter, char dstNum, char dstLetter)
{
	int LetterDistace = int(pow(int(dstLetter - DIFF) - int(srcLetter - DIFF), SQURED)); // get the absolote value of the distance between src and dest letters
	int numDistance = int(pow(int(dstNum) - int(srcNum), SQURED));// get the absolote value of the distance between src and dest numbers
	bool flag = true;
	if(!((numDistance == 1 && LetterDistace == 1) || (numDistance == 0 && LetterDistace == 1) || (numDistance == 1 && LetterDistace == 0)))
	{
		flag = false;
	}
	return flag;
}
